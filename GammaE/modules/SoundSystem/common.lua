-- Premake5.lua
project_name = "SoundSystem"
caller_script_directory = os.getcwd();

workspace("GammaE_" .. project_name)

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
		"NULL=0",
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
        sourceRoot .. "/CMakeFiles/**",
		sourceRoot .. "**/SndDrv_BASS/*", 
		sourceRoot .. "**/SndDrv_DirectSound/*", 
		sourceRoot .. "**/SndDrv_SDL/*",
    }

	-- Exclude	files
	filter { "files:**_BASS*" }
	  flags {"ExcludeFromBuild"}
	  
	filter { "files:**_SDL*" }
	  flags {"ExcludeFromBuild"}
	
	-- Exclude	files
	filter { "files:**DSound*" }
	  flags {"ExcludeFromBuild"}
	
	filter { "files:**_DS_*" }
	  flags {"ExcludeFromBuild"}

    -- Add include directories (sourceRoot is included by default)
    includedirs {
		"$(ProjectDir)../inc",
		"$(ProjectDir)../../../inc",
		"$(ProjectDir)../modules/" .. project_name .. "/src",
		"$(ProjectDir)../src/"
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
--[[
	removefiles
	{	
		sourceRoot .. "SndDrv_BASS/**.cpp", 
		sourceRoot .. "SndDrv_BASS/**.h", 
		sourceRoot .. "SndDrv_DirectSound/**.cpp", 
		sourceRoot .. "SndDrv_DirectSound/**.h", 
		sourceRoot .. "SndDrv_SDL/**.cpp", 
		sourceRoot .. "SndDrv_SDL/**.h", 
	}
]]
	includedirs {
			"$(ProjectDir)../../SDKS/FileLib/Src;",
			"$(ProjectDir)../../SDKS/libsndfile/src"		
		}

-- Install rules (using a post-build step for example purposes)
postbuildcommands {
    -- "{MKDIR} %{wks.location}/dist/lib", -- Create output directory
    -- "{COPYFILE} %{cfg.targetdir}/MyLibrary.lib %{wks.location}/dist/lib" -- Copy library to the dist directory
}
