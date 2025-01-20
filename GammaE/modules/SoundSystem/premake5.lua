-- Premake5.lua
project_name = "SoundSystem"
caller_script_directory = os.getcwd();

workspace("GammaE_" .. project_name)
	dofile(caller_script_directory .. "/../common.lua")

	includedirs {
		"$(ProjectDir)../../SDKS/FileLib/Src;",
		"$(ProjectDir)../../SDKS/libsndfile/src",
		"$(ProjectDir)../../SDKS/OpenAL 1.1 SDK/include"
	}

	removefiles { 
			"**/SndDrv_BASS/*", 
			"**/SndDrv_DirectSound/*", 
			"**/SndDrv_SDL/*",
	}

	-- Exclude	files
	filter { "files:**_BASS*" }
	  flags {"ExcludeFromBuild"}



-- Install rules (using a post-build step for example purposes)
postbuildcommands {
    -- "{MKDIR} %{wks.location}/dist/lib", -- Create output directory
    -- "{COPYFILE} %{cfg.targetdir}/MyLibrary.lib %{wks.location}/dist/lib" -- Copy library to the dist directory
}
