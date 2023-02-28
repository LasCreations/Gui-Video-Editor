#ifndef WINDOW_H
#define WINDOW_H

#include "Widget.h"

void Destroy(GtkWidget*,gpointer);

void Construct(Widget*);

void Create(int,char**);

void FileChooser();

#endif
