#ifndef VIDEO_H
#define VIDEO_H

#include "Widget.h"

/*The Video Function
 * Take the path of the video, The video screen and the window screen
*/
int VideoMain(WindowData *window, char *filepath);

/* This function is called when the GUI toolkit creates the physical window that will hold the video.
 * At this point we can retrieve its handler (which has a different meaning depending on the windowing system)
 * and pass it to GStreamer through the VideoOverlay interface. */
void realize_cb (GtkWidget *widget, CustomData *data);

/* This function is called when the PLAY button is clicked */
void play_cb (GtkButton *button, CustomData *data);

/* This function is called when the PAUSE button is clicked */
void pause_cb (GtkButton *button, CustomData *data);

/* This function is called when the STOP button is clicked */
void stop_cb (GtkButton *button, CustomData *data);

/* This function is called when the main window is closed */
void delete_event_cb (GtkWidget *widget, GdkEvent *event, CustomData *data);

/* This function is called everytime the video window needs to be redrawn (due to damage/exposure,
 * rescaling, etc). GStreamer takes care of this in the PAUSED and PLAYING states, otherwise,
 * we simply draw a black rectangle to avoid garbage showing up. */
gboolean draw_cb (GtkWidget *widget, cairo_t *cr, CustomData *data);

/* This function is called when the slider changes its position. We perform a seek to the
 * new position here. */
void slider_cb (GtkRange *range, CustomData *data);

/* This creates all the GTK+ widgets that compose our application, and registers the callbacks */
void create_ui (CustomData *data, WindowData *window);

/* This function is called periodically to refresh the GUI */
gboolean refresh_ui (CustomData *data);

/* This function is called when new metadata is discovered in the stream */
void tags_cb (GstElement *playbin, gint stream, CustomData *data);

/* This function is called when an error message is posted on the bus */
void error_cb (GstBus *bus, GstMessage *msg, CustomData *data);

/* This function is called when an End-Of-Stream message is posted on the bus.
 * We just set the pipeline to READY (which stops playback) */
void eos_cb (GstBus *bus, GstMessage *msg, CustomData *data);

/* This function is called when the pipeline changes states. We use it to
 * keep track of the current state. */
void state_changed_cb (GstBus *bus, GstMessage *msg, CustomData *data);

/* Extract metadata from all the streams and write it to the text widget in the GUI */
void analyze_streams (CustomData *data);

/* This function is called when an "application" message is posted on the bus.
 * Here we retrieve the message posted by the tags_cb callback */
void application_cb (GstBus *bus, GstMessage *msg, CustomData *data);

#endif
