-- Premake5.lua
workspace "GammaE_Misc"
    configurations { "Debug", "Release" }
    location "build" -- Where generated files (like Visual Studio solutions) will be stored
    architecture "x86_64"

project "Misc"

caller_script_directory = os.getcwd();
dofile(caller_script_directory .. "/../common.lua")

-- Install rules (using a post-build step for example purposes)
postbuildcommands {
    -- "{MKDIR} %{wks.location}/dist/lib", -- Create output directory
    -- "{COPYFILE} %{cfg.targetdir}/MyLibrary.lib %{wks.location}/dist/lib" -- Copy library to the dist directory
}
