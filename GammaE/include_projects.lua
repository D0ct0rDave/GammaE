-- premake5.lua for the full Framework
BUILD_LOCATION = os.getcwd() .. "/build"

workspace "GammaE"
    configurations { "Debug", "Release" }
    location(BUILD_LOCATION) -- Generated build files for the workspace
    architecture "x86_64"

    -- Set the C++ standard for all projects in the workspace
    cppdialect "C++17"

    -- Define the root directory containing all libraries
    local frameworkRoot = os.getcwd()
	
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
	
	print("Current plaform: ".. currentPlatform)
	
	-- Step 2: Include external projects based on generated project files
    local function includeProjects(rootDir)
		local projectFileFound = false;
		-- print("Processing external projects in : " .. rootDir)
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
				
			if projectFileFound then break end

			-- Recurse into subdirectories
			includeProjects(entry)
        end
    end

    includeProjects(frameworkRoot)

-- Additional settings for the workspace can go here
