#ifndef _WINDOW_H_
#define _WINDOW_H_


#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include <gtk/gtk.h>

typedef struct _Window{
	GtkWidget *MainWindow;
	GtkWidget *MainBox;
	GtkWidget *Tool_Bar_Box;
	GtkWidget *Menubar;
	GtkWidget *FileMenu, *EditMenu, *ClipMenu, *SequenceMenu, *GraphicsMenu, *ViewMenu, *WindowMenu, *HelpMenu;
	GtkWidget *FileMi, *EditMi, *ClipMi, *SequenceMi, *GraphicsMi, *ViewMi, *WindowMi, *HelpMi;
	GtkWidget *QuitMi, *ImportMi; //File Menu Items
}VideoPlayerWindow;

void activate (GtkApplication *app,gpointer user_data);

static void FileChooser();

#endif
