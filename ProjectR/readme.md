# ProjectR (2009-2010):
This is one of the latest iterations of the game engine. 

## Engine features at this point.
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

## Project description 
ProjectR is a new SpaceShooter prototype.
The game action plays on a screen where a video produces the scroll of the background.The entities move towards the player and this creates the sensation of the player moving forward like in most side scrollers
One of the things I prototyped was the implementation of entities behavior and game flow using lua scripts, just for the sake of this.

Another experiment was the creation of the HUD created from text data files.
In general everything is configured using text files, shaders (a la Quake3), config (For input and commands)

## Troubleshoting
The video is encoded in XVid. If the video is not displayed properly (you can check an error message in the console log) maybe it's because you are lacking the appropriate decoder.

## Screenshots
![screenshot1.png](https://raw.githubusercontent.com/D0ct0rDave/GammaE_Engine/refs/heads/ProjectR/repoimages/screenshot0001.png)
![screenshot2.png](https://raw.githubusercontent.com/D0ct0rDave/GammaE_Engine/refs/heads/ProjectR/repoimages/screenshot0002.png)
![screenshot3.png](https://raw.githubusercontent.com/D0ct0rDave/GammaE_Engine/refs/heads/ProjectR/repoimages/screenshot0003.png)

Quake console with command interpreter.
![screenshot0.png](https://raw.githubusercontent.com/D0ct0rDave/GammaE_Engine/refs/heads/ProjectR/repoimages/screenshot0000.png)
