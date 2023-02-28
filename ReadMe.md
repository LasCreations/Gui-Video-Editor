# Video Editor

## Recquired Packages
- libavcodec
- GStreamer
- Gtk/Gtk3+
- SDL2



## How To Run
> Using cmake 
- Run command
- cmake CMakeLists.txt
- make
- ./main

> Using cmd
- gcc audio.c -o main -Wall `pkg-config --cflags gtk+-3.0` `pkg-config --libs gtk+-3.0` `pkg-config --cflags --libs gstreamer-video-1.0 gstreamer-1.0 gstreamer-audio-1.0` `sdl2-config --cflags --libs` -lavutil -lswresample -lm

### Task List
- [x] Create a Window
- [x] Import A Video



