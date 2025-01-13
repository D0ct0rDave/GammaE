-- Premake5.lua

workspace "GammaE_E3D"
    configurations { "Debug", "Release" }
    location "build" -- Where generated files (like Visual Studio solutions) will be stored
    architecture "x86_64"

project "E3D"
    kind "StaticLib" -- Change to "SharedLib" for a shared library
    language "C++"
    cppdialect "C++17"
    targetdir "$(ProjectDir)/lib/%{cfg.buildcfg}" -- Output directory for binaries
    objdir "$(ProjectDir)/obj/%{cfg.buildcfg}" -- Output directory for intermediate files
	characterset("ASCII")
	
    -- Specify the root directory of the library
    local sourceRoot = os.getcwd()

	-- specific defines for this project
	defines {
		"_NULL=0",
		"_MBCS" 
	}
 
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
		"$(ProjectDir)../../../sdks/OpenGL;",
		"$(ProjectDir)../../../sdks/FileLib/src;",
		"$(ProjectDir)../../../sdks/TexLib;",
		"$(ProjectDir)../..;$(ProjectDir).."
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

-- Install rules (using a post-build step for example purposes)
postbuildcommands {
    -- "{MKDIR} %{wks.location}/dist/lib", -- Create output directory
    -- "{COPYFILE} %{cfg.targetdir}/MyLibrary.lib %{wks.location}/dist/lib" -- Copy library to the dist directory
}
