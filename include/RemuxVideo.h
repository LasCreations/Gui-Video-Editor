#ifndef REMUX_VIDEO_H
#define REMUX_VIDEO_H

/**
 * @file libavformat/libavcodec demuxing and muxing API usage example
 * @example remux.c
 *
 * Remux streams from one container format to another. Data is copied from the
 * input to the output without transcoding.
 */

#include <libavformat/avformat.h>
#include <libavutil/timestamp.h>

int Remuxing(char in_filename[],char out_filename[]);

void log_packet(const AVFormatContext *fmt_ctx, const AVPacket *pkt, const char *tag);

#endif

