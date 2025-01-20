
if BUILD_LOCATION == "" then
	BUILD_LOCATION = "build"
end

-- Premake5.lua
	configurations { "Debug", "Release" }
    location(BUILD_LOCATION) -- Where generated files (like Visual Studio solutions) will be stored
    architecture "x86_64"

project(project_name)

    kind "StaticLib" -- Change to "SharedLib" for a shared library
    language "C++"
    cppdialect "C++17"
    targetdir "$(ProjectDir)/lib/%{cfg.buildcfg}" -- Output directory for binaries
    objdir "$(ProjectDir)/obj/%{cfg.buildcfg}" -- Output directory for intermediate files
	characterset("ASCII")

    -- Specify the root directory of the library
    sourceRoot = caller_script_directory

	-- Determine the current platform's project file extension
    currentPlatform = os.target():lower() -- e.g., "windows", "linux", "macosx"

	-- specific defines for this project
	defines {
		"_NULL=0",
		"_MBCS" 
	}

	filter { "system:windows" }
		defines { "WIN32" }
	filter {} -- Reset filter

    -- Recursively include all .cpp and .h files from the sourceRoot directory
    files {
        sourceRoot .. "/**.cpp",
        sourceRoot .. "/**.h",
		sourceRoot .. "/**.inl"
    }

    -- Exclude certain directories (e.g., build, CMakeFiles)
    removefiles {
        sourceRoot .. "/build/**",
        sourceRoot .. "/CMakeFiles/**"
    }

    -- Add include directories (sourceRoot is included by default)
    includedirs {
        sourceRoot,
		"$(ProjectDir)../..;",
		"$(ProjectDir).."
    }

    -- Group files based on their folder structure
    filter "files:**.cpp"
        vpaths {
            ["Source Files"] = "**.cpp" -- Places all .cpp files under "Source Files" in the project
        }
    filter "files:**.h"
        vpaths {
            ["Header Files"] = "**.h" -- Places all .h files under "Header Files" in the project
        }
    filter {} -- Clear filter to reset for subsequent rules

    -- Configuration-specific settings
    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On" -- Generate debug symbols

    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On" -- Enable optimizations

    filter {} -- Clear filter for general settings
