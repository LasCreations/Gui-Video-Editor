Install these
apt-get install -y libavcodec-dev libavformat-dev libavutil-dev libswresample-dev

Compile
gcc `pkg-config --cflags gtk+-3.0` main.c -o main `pkg-config --libs gtk+-3.0` -Wall -lavutil -lswresample

