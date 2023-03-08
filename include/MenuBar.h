/*:
 * @file MenuBar.h
 * @author Lascelle Mckenzie
 * @details 
*/

#ifndef MENUBAR_H
#define MENUBAR_H

#include <gtk/gtk.h>

#include "ImportDialog.h"
#include "SaveDialog.h"


#include <stdbool.h>
#include <stdio.h>

typedef struct MenuBar{
	GtkWidget *MenuBarBox; 	
	
	GtkWidget *MenuBar;  	
	
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

	//Under File Tab
	GtkWidget *QuitMi;  
	GtkWidget *ImportMi;
	GtkWidget *ExportMi;
	GtkWidget *SaveMi;
	GtkWidget *SaveAsMi;
	GtkWidget *NewMi;
}MenuBar;

void AddMenuBar(GtkWidget *MainBox, GtkWidget *MainWindow);

#endif
