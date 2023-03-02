/*:
 * @file VideoData.h
 * @author Lascelle Mckenzie
 * @details 
*/

#ifndef VIDEO_DATA_H
#define VIDEO_DATA_H

#include <libavutil/opt.h>
#include <libavutil/time.h>
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libavformat/avio.h>
#include <libavutil/avstring.h>
#include <libswscale/swscale.h>
#include <libswresample/swresample.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



char* GetData(char*);

#endif

