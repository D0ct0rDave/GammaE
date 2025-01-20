-- Premake5.lua
project_name = "Sound"
caller_script_directory = os.getcwd();

workspace("GammaE_" .. project_name)
	dofile(caller_script_directory .. "/../common.lua")

includedirs {
		"$(ProjectDir)../../SDKS/FileLib/Src;",
		"$(ProjectDir)../../SDKS/libsndfile-0.0.26/src"		
	}

-- Install rules (using a post-build step for example purposes)
postbuildcommands {
    -- "{MKDIR} %{wks.location}/dist/lib", -- Create output directory
    -- "{COPYFILE} %{cfg.targetdir}/MyLibrary.lib %{wks.location}/dist/lib" -- Copy library to the dist directory
}
