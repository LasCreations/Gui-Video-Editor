/*:
 * @file Video.c
 * @author Lascelle Mckenzie
 * @details 
*/

#include "../include/Video.h"


void SetData(GtkWidget *window, GtkWidget *VideoBox, char filepath[]){ 
	//DecodeVideo("/home/lascelle/Videos/Sample2.mp4");
	//Remuxing("/home/lascelle/Videos/Sample2.mp4", "test.mkv");
	VideoMain(window, VideoBox, "file:///home/lascelle/Videos/Sample.mp4");
}
