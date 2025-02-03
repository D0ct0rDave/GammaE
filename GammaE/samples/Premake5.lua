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
local function includeExternalProjects(rootDir)

	local projectFiles = os.matchfiles(rootDir .. "/*." .. projectExtension)
	for _, projectFile in ipairs(projectFiles) do
		local projectName = projectFile:match("([^/\\]+)%..+$") -- Extract project name

		print("Adding external project: " .. projectFile)
		externalproject(projectName)
			location(rootDir)
			kind "StaticLib" -- Modify as needed
			language "C++"
	end
end

------------------------------------------------------------------------------

scriptRoot = os.getcwd()	
frameworkRoot = scriptRoot .. "/.."

------------------------------------------------------------------------------

local function addSampleProject(_projectName)
	
	local ProjectRelativeFinalDataRoot = "$(ProjectDir)../graphics/" .. _projectName .. "/data"
	local ProjectRelativeSDKSRoot = "$(ProjectDir)../../../SDKS"
	local ProjectRelativeGammaERoot = "$(ProjectDir)../.."

	project(_projectName)
		kind "WindowedApp" -- Change to "SharedLib" for a shared library
		language "C++"
		cppdialect "C++17"
		targetdir "$(ProjectDir)/exe/%{cfg.buildcfg}" -- Output directory for binaries
		objdir "$(ProjectDir)/obj/%{cfg.buildcfg}" -- Output directory for intermediate files
		characterset("ASCII")
		debugdir(ProjectRelativeFinalDataRoot)

		-- Recursively include all .cpp and .h files from the sourceRoot directory
		sourceRoot = scriptRoot .. "/graphics/" .. _projectName

		files {
			sourceRoot .. "/src/**.cpp",
			sourceRoot .. "/src/**.h",
			sourceRoot .. "/src/**.txt",
		}

		-- specific defines for this project
		defines {
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
			ProjectRelativeSDKSRoot .. "/Externals/FreeImage/Dist;",
			}

		-- Library directories common for all configurations
		libdirs
		{
			ProjectRelativeSDKSRoot .. "/Externals/FreeImage/Dist/x64;",
			ProjectRelativeSDKSRoot .. "/OpenAL 1.1 SDK/libs",
			ProjectRelativeSDKSRoot .. "/OpenAL 1.1 SDK/libs/Win64",
			ProjectRelativeSDKSRoot .. "/lua-5.4.7/lib/x64/%{cfg.buildcfg}",	
			ProjectRelativeSDKSRoot .. "/libsndfile/lib/x64/%{cfg.buildcfg}",
			ProjectRelativeSDKSRoot .. "/libconfig/lib/x64/%{cfg.buildcfg}",
			ProjectRelativeGammaERoot .. "/build/lib/%{cfg.buildcfg}",
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
		}

		-- Configuration-specific settings
		filter "configurations:Debug"
			defines { "DEBUG" }
			symbols "On" -- Generate debug symbols
		filter "configurations:Release"
			defines { "NDEBUG" }
			optimize "On" -- Enable optimizations
		filter {} -- Clear filter for general settings

		-- Add the external project to the solution
		includeLibraries(frameworkRoot .. "/build")	

	-- Install rules (using a post-build step for example purposes)

	project(_projectName) -- for some reason this is reset, so we need to setup it again
		print("Final data:" .. ProjectRelativeFinalDataRoot)
		postbuildcommands
		{
			-- "{MKDIR} %{wks.location}/dist/lib", -- Create output directory
			"{COPYFILE} " .. ProjectRelativeSDKSRoot .. "/Externals/FreeImage/Dist/x64/FreeImage.dll " .. ProjectRelativeFinalDataRoot
		}
end
------------------------------------------------------------------------------
function addToolProject(_projectName, windowedApplication)

	local ProjectRelativeFinalDataRoot = "$(ProjectDir)../tools/" .. _projectName .. "/data"	
	local ProjectRelativeSDKSRoot = "$(ProjectDir)../../../SDKS"
	local ProjectRelativeGammaERoot = "$(ProjectDir)../.."

	project(_projectName)
		if windowedApplication then
			kind "WindowedApp" -- Change to "SharedLib" for a shared library
		else
			kind "ConsoleApp" -- Change to "SharedLib" for a shared library
		end
		
		language "C++"
		cppdialect "C++17"
		targetdir "$(ProjectDir)/exe/%{cfg.buildcfg}" -- Output directory for binaries
		objdir "$(ProjectDir)/obj/%{cfg.buildcfg}" -- Output directory for intermediate files
		characterset("ASCII")
		debugdir(ProjectRelativeFinalDataRoot)

		-- Recursively include all .cpp and .h files from the sourceRoot directory		
		sourceRoot = scriptRoot .. "/tools/" .. _projectName

		files
		{
			sourceRoot .. "/src/**.cpp",
			sourceRoot .. "/src/**.h",
			sourceRoot .. "/src/**.txt",
		}

		-- specific defines for this project
		defines
		{
			"_MBCS",
			"_OGL_",
			"_OPENAL_",
			"FREEIMAGE_LIB",
			"__WXMSW__",
			"NOPCH",
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
			ProjectRelativeSDKSRoot .. "/Externals/FreeImage/Dist;",
		}

		if windowedApplication then
			includedirs 
			{
				ProjectRelativeSDKSRoot .. "/Externals/wxWidgets2.8/include",
				ProjectRelativeSDKSRoot .. "/Externals/wxWidgets2.8/include/msvc",
			}			
		end

		-- Library directories common for all configurations
		libdirs
		{
			ProjectRelativeSDKSRoot .. "/Externals/FreeImage/Dist/x64",
			ProjectRelativeSDKSRoot .. "/OpenAL 1.1 SDK/libs",
			ProjectRelativeSDKSRoot .. "/OpenAL 1.1 SDK/libs/Win64",
			ProjectRelativeSDKSRoot .. "/lua-5.4.7/lib/x64/%{cfg.buildcfg}",	
			ProjectRelativeSDKSRoot .. "/libsndfile/lib/x64/%{cfg.buildcfg}",
			ProjectRelativeSDKSRoot .. "/libconfig/lib/x64/%{cfg.buildcfg}",
			ProjectRelativeGammaERoot .. "/build/lib/%{cfg.buildcfg}",
		}

		if windowedApplication then
			libdirs
			{
				ProjectRelativeSDKSRoot .. "/Externals/wxWidgets2.8/lib/vc_lib/x64",
			}
		end		

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
			"wsock32.lib",
			"comctl32.lib",
			"rpcrt4.lib",
			"odbc32.lib",
		}

		-- Configuration-specific settings
		filter "configurations:Debug"
			defines
			{ 
				"DEBUG",
				"__WXDEBUG__",
			}
			symbols "On" -- Generate debug symbols
		
			if windowedApplication then
				links 
				{
					"wxbase28d.lib",
					"wxbase28d_net.lib",
					"wxbase28d_odbc.lib",
					"wxbase28d_xml.lib",
					"wxmsw28d_adv.lib",
					"wxmsw28d_aui.lib",
					"wxmsw28d_core.lib",
					"wxmsw28d_dbgrid.lib",
					"wxmsw28d_gl.lib",
					"wxmsw28d_html.lib",
					"wxmsw28d_media.lib",
					"wxmsw28d_qa.lib",
					"wxmsw28d_richtext.lib",
					"wxmsw28d_xrc.lib",
					"wxexpatd.lib",
					"wxjpegd.lib",
					"wxpngd.lib",
					"wxregexd.lib",
					"wxtiffd.lib",
					"wxzlibd.lib",
				}
			end
		filter "configurations:Release"
			defines
			{ 
				"NDEBUG"
			}

			optimize "On" -- Enable optimizations

			if windowedApplication then
				links 
				{
					"wxmsw28_xrc.lib",
					"wxmsw28_dbgrid.lib",
					"wxmsw28_core.lib",
					"wxbase28.lib",
					"wxbase28_net.lib",
					"wxmsw28_adv.lib",
					"wxmsw28_html.lib",
					"wxbase28_odbc.lib",
					"wxmsw28_richtext.lib",
					"wxbase28_xml.lib",
					"wxmsw28_aui.lib",
					"wxmsw28_media.lib",
					"wxmsw28_qa.lib",
					"wxmsw28_gl.lib",
					"wxtiff.lib",
					"wxjpeg.lib",
					"wxregex.lib",
					"wxpng.lib",
					"wxzlib.lib",
					"wxexpat.lib",
				}
			end

		filter {} -- Clear filter for general settings

		-- Add the external project to the solution
		includeLibraries(frameworkRoot .. "/build")	

	-- Install rules (using a post-build step for example purposes)

	project(_projectName) -- for some reason this is reset, so we need to setup it again
		print("Final data:" .. ProjectRelativeFinalDataRoot)
		postbuildcommands
		{
			"{MKDIR} " .. ProjectRelativeFinalDataRoot, -- Create output directory
			"{COPYFILE} " .. ProjectRelativeSDKSRoot .. "/Externals/FreeImage/Dist/x64/FreeImage.dll " .. ProjectRelativeFinalDataRoot
		}
end
------------------------------------------------------------------------------
-- Premake5.lua
------------------------------------------------------------------------------
workspace "GammaE_Samples"
    configurations { "Debug", "Release" }
    location "build" -- Where generated files (like Visual Studio solutions) will be stored
    architecture "x86_64"

------------------------------------------------------------------------------
group("Samples")
	group("Graphics")
		addSampleProject("Culling")
		addSampleProject("Shaders")
		addSampleProject("SimpleRendering")

	group("Tools")
		addToolProject("wxSampleTool", true)

group("GammaE")	
	includeExternalProjects(frameworkRoot .. "/build")
