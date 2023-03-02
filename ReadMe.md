# Video Editor

## Recquired Packages
- libavcodec
- GStreamer
- Gtk/Gtk3+
- SDL2

## How To Build Using Cmake
In the main directory run command
- cmake -S . -B build/
This places all the Cmake build files in the build folder

## How To Run Using Cmake
Go into the build directory and run command make
To run program ./main

## How To Build Using GCC
- gcc audio.c -o main -Wall `pkg-config --cflags gtk+-3.0` `pkg-config --libs gtk+-3.0` `pkg-config --cflags --libs gstreamer-video-1.0 gstreamer-1.0 gstreamer-audio-1.0` `sdl2-config --cflags --libs` -lavutil -lswresample -lm

## Directory Structure
|--bin                <- Compiled binaries
|    --Makefile       <- Project makefile
|    --main           <- Project main executable
|--config             <- Config files 
|    --
|-- docs              <- Documentation
|--include            <- Header files
|    --
|--projects           <- Projects folder
|--ReadMe             <- General readme of the project
|--src                <- Source files
|    --

### Task List
- [x] Create a Window
- [x] Create Project Folder
- [x] Import A Video
