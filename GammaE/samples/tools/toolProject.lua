------------------------------------------------------------------------------
function addToolProject(_projectName, windowedApplication)

	local ProjectRelativeFinalDataRoot = "$(ProjectDir)../" .. _projectName .. "/data"
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
		sourceRoot = scriptRoot .. "/" .. _projectName

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
			ProjectRelativeSDKSRoot .. "/Externals/wxWidgets2.8/include",
			ProjectRelativeSDKSRoot .. "/Externals/wxWidgets2.8/include/msvc",
		}

		-- Library directories common for all configurations
		libdirs
		{
			ProjectRelativeSDKSRoot .. "/Externals/wxWidgets2.8/lib/vc_lib/x64",
			ProjectRelativeSDKSRoot .. "/Externals/FreeImage/Dist/x64",
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

		filter "configurations:Release"
			defines
			{ 
				"NDEBUG"
			}

			optimize "On" -- Enable optimizations

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