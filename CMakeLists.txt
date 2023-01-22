cmake_minimum_required(VERSION 3.21)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-O3 -Wall")
project(main C CXX)

file(GLOB CPP_SOURCE
"${PROJECT_SOURCE_DIR}/src/*.c"
)


FIND_PACKAGE(PkgConfig REQUIRED)

PKG_CHECK_MODULES(GTK REQUIRED gtk+-3.0 gstreamer-video-1.0 gstreamer-1.0 gstreamer-audio-1.0)

add_executable(main ${CPP_SOURCE})

include_directories(${PROJECT_SOURCE_DIR}/lib ${GTK_INCLUDE_DIRS})

ADD_DEFINITIONS(${GTK_CFLAGS_OTHER})

LINK_DIRECTORIES(${GTK_LIBRARY_DIRS})

target_link_libraries(main -lavutil -lswresample ${GTK_LIBRARIES})
