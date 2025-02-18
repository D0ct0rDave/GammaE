# GammaE (~2000-2009)

## GammaE 3D Engine

The GammaE project started as a way of putting into practice the knowledge I had acquired over time when I started working in the video game industry back in 2000.
I started working for a major video game company in 1999, and soon after I began to develop a great interest in the field of computer graphics and game engine design, which led me to study every paper or article and in general any related information that fell into my hands.
The name GammaE comes from joining the words Game and Engine, and since GameEngine is an extremely generic name, it derived into GameE and finally into GammaE.

This repository aims to collect the work done during those years so that it is not lost forever in the sectors of my hard drives, and by the way, if anyone wants to take a look, they can take what they need and adapt it to their needs.

I have tried to create a first commit with the work done during the first period, although after so much time, I think some later files have slipped through. However, I have tried to create a small functional base as a first iteration.

While I have been working on recovering this code base, I have remembered, looking at the code, that the engine has changed over time, and some projects use one version of the engine and others another. Specifically, the engine was initially implemented using Rational Rose for the design and interaction of classes and systems and this makes the code full of commented code that the application interprets during code generation. In the last iterations this code was removed and the files became much cleaner.

The engine is highly influenced by the Quake2/3 engine. It can be seen one the shader system implemented to render the 3D geometry and also, the input configuration, and also the command interpreter implemented at higher level.

## Repository structure

The repository has several branches and every branch represents a stage in the project.
Each stage has a sample application depicting the main features at this point or introduced since last iteration.

- Sample application is the initial application that shows some features developed in the engine.
- BThrower
- Orion is a Rogue Squadron like project developed on the early 2000's
- Word Challenge MP
- ProjectR is a 2D space shooter sidescroller prototyping new techniques like script integration, and other things.
- ProjectS  


## Build
First you will need to build the dependencies of the engine. Depending on the branch selected we'll have to build some dependencies or another.

For the main / master branch you will need to build.
FreeImage (SDKS/Externals/FreeImage)
lua (SDKS/Externals/lua)

If you need to build tools:
wxWidgets (SDKS/Externals/wxWidgets2.8)


Generate the Engine project files with gen_solution_vs2022.bat. This is located under $(RepositoryRoot)/GammaE.

This will generate the engine project and solution files under the build directory. You can now open the solution file and do a full rebuild.

You can now generate the Tools, the samples or the Main project project files.
- Tools: use gen_solution_vs2022.bat on $(RepositoryRoot)/GammaE/Tools
- Samples: use gen_solution_vs2022.bat on $(RepositoryRoot)/GammaE/Samples
- MainProject: use gen_solution_vs2022.bat on $(RepositoryRoot)/ProjectS
	
The main project folder may depend on the branch currently checkedout. 

The current branches are: 
- ProjectS, 
- ProjectR, 
- Orion, 
- GammaE_Framework

## Branches

### GammaE_Framework
- Platform independent engine and framework structure.
- Quake3 like "shaders".
- 3D / Scene Graph / Collision multiplatform engine
- MD2 / MD3 / Q2BSP support.

![Screenshot5.png](https://raw.githubusercontent.com/D0ct0rDave/GammaE_Engine/refs/heads/GammaE_Branch/repoimgs/Screenshot5.png)

![Screenshot6.png](https://raw.githubusercontent.com/D0ct0rDave/GammaE_Engine/refs/heads/GammaE_Branch/repoimgs/Screenshot6.png)

### ProjectR
Some remarcable features:
- Video rendering for the scrolling background,
- Sample HUD defined in text file
- Script in lua to handle entities.

In game screenshots. 

![screenshot1.png](https://raw.githubusercontent.com/D0ct0rDave/GammaE_Engine/refs/heads/ProjectR/repoimages/screenshot0001.png)

![screenshot2.png](https://raw.githubusercontent.com/D0ct0rDave/GammaE_Engine/refs/heads/ProjectR/repoimages/screenshot0002.png)

The console / Command Interpreter

![screenshot0.png](https://raw.githubusercontent.com/D0ct0rDave/GammaE_Engine/refs/heads/ProjectR/repoimages/screenshot0000.png)


Añadir documentación de tools con screenshot
- Particle editor
- GAS / GTS / MD2 / GEM Loader / GEM Saver / 3D Viewer
