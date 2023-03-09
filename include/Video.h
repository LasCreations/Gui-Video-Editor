/*:
 * @file Video.h
 * @author Lascelle Mckenzie
 * @details 
*/
#ifndef VIDEO_H
#define VIDEO_H

#include <gtk/gtk.h>

#include "DecodeVideo.h"
#include "RemuxVideo.h"
#include "StreamVideo.h"

void SetData(GtkWidget *window, GtkWidget *VideoBox, char filepath[]);

#endif
