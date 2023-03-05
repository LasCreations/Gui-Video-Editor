
#ifndef TOOLBAR_H
#define TOOLBAR_H

 #include <gtk/gtk.h> 

#include <stdbool.h>

typedef struct Toolbar{
	GtkWidget *ToolBarBox;
	
	GtkWidget *toolbar;
	
	GtkToolItem *newTb;
	GtkToolItem *openTb;

	GtkToolItem *saveTb;
	GtkToolItem *sep;
	
	GtkToolItem *exitTb;

}Toolbar;

void AddToolBar(GtkWidget *MainBox, GtkWidget *MainWindow);
void on_prompt_clicked(GtkWidget *MainBox, gpointer user_data);
#endif

