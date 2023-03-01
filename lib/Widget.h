#ifndef WIDGET_H
#define WIDGET_H


#include <gst/gst.h>
#include <gst/video/videooverlay.h>

#include <gdk/gdk.h>
#if defined (GDK_WINDOWING_X11)
#include <gdk/gdkx.h>
#elif defined (GDK_WINDOWING_WIN32)
#include <gdk/gdkwin32.h>
#elif defined (GDK_WINDOWING_QUARTZ)
#include <gdk/gdkquartz.h>
#endif

#include <gtk/gtk.h>

#include <string.h>
#include <stdlib.h>

typedef struct WindowData{
	GtkWidget *MainWindow; 
	GtkWidget *MainBox;
	GtkWidget *VideoBox;
	GtkWidget *Tool_Bar_Box; 	
	GtkWidget *Menubar;  	
	GtkWidget *FileMenu;   
	GtkWidget *EditMenu; 
	GtkWidget *ClipMenu; 
	GtkWidget *SequenceMenu;
	GtkWidget *GraphicsMenu;   
	GtkWidget *ViewMenu;   
	GtkWidget *WindowMenu;  
	GtkWidget *HelpMenu;   
	GtkWidget *FileMi;   
	GtkWidget *EditMi;   
	GtkWidget *ClipMi;   
	GtkWidget *SequenceMi; 
	GtkWidget *GraphicsMi; 
	GtkWidget *ViewMi;  
	GtkWidget *WindowMi;  
	GtkWidget *HelpMi;
	GtkWidget *QuitMi;  
	GtkWidget *ImportMi; 
}WindowData;

/* Structure to contain all our information, so we can pass it around */
typedef struct CustomData {
	GstElement *playbin;           /* Our one and only pipeline */
	GtkWidget *slider;              /* Slider widget to keep track of current position */
	GtkWidget *streams_list;        /* Text widget to display info about the streams */
	gulong slider_update_signal_id; /* Signal ID for the slider update signal */
	GstState state;                 /* Current state of the pipeline */
	gint64 duration;                /* Duration of the clip, in nanoseconds */
}CustomData;

#endif
