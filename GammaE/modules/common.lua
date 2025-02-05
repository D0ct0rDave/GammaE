project(project_name)

    kind "StaticLib" -- Change to "SharedLib" for a shared library
    language "C++"
    cppdialect "C++17"
    targetdir "$(ProjectDir)/lib/$(Platform)/%{cfg.buildcfg}" -- Output directory for binaries
    objdir "$(ProjectDir)/obj/$(Platform)" -- Output directory for intermediate files
	characterset("ASCII")

    -- Specify the root directory of the library
    sourceRoot = caller_script_directory

	-- Determine the current platform's project file extension
    currentPlatform = os.target():lower() -- e.g., "windows", "linux", "macosx"

	-- specific defines for this project
	defines 
	{
		"NULL=0",
		"_MBCS" 
	}

	filter { "system:windows" }
		defines { "WIN32" }
	filter {} -- Reset filter
	
	disablewarnings
	{
		"4091",
	}
	
    -- Recursively include all .cpp and .h files from the sourceRoot directory
    files 
	{
        sourceRoot .. "/**.cpp",
        sourceRoot .. "/**.h",
		sourceRoot .. "/**.inl"
    }

    -- Exclude certain directories (e.g., build, CMakeFiles)
    removefiles
	{
        sourceRoot .. "**doxy_g.h",
		sourceRoot .. "/build/**",
        sourceRoot .. "/CMakeFiles/**"
    }

    -- Add include directories (sourceRoot is included by default)
    includedirs 
	{
		"$(ProjectDir)../inc",
		"$(ProjectDir)../../../inc",
		"$(ProjectDir)../modules/" .. project_name .. "/src",
		"$(ProjectDir)../src/"
    }

    -- Configuration-specific settings
    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On" -- Generate debug symbols

    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On" -- Enable optimizations

    filter {} -- Clear filter for general settings
