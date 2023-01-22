#include "window.h"

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


typedef struct _CustomData {
  GstElement *playbin;           /* Our one and only pipeline */
  GtkWidget *slider;              /* Slider widget to keep track of current position */
  GtkWidget *streams_list;        /* Text widget to display info about the streams */
  gulong slider_update_signal_id; /* Signal ID for the slider update signal */
  GstState state;                 /* Current state of the pipeline */
  gint64 duration;                /* Duration of the clip, in nanoseconds */
} CustomData;

static void realize_cb (GtkWidget *widget, CustomData *data);
static void play_cb (GtkButton *button, CustomData *data);
static void pause_cb (GtkButton *button, CustomData *data);
static void stop_cb (GtkButton *button, CustomData *data);
static void delete_event_cb (GtkWidget *widget, GdkEvent *event, CustomData *data);
static gboolean draw_cb (GtkWidget *widget, cairo_t *cr, CustomData *data);
static void slider_cb (GtkRange *range, CustomData *data);
static void create_ui (CustomData *data);
static gboolean refresh_ui (CustomData *data);
static void tags_cb (GstElement *playbin, gint stream, CustomData *data);
static void error_cb (GstBus *bus, GstMessage *msg, CustomData *data);
static void eos_cb (GstBus *bus, GstMessage *msg, CustomData *data);
static void state_changed_cb (GstBus *bus, GstMessage *msg, CustomData *data);
static void analyze_streams (CustomData *data);
static void application_cb (GstBus *bus, GstMessage *msg, CustomData *data);
static int VideoPlayerData(char path[]);

