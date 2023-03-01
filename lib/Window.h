#ifndef WINDOW_H
#define WINDOW_H


#include "../lib/Widget.h"
#include "../lib/Video.h"

void Destroy(GtkWidget*,gpointer);

void Construct(WindowData*);

void Create(int,char**);

void FileChooser(GtkWidget*, WindowData*);

#endif
