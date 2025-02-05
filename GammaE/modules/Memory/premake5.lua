-- Premake5.lua
project_name = "Memory"
caller_script_directory = os.getcwd();

dofile(caller_script_directory .. "/../common.lua")

-- Install rules (using a post-build step for example purposes)
postbuildcommands {
    -- "{MKDIR} %{wks.location}/dist/lib", -- Create output directory
    -- "{COPYFILE} %{cfg.targetdir}/MyLibrary.lib %{wks.location}/dist/lib" -- Copy library to the dist directory
}
