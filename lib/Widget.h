#ifndef WIDGET_H
#define WIDGET_H

#include <gtk/gtk.h>
#include <stdlib.h>

typedef struct Widget{
	GtkWidget *base;
	gint min_heigth;
	gint min_width;
	gint max_height;
	gint max_width;
}Widget;


#endif
