# Motion Film Lab
Motion Film Lab is an open source GUI Video Editor, which is entirely written in C.

> NOTE: Motion Film Lab is currently under active development.

## Dependencies
- FFmpeg
- GStreamer
- Gtk/Gtk3+
- SDL2
- cmake

## How To Install 
In the main directory you will find a script folder. In that folder run the command:

```
chmod +x *
```

After this is done run the command:

```
sudo ./install
```
This will install the build file to /usr/bin/. 

You can now search for MFL in your system or type and run MFL in your terminal to start the program.


## How To Uninstall 
In the scripts folder, run the command:
```
sudo ./uninstall
```

## Directory Structure
```
|-- bin
	|-- CMakeCache.txt
	|-- CMakeFiles
	|-- cmake_install.cmake
	|-- install_manifest.txt
	|-- Makefile                      <- Project makefile
	|-- MFF                           <- Project main executable
|-- CMakeLists.txt
|-- include                               <- Header files
	|-- Audio.h
	|-- Video.h
	|-- Image.h
	|-- Window.h
	|-- DecodeVideo.h
	|-- ImportDialog.h
	|-- MenuBar.h
	|-- SaveDialog.h
	|-- SourcePanel.h
	|-- Toolbar.h
|-- projects
	|-- ProjectName
		|-- build
		|-- Imports
			|-- Audio
			|-- Images
			|-- Video
	|-- ReadMe.txt
|-- ReadMe.md                             <- Project README
|-- scripts 
	|-- build.sh
	|-- configure.sh
	|-- install.sh
	|-- add_dependencies.sh
	|-- run.sh
	|-- uninstall.sh
|-- src                                   <- Source files
	|-- Audio.c
	|-- Video.c
	|-- Image.c
	|-- Window.c
	|-- DecodeVideo.c
	|-- ImportDialog.c
	|-- MenuBar.c
	|-- SaveDialog.c
	|-- SourcePanel.c
	|-- Toolbar.c
	|-- main.c
```

## FFmpeg Libraries Used
- libavcodec           <-- encoding/decoding library
- libavfilter          <-- graph-based frame editing library
- libavformat          <-- I/O and muxing/demuxing library
- libavdevice          <-- special devices muxing/demuxing library
- libavutil            <-- common utility library
- libswresample        <-- audio resampling, format conversion and mixing
- libpostproc          <-- post processing library
- libswscale           <-- color conversion and scaling library
