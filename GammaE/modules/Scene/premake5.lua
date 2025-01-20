-- Premake5.lua
project_name = "Scene"
caller_script_directory = os.getcwd();

workspace("GammaE_" .. project_name)
	dofile(caller_script_directory .. "/../common.lua")

includedirs {
		"$(ProjectDir)../../sdks/FileLib/Src;",
		"$(ProjectDir)../../sdks/TexLib/src;"
	}

-- Install rules (using a post-build step for example purposes)
postbuildcommands {
    -- "{MKDIR} %{wks.location}/dist/lib", -- Create output directory
    -- "{COPYFILE} %{cfg.targetdir}/MyLibrary.lib %{wks.location}/dist/lib" -- Copy library to the dist directory
}
