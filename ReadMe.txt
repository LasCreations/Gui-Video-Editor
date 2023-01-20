Install these recquired packages


######libavcodec########
apt-get install -y libavcodec-dev libavformat-dev libavutil-dev libswresample-dev


#####GStreamer########
GStreamer is sometimes preinstalled on some distros ... i.e. Kali, Ubuntu

##Install 
sudo apt-get install libgstreamer-plugins-base1.0-dev

apt-get install libgstreamer1.0-dev libgstreamer-plugins-base1.0-dev libgstreamer-plugins-bad1.0-dev gstreamer1.0-plugins-base gstreamer1.0-plugins-good gstreamer1.0-plugins-bad gstreamer1.0-plugins-ugly gstreamer1.0-libav gstreamer1.0-doc gstreamer1.0-tools gstreamer1.0-x gstreamer1.0-alsa gstreamer1.0-gl gstreamer1.0-gtk3 gstreamer1.0-qt5 gstreamer1.0-pulseaudio


#####Gtk for C######
sudo apt install libgtk-3-dev

Compile
gcc `pkg-config --cflags gtk+-3.0` main.c -o main `pkg-config --libs gtk+-3.0` -Wall -lavutil -lswresample
gcc main.c -o main `pkg-config --cflags gtk+-3.0` `pkg-config --libs gtk+-3.0` `pkg-config --cflags --libs gstreamer-video-1.0 gstreamer-1.0 gstreamer-audio-1.0`
