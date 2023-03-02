
#include "../include/VideoData.h"


char *GetData(char *filename){
	AVFormatContext *fmt_ctx = NULL;
	int ret;
	//char *filename = "/home/lascelle/Videos/Sample2.mp4";
	
	//fill format context with file info
	avformat_open_input(&fmt_ctx, filename, NULL, NULL);

	// get streams info from format context
	if ((ret = avformat_find_stream_info(fmt_ctx, NULL)) < 0) {
		av_log(NULL, AV_LOG_ERROR, "Cannot find stream information\n");
		//return ret;
	}

	// loop streams and dump info
	for (int i = 0; i < fmt_ctx->nb_streams; i++)
	{
		//printf("it was print here");
		av_dump_format(fmt_ctx, i, filename, false);		
	}

	// close format context
	avformat_close_input(&fmt_ctx);
	return NULL;
}
