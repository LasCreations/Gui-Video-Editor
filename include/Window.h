/*
 * @file Window.h
 * @author Lascelle Mckenzie
 * @details File containing the definition and usage for Window API
*/


#ifndef WINDOW_H
#define WINDOW_H

#include <gtk/gtk.h>

#include "MenuBar.h"
#include "Toolbar.h"
#include "SourcePanel.h"

void Create();
void Destroy(GtkWidget*,gpointer);

#endif
