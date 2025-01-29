-- Premake5.lua
project_name = "Game"
caller_script_directory = os.getcwd();

workspace("GammaE_" .. project_name)
	dofile(caller_script_directory .. "/../common.lua")

	files 
	{
        sourceRoot .. "/**.cxx",
	}	
	includedirs 
	{
		"$(ProjectDir)../../SDKS/lua-5.4.7/include;"
	}
	
	-- Exclude file
	filter { "files:**CGScriptBinding.cpp" }
	  flags {"ExcludeFromBuild"}
	filter {} -- Reset filter


-- Install rules (using a post-build step for example purposes)
prebuildcommands 
{
	"$(ProjectDir)../../SDKS/swigwin-4.3.0/swig.exe -includeall -c++ -lua -ignoremissing -DGAMMAE_NO_SOUND -DGAMMAE_NO_NETWORK -I$(ProjectDir)../inc $(ProjectDir)../modules/Game/src/GameRes/Script/CGScriptBinding.cpp"
}

postbuildcommands 
{
    -- "{MKDIR} %{wks.location}/dist/lib", -- Create output directory
    -- "{COPYFILE} %{cfg.targetdir}/MyLibrary.lib %{wks.location}/dist/lib" -- Copy library to the dist directory
}


-- E:\Projects\OldProjects\GammaE_Framework\SDKS\swig\swig.exe -includeall -c++ -lua -ignoremissing -IE:\Projects\OldProjects\GammaE_Framework\SDKS\lua-5.4.7\include IE:\Projects\OldProjects\GammaE_Framework\GammaE\inc GScriptBinding.cpp GScriptBinding_prepro.cpp

-- This has worked -->
-- E:\Projects\OldProjects\GammaE_Framework\SDKS\swig\swig.exe -includeall -c++ -lua -ignoremissing -IE:\Projects\OldProjects\GammaE_Framework\GammaE\inc CGScriptBinding.cpp