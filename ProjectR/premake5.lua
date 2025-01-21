-- Premake5.lua

workspace "ProjectR"
    configurations { "Debug", "Release" }
    location "build" -- Where generated files (like Visual Studio solutions) will be stored
    architecture "x86_64"
	
project "ProjectR"
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
        sourceRoot .. "/**.lua",
    }

	-- Exclude	files
	filter { "files:**.lua", "files:**.txt" }
	  flags {"ExcludeFromBuild"}
	filter {} -- Reset filter

    -- specific defines for this project
	defines 
	{
		"NULL=0",
		"_MBCS",
		"_OGL_",
		"_OPENAL_"
	}
	
    filter { "system:windows" }
		defines { "WIN32" }
	filter {} -- Reset filter

	includedirs {
        -- Add include directories (sourceRoot is included by default)
		sourceRoot,
		"$(ProjectDir)../../GammaE/inc",
		"$(ProjectDir)../src/Project",
		"$(ProjectDir)../src/Modules",	
		"$(ProjectDir)../../sdks/FreeImage/Dist",
    }

	-- Library directories common for all configurations
	libdirs
	{
		"$(ProjectDir)../../sdks/FreeImage/Dist",
		"$(ProjectDir)../../sdks/lua",
		"$(ProjectDir)../../sdks/OpenAL 1.1 SDK/libs",
		"$(ProjectDir)../../sdks/OpenAL 1.1 SDK/libs/Win64",
	}

	links 
	{
		"opengl32.lib",
		"glu32.lib",
		"libsndfile.lib",
		"freeimage.lib",
		"libconfig.lib",
		"lua51.lib",
		"OpenAL32.lib",
		"alut.lib",
	}

	-- Configuration-specific settings
    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On" -- Generate debug symbols
		libdirs
		{
			"$(ProjectDir)../../GammaE/build/lib/Debug",
			"$(ProjectDir)../../sdks/libsndfile/lib/x64/Debug",
			"$(ProjectDir)../../sdks/libconfig/lib/x64/Debug",			
		}
    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On" -- Enable optimizations
		libdirs
		{			
			"$(ProjectDir)../../GammaE/build/lib/Release",
			"$(ProjectDir)../../sdks/libsndfile/lib/x64/Release",
			"$(ProjectDir)../../sdks/libconfig/lib/x64/Release",
		}
    filter {} -- Clear filter for general settings

	------------------------------------------------------------------------------
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
    ------------------------------------------------------------------------------
	local function includeLibraries(rootDir)
	    local entries = os.matchdirs(rootDir .. "/*") -- Find all subdirectories
        for _, entry in ipairs(entries) do
			local projectFiles = os.matchfiles(entry .. "/*." .. projectExtension)				
			for _, projectFile in ipairs(projectFiles) do
				local projectName = projectFile:match("([^/\\]+)%..+$") -- Extract project name

				print("Adding library: " .. projectFile)
				links { projectName .. ".lib" }
			end

			-- Recurse into subdirectories
			includeLibraries(entry)
        end
    end
	------------------------------------------------------------------------------
	-- Step 2: Include external projects based on generated project files
	local libraries= {} -- Collect all library names
	local function includeProjects(rootDir)
        local entries = os.matchdirs(rootDir .. "/*") -- Find all subdirectories
        for _, entry in ipairs(entries) do
			local projectFiles = os.matchfiles(entry .. "/*." .. projectExtension)
			for _, projectFile in ipairs(projectFiles) do
				local projectName = projectFile:match("([^/\\]+)%..+$") -- Extract project name
			

				print("Adding external project: " .. projectFile)
				externalproject(projectName)
					location(entry)
					kind "StaticLib" -- Modify as needed
					language "C++"

				dependson { projectName }
			end
			-- Recurse into subdirectories
			includeProjects(entry)
        end
    end

	------------------------------------------------------------------------------
	-- Add the external project to the solution
    includeLibraries(frameworkRoot)	
    -- includeProjects(frameworkRoot)


-- Install rules (using a post-build step for example purposes)
postbuildcommands {
    -- "{MKDIR} %{wks.location}/dist/lib", -- Create output directory
    -- "{COPYFILE} %{cfg.targetdir}/MyLibrary.lib %{wks.location}/dist/lib" -- Copy library to the dist directory
}