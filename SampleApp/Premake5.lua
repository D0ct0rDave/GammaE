-- Premake5.lua

workspace "GammaE_Application"
    configurations { "Debug", "Release" }
    location "build" -- Where generated files (like Visual Studio solutions) will be stored
    architecture "x86_64"
	
project "GammaE_Application"
    kind "WindowedApp" -- Change to "SharedLib" for a shared library
    language "C++"
    cppdialect "C++17"
    targetdir "$(ProjectDir)/exe/%{cfg.buildcfg}" -- Output directory for binaries
    objdir "$(ProjectDir)/obj/%{cfg.buildcfg}" -- Output directory for intermediate files
	characterset("ASCII")

	-- Specify the root directory of the library
    local sourceRoot = os.getcwd()
    frameworkRoot = sourceRoot .. "/../GammaE"
	print("Framework dir: " .. frameworkRoot)
  	
	-- Recursively include all .cpp and .h files from the sourceRoot directory
    files {
        sourceRoot .. "/**.cpp",
        sourceRoot .. "/**.h",
		sourceRoot .. "/**.txt",
    }

	-- specific defines for this project
	defines {
		"_NULL=0",
		"_MBCS" ,
		"_OGL_",
		"_DSOUND_"
	}
	
	filter { "system:windows" }
		defines { "WIN32" }
	filter {} -- Reset filter

    -- Add include directories (sourceRoot is included by default)
    includedirs {
		sourceRoot,
		"$(ProjectDir)../../GammaE",
		"$(ProjectDir)../../sdks/TexLib/src",
		"$(ProjectDir)../../sdks/TerrainGenerationLib/Src",
		"$(ProjectDir)../../sdks/FileLib/src",
    }

    -- Group files based on their folder structure
    filter "files:**.cpp"
        vpaths {
            ["Source Files"] = "**.cpp" -- Places all .cpp files under "Source Files" in the project
        }
    filter "files:**.h"
        vpaths {
            ["Header Files"] = "**.h" -- Places all .h files under "Header Files" -- in the project
        }
    filter {} -- Clear filter to reset for subsequent rules

	-- Library directories common for all configurations
	libdirs
	{
	}
	
	links 
	{
		"tex.lib",
		"TerrainGenerationLib.lib",		
		"opengl32.lib",
		"glu32.lib",
		"libsndfile.lib",
	}

    -- Configuration-specific settings
    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On" -- Generate debug symbols
		libdirs
		{
			"$(ProjectDir)../../sdks/TexLib/build/lib/Debug",
			"$(ProjectDir)../../sdks/TerrainGenerationLib/build/lib/Debug",
			"$(ProjectDir)../../sdks/libsndfile-0.0.26/Win32/LibSndFile/lib/Debug",
			"$(ProjectDir)../../GammaE/build/lib/Debug",
		}
    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On" -- Enable optimizations
		libdirs
		{
			"$(ProjectDir)../../sdks/TexLib/build/lib/Release",
			"$(ProjectDir)../../sdks/TerrainGenerationLib/build/lib/Release",
			"$(ProjectDir)../../sdks/libsndfile-0.0.26/Win32/LibSndFile/lib/Release",
			"$(ProjectDir)../../GammaE/build/lib/Release",			
		}
    filter {} -- Clear filter for general settings

    -- List of directories to exclude from recursion
    local excludeDirs = { 
        "build",
		"UML",
		"Tools"
    }

	-- Define the mapping of platforms to project file extensions
	local platformProjectExtensions = {
        windows = "vcxproj",
        linux = "makefile",
        macosx = "xcodeproj"
    }

	-- Determine the current platform's project file extension
    local currentPlatform = os.target():lower() -- e.g., "windows", "linux", "macosx"
    local projectExtension = platformProjectExtensions[currentPlatform]

    if not projectExtension then
        error("Unsupported platform: " .. currentPlatform)
    end

    
	local function includeLibraries(rootDir)
		local projectFileFound = false;
        local entries = os.matchdirs(rootDir .. "/*") -- Find all subdirectories
        for _, entry in ipairs(entries) do
			local projectFiles = os.matchfiles(entry .. "/*." .. projectExtension)				
			for _, projectFile in ipairs(projectFiles) do
				projectFileFound = true;
				local projectName = projectFile:match("([^/\\]+)%..+$") -- Extract project name

				print("Adding library: " .. projectFile)
				links { projectName .. ".lib" }
			end

			if projectFileFound then break end

			-- Recurse into subdirectories
			includeLibraries(entry)
        end
    end
	
	
	-- Step 2: Include external projects based on generated project files
	local libraries= {} -- Collect all library names
	local function includeProjects(rootDir)
		local projectFileFound = false;
        local entries = os.matchdirs(rootDir .. "/*") -- Find all subdirectories
        for _, entry in ipairs(entries) do
			local projectFiles = os.matchfiles(entry .. "/*." .. projectExtension)				
			for _, projectFile in ipairs(projectFiles) do
				projectFileFound = true;
				local projectName = projectFile:match("([^/\\]+)%..+$") -- Extract project name

				print("Adding external project: " .. projectFile)
				externalproject(projectName)
					location(entry)
					kind "StaticLib" -- Modify as needed
					language "C++"
			end
			
			if projectFileFound then break end

			-- Recurse into subdirectories
			includeProjects(entry)
        end
    end
	
	

	-- Add the external project to the solution
	includeLibraries(frameworkRoot)	
	includeProjects(frameworkRoot)

	-- local lolo = "lole.lib; e333d.lib; adfffe.lib;"
	-- links { lolo }
	

-- Install rules (using a post-build step for example purposes)
postbuildcommands {
    -- "{MKDIR} %{wks.location}/dist/lib", -- Create output directory
    -- "{COPYFILE} %{cfg.targetdir}/MyLibrary.lib %{wks.location}/dist/lib" -- Copy library to the dist directory
}
