# What is MARS?
MARS is a C++, Open Source, 3D Game Engine in development. Started this project roughly 4 years ago when I was still learning C++; however I abandoned the project because of life situations. Well, it's almost 4 years later and I cloned the old repo and made this new one because why not. I think it'd be to work on again and see how much better I've gotten over the years.

Feel free to follow along or make pull requests. This isn't a serious project, just something to fool around with.

The idea for MARS originally came about when I wanted to create something unique and challenging. 
A Game Engine seemed like a huge task and a large challenge which added to the the enjoyment of working on it.

# Planned Features
- [ ] Completely abstracted Rendering API with the ability to hotswap the renderer you are using with a simple console command.
- [ ] Easy to extand gameplay framework
- [ ] Commplete scripting language to allow easy gameplay scripting
- [ ] AI Suite
- [ ] Complete Entity Component System
- [ ] Networking Layer
- [x] Robust logging system
- [ ] Custom data types (Array, Map, Vector, etc) (in-progress)
-  - [x] Stack
-  - [ ] Array
-  - [ ] Map
-  - [ ] String
-  - [ ] Vector
-  - [ ] Tuple
- [x] Custom Platform Layer to allow the engine to run anywhere
- [x] Robust event system
- [x] Built in input polling/buffer
- [ ] MARS Tool Framework -- A suite of tools designed to make working with MARS easy. (Class Tool, Project Setup Tool, etc)
- [ ] Easy to use Editor (in-progress)
- [ ] Custom Multi-threading class to easily create mutli-threaded game code
- [ ] Level Editor
- [ ] In-Editor Visual Scripting Language for designers and artists

# Supported Platforms
 - [x] Windows 10 (x64) [primary priority]
 - [ ] Linux (Partial Support) [secondary priority]
 - [ ] Mac OSX
 - [ ] PlayStation
 - [ ] Xbox

# Implemented Rendering APIs
- [ ] DirectX 11
- [ ] DirectX 12
- [ ] Vulkan
- [ ] OpenGL 4.6 (In-Progress)

# Getting started
### Building the Project

- `git clone` the project. 
- Run `git submodule init` and `git submodule update`
- Install Visual Studio 2019 if you haven't already
- Create a folder inside of Thirdparty called "Libs". 
- Build assimp, glfw3, SDL2 and SDL2main and place their .lib files inside of the Libs folder. 
- Run the GenProjectFiles.bat script.
- Run the MARS.sln.bat script
- Build the ALL_BUILD project in VS

### Running the engine
- Set the MARSEditor project as the startup project
- Run the project
