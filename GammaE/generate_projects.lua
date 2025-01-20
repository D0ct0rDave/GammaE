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
    
    -- List of directories to exclude from recursion
    local excludeDirs = { 
        "build",
		"UML",
		"Tools"
    }

    -- Helper function to check if a directory should be excluded
    local function isExcluded(dir)
        for _, exclude in ipairs(excludeDirs) do
            if dir:find(exclude) then
                return true
            end
        end
        return false
    end
       
    -- Step 1: Recursively locate and include all premake5.lua files in subdirectories
    local function includeLibraries(rootDir)
        local entries = os.matchdirs(rootDir .. "/*") -- Find all subdirectories
        for _, entry in ipairs(entries) do
            if not isExcluded(entry) then
                if os.isfile(entry .. "/premake5.lua") then
                    print("Including library: " .. entry)
                    include(entry)

                    --[[
                    print("Adding library project to workspace: " .. entry)
                    project(entry:match("([^/\\]+)$")) -- Use the directory name as the project name
                        location("build")
                        kind "StaticLib" -- Default to StaticLib; can be overridden in individual premake5.lua files
                        files {
                            entry .. "/**.cpp",
                            entry .. "/**.h"
                        }
                        includedirs {
                            entry
                        }
                    ]]

                else
                    -- Recurse into subdirectories to locate premake5.lua
                    includeLibraries(entry)
                end
            end
        end
    end
    
    includeLibraries(frameworkRoot)

-- Additional settings for the workspace can go here
