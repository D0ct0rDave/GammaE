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
    local excludePremakesInDirs = { 
        "build",
    }

    -- Helper function to check if a directory should be excluded
    local function isPremakeInDirExcluded(dir)
        for _, exclude in ipairs(excludePremakesInDirs) do
            if dir:find(exclude) then
                return true
            end
        end
        return false
    end
	
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
	local function extractUuidFromVcxproj(vcxprojPath)
		-- Open the .vcxproj file for reading
		local file = io.open(vcxprojPath, "r")
		if not file then
			print("Failed to open " .. vcxprojPath)
			return nil
		end

		-- Read the contents line by line
		for line in file:lines() do
			-- Match the ProjectGuid field and extract the UUID
			local uuid = line:match("<ProjectGuid>{(.-)}</ProjectGuid>")
			if uuid then
				file:close()
				return uuid
			end
		end

		file:close()
		print("No UUID found in " .. vcxprojPath)
		return nil
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
			
				-- Extract the UUID from the .vcxproj file
				local extractedUuid = extractUuidFromVcxproj(projectFile)
				--[[
				if not extractedUuid then
					print("Warning: No UUID found for project " .. projectName)
				else
					print("UUID for " .. projectName .. ": " .. extractedUuid)
				end
				]]

				print("Adding external project: " .. projectFile)
				externalproject(projectName)
					location(entry)
					kind "StaticLib" -- Modify as needed
					language "C++"
				
					--[[if extractedUuid then
						uuid(extractedUuid) -- Add the extracted UUID
					end
					]]
				
				dependson { projectName }
			end
			-- Recurse into subdirectories
			includeProjects(entry)
        end
    end
	------------------------------------------------------------------------------
	local function includeProjectsAndSetupReferences(rootDir)
		local entries = os.matchdirs(rootDir .. "/*") -- Find all subdirectories
		local projectNames = {} -- Store the names of included projects
		print("matchdirs project: " .. rootDir)
		for _, entry in ipairs(entries) do
			if os.isfile(entry .. "/premake5.lua") and not isPremakeInDirExcluded(entry) then

				local projectName = entry:match("([^/\\]+)$") -- Extract project name from directory
				print("Including project: " .. projectName)
				include(entry) -- Include the library's premake5.lua to preserve settings

				-- Collect the project name for linking
				table.insert(projectNames, projectName)
			end

			-- Recurse into subdirectories
			includeProjectsAndSetupReferences(entry)
		end

		return projectNames
	end
	------------------------------------------------------------------------------
	-- Add the external project to the solution
	print("Framework dir " .. frameworkRoot)

	--	local librariesToLink = includeProjectsAndSetupReferences(frameworkRoot)
	--	print(table.concat(librariesToLink,", "))
    --	links(librariesToLink) -- Automatically set up project references
	
    includeLibraries(frameworkRoot)	
    includeProjects(frameworkRoot)

	-- local lolo = "lole.lib; e333d.lib; adfffe.lib;"
	-- links { lolo }
	

-- Install rules (using a post-build step for example purposes)
postbuildcommands {
    -- "{MKDIR} %{wks.location}/dist/lib", -- Create output directory
    -- "{COPYFILE} %{cfg.targetdir}/MyLibrary.lib %{wks.location}/dist/lib" -- Copy library to the dist directory
}
