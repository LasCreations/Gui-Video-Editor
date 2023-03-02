# Video Editor

## Recquired Packages
- FFmpeg Libraries 
- GStreamer
- Gtk/Gtk3+
- SDL2

## How To Build Using Cmake
In the main directory run command
- cmake -S . -B bin/

## How To Run Using Cmake
Go into the build directory and run command make
To run program ./main

## How To Build Using GCC
- gcc audio.c -o main -Wall `pkg-config --cflags gtk+-3.0` `pkg-config --libs gtk+-3.0` `pkg-config --cflags --libs gstreamer-video-1.0 gstreamer-1.0 gstreamer-audio-1.0` `sdl2-config --cflags --libs` -lavutil -lswresample -lm

## Directory Structure


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
