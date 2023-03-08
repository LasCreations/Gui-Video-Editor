

#ifndef DECODE_VIDEO_H
#define DECODE_VIDEO_H

#include <libavutil/opt.h>
#include <libavutil/time.h>
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libavformat/avio.h>
#include <libavutil/avstring.h>
#include <libswscale/swscale.h>
#include <libswresample/swresample.h>
#include <libavutil/dict.h>
#include <libavutil/timestamp.h>


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void DecodeVideo(char filename[]);


int Remuxing(char in_filename[],char out_filename[]);

#endif


