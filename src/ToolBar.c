
#include "../include/Toolbar.h"

void AddToolBar(GtkWidget *MainBox, GtkWidget *MainWindow){
	Toolbar *TBar;

  	TBar->ToolBarBox = gtk_box_new(GTK_ORIENTATION_VERTICAL,10);
  	TBar->toolbar = gtk_toolbar_new(); 
  	gtk_toolbar_set_style(GTK_TOOLBAR(TBar->toolbar), GTK_TOOLBAR_ICONS);

	TBar->openTb = gtk_tool_button_new (gtk_image_new_from_icon_name("document-open", GTK_ICON_SIZE_SMALL_TOOLBAR), NULL);
	TBar->saveTb = gtk_tool_button_new (gtk_image_new_from_icon_name("document-save", GTK_ICON_SIZE_SMALL_TOOLBAR), NULL);
	TBar->undoTb = gtk_tool_button_new (gtk_image_new_from_icon_name("edit-undo", GTK_ICON_SIZE_SMALL_TOOLBAR), NULL);
	TBar->redoTb = gtk_tool_button_new (gtk_image_new_from_icon_name("edit-redo", GTK_ICON_SIZE_SMALL_TOOLBAR), NULL);

  	//TBar->newTb = gtk_tool_button_new (gtk_image_new_from_icon_name("window-new", GTK_ICON_SIZE_SMALL_TOOLBAR), NULL);
  	//gtk_tool_item_set_tooltip_markup (TBar->newTb, "Open another one of these windows");

  	gtk_toolbar_insert(GTK_TOOLBAR (TBar->toolbar), TBar->openTb, -1);
  	gtk_toolbar_insert(GTK_TOOLBAR (TBar->toolbar), TBar->saveTb, -1);
  	gtk_toolbar_insert(GTK_TOOLBAR (TBar->toolbar), TBar->undoTb, -1);
  	gtk_toolbar_insert(GTK_TOOLBAR (TBar->toolbar), TBar->redoTb, -1);

  	//TBar->sep = gtk_separator_tool_item_new();
  	//gtk_toolbar_insert(GTK_TOOLBAR(TBar->toolbar), TBar->sep, -1);


  	gtk_box_pack_start(GTK_BOX(TBar->ToolBarBox), TBar->toolbar, FALSE, FALSE, 5);
  	
	gtk_box_pack_start(GTK_BOX(MainBox), TBar->ToolBarBox, FALSE, FALSE, 5);

  	//g_signal_connect (TBar->newTb, "clicked", G_CALLBACK (on_prompt_clicked), MainWindow);
}

void on_prompt_clicked(GtkWidget *MainBox, gpointer user_data){	
  	gtk_main_quit();
}
