# GammaE (~2000-2009)
GammaE 3D Engine

The GammaE project started as a way of putting into practice the knowledge I had acquired over time when I started working in the video game industry back in 2000.
I started working for a major video game company in 1999, and soon after I began to develop a great interest in the field of computer graphics and game engine design, which led me to study every paper or article and in general any related information that fell into my hands.
The name GammaE comes from joining the words Game and Engine, and since GameEngine is an extremely generic name, it derived into GameE and finally into GammaE.

This repository aims to collect the work done during those years so that it is not lost forever in the sectors of my hard drives, and by the way, if anyone wants to take a look, they can take what they need and adapt it to their needs.

I have tried to create a first commit with the work done during the first period, although after so much time, I think some later files have slipped through. However, I have tried to create a small functional base as a first iteration.

While I have been working on recovering this code base, I have remembered, looking at the code, that the engine has changed over time, and some projects use one version of the engine and others another. Specifically, the engine was initially implemented using Rational Rose for the design and interaction of classes and systems and this makes the code full of commented code that the application interprets during code generation. In the last iterations this code was removed and the files became much cleaner.


## ProjectR (2009-2010):
This is one of the latest iterations of the game engine. 

At this point many improvements and modifications have been added.
- One of the main things done has been the cleanup of all the garbage introduced by the Rational Rose code generation system.
- Also the naming conventions have improved from previous iterations.
- A documentation system has been introduced using Doxygen.
- Many new features have been integrated.
- Quake 2 like console with command interpreter.
- Added video rendering as an extension from the application (ProjectR)
- Lua support and c++ bindings to the game engine.
- On previous iterations AI library using A* algorithm.
- Network support (from previous a project Word Challenge Multiplayer)
- Many SFX features included etc.

ProjectR is a new SpaceShooter prototype. The game action  featured a background video which produced the scrolling. The entities where presented moving towards the player
