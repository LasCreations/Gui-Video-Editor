#ifndef WINDOW_H
#define WINDOW_H


#include "../include/Widget.h"
#include "../include/Video.h"

void Destroy(GtkWidget*,gpointer);

void Construct(WindowData*);

void Create(int,char**);

void FileChooser(GtkWidget*, WindowData*);

void NewProject(GtkWidget*, WindowData*);

void create_button_clicked(GtkWidget*, WindowData*);

void cancel_button_clicked(GtkWidget*, WindowData*);


#endif
