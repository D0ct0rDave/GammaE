-- Premake5.lua
ProjectName = "ProjectS"

ProjectRelativeFinalDataRoot = "$(ProjectDir)../data/FinalData"
ProjectRelativeSDKSRoot = "$(ProjectDir)../../SDKS"
ProjectRelativeGammaERoot = "$(ProjectDir)../../GammaE"

workspace "ProjectS"
    configurations { "Debug", "Release" }
    location "build" -- Where generated files (like Visual Studio solutions) will be stored
    architecture "x86_64"

project(ProjectName)
    kind "WindowedApp" -- Change to "SharedLib" for a shared library
    language "C++"
    cppdialect "C++17"
    targetdir "$(ProjectDir)/exe/$(Platform)/%{cfg.buildcfg}" -- Output directory for binaries
    objdir "$(ProjectDir)/obj/$(Platform)/%{cfg.buildcfg}" -- Output directory for intermediate files
	characterset("ASCII")
    debugdir(ProjectRelativeFinalDataRoot)

	-- Recursively include all .cpp and .h files from the sourceRoot directory
	    local sourceRoot = os.getcwd()
    files 
	{
        sourceRoot .. "/src/**.cpp",
        sourceRoot .. "/src/**.h",
		sourceRoot .. "/src/**.txt",
        sourceRoot .. "/src/**.lua",
    }

	-- Exclude	files
	filter { "files:**.lua", "files:**.txt" }
	  flags {"ExcludeFromBuild"}
	filter {} -- Reset filter

    -- specific defines for this project
	defines 
	{
		"_MBCS",
		"_OGL_",
		"_OPENAL_",
		"FREEIMAGE_LIB",
	}
	
    filter { "system:windows" }
		defines { "WIN32" }
	filter {} -- Reset filter

	disablewarnings
	{
		"4091",
	}

	includedirs 
	{
        -- Add include directories (sourceRoot is included by default)
		sourceRoot,
		ProjectRelativeGammaERoot .. "/inc",
		"$(ProjectDir)../src/Project",
		"$(ProjectDir)../src/Modules",	
		ProjectRelativeSDKSRoot .. "/Externals/FreeImage/Dist;",
		ProjectRelativeSDKSRoot .. "/Externals/lua/include",
    }

	-- Library directories common for all configurations
	libdirs
	{
		ProjectRelativeSDKSRoot .. "/Externals/FreeImage/Dist/$(Platform)/%{cfg.buildcfg}",
		ProjectRelativeSDKSRoot .. "/OpenAL 1.1 SDK/libs",
		ProjectRelativeSDKSRoot .. "/OpenAL 1.1 SDK/libs/Win64",
		ProjectRelativeSDKSRoot .. "/Externals/lua/lib/$(Platform)/%{cfg.buildcfg}",	
		ProjectRelativeSDKSRoot .. "/libsndfile/lib/$(Platform)/%{cfg.buildcfg}",
		ProjectRelativeSDKSRoot .. "/libconfig/lib/$(Platform)/%{cfg.buildcfg}",
		ProjectRelativeGammaERoot .. "/build/lib/$(Platform)/%{cfg.buildcfg}",
	}

	links 
	{
		"ddraw.lib",
		"dxguid.lib",
		"opengl32.lib",
		"glu32.lib",
		"libsndfile.lib",
		"freeimage.lib",
		"libconfig.lib",
		"lua.lib",
		"OpenAL32.lib",
		"vfw32.lib",
		"WSOCK32.LIB",
		--"alut.lib",
	}

	-- Configuration-specific settings
    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On" -- Generate debug symbols
    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On" -- Enable optimizations
    filter {} -- Clear filter for general settings

	------------------------------------------------------------------------------
	-- Define the mapping of platforms to project file extensions
	local platformProjectExtensions = 
	{
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
		local projectFiles = os.matchfiles(rootDir .. "/*." .. projectExtension)
		for _, projectFile in ipairs(projectFiles) do
			local projectName = projectFile:match("([^/\\]+)%..+$") -- Extract project name

			print("Adding library: " .. projectFile)
			links { projectName .. ".lib" }
			links { projectName }
		end
    end
	------------------------------------------------------------------------------
	-- Step 2: Include external projects based on generated project files
	local libraries= {} -- Collect all library names
	local function includeProjects(rootDir)

		local projectFiles = os.matchfiles(rootDir .. "/*." .. projectExtension)
		for _, projectFile in ipairs(projectFiles) do
			local projectName = projectFile:match("([^/\\]+)%..+$") -- Extract project name

			print("Adding external project: " .. projectFile)
			externalproject(projectName)
				location(rootDir)
				kind "StaticLib" -- Modify as needed
				language "C++"

			links { projectName }
		end
    end

	------------------------------------------------------------------------------
    frameworkRoot = sourceRoot .. "/../GammaE"
	print("Framework dir: " .. frameworkRoot)
 
	-- Add the external project to the solution
    includeLibraries(frameworkRoot .. "/build")	
    includeProjects(frameworkRoot .. "/build")

-- Install rules (using a post-build step for example purposes)
project(ProjectName) -- for some reason this is reset, so we need to setup it again
	print("Final data:" .. ProjectRelativeFinalDataRoot)
	postbuildcommands
	{
		-- "{MKDIR} %{wks.location}/dist/lib", -- Create output directory
		"{COPYFILE} " .. ProjectRelativeSDKSRoot .. "/Externals/FreeImage/Dist/$(Platform)/%{cfg.buildcfg}/FreeImage.dll " .. ProjectRelativeFinalDataRoot
	}
