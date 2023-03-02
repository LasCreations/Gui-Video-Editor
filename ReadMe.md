# Video Editor

## Recquired Packages
- FFmpeg Libraries 
- GStreamer
- Gtk/Gtk3+
- SDL2

## How To Install 
In the scripts folder there are different type of shell commands.
First run the configure file then the build file. 
If you want to install it onto your system at the path (/usr/bin/), so that you can run it anywhere in your terminal firstly ensure 
you are in super user mode (sudo) and then run the install file, and now that it is installed all you have to do is enter MFF in the terminal 
and the program will be launched.   
If you choose not to do so just simply run the run file.

## Directory Structure

```
|-- bin
	`|-- CMakeCache.txt
	|-- CMakeFiles
	|-- cmake_install.cmake
	|-- install_manifest.txt
	|-- Makefile
	|-- MFF
|-- CMakeLists.txt
|-- include
	|-- Audio.h
	|-- VideoData.h
	|-- Video.h
	|-- Widget.h
	|-- Window.h
|-- projects
	|-- ReadMe.txt
|-- ReadMe.md
|-- scripts 
	|-- build.sh
	|-- configure.sh
	|-- install.sh
	|-- run.sh
|-- src 
	|-- main.c
	|-- Video.c
	|-- VideoData.c
	`|--Window.c
```

<!--
```
|-- Makefile           <- Project makefile
|-- README             <- Project README
|-- bin                <- Compiled binaries
|   `-- run            <- Project main executable
|-- build              <- Static objects and intermediate files
|-- data               <- Project data
|   |-- raw            <- Raw data
|   |-- interim        <- Interm data
|   |-- input          <- Input data
|   |-- output         <- Output data
|-- docs               <- Documentation
|-- include            <- Header files
|-- lib                <- Dynamic objects
|-- src                <- Source files
`-- tests              <- Unit tests
```

-->



## FFmpeg Libraries
- libavcodec           <-- encoding/decoding library
- libavfilter          <-- graph-based frame editing library
- libavformat          <-- I/O and muxing/demuxing library
- libavdevice          <-- special devices muxing/demuxing library
- libavutil            <-- common utility library
- libswresample        <-- audio resampling, format conversion and mixing
- libpostproc          <-- post processing library
- libswscale           <-- color conversion and scaling library


### Task List
- [x] Create a Window
- [x] Create Project Folder
- [x] Import A Video
- [x] Get Video Data

