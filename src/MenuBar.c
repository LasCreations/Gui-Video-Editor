
#include "../include/MenuBar.h"

void AddMenuBar(GtkWidget *MainBox, GtkWidget *MainWindow){
	MenuBar *menubar;

	menubar->MenuBarBox = gtk_box_new(GTK_ORIENTATION_VERTICAL,1); 

	gtk_box_pack_start(GTK_BOX(MainBox),menubar->MenuBarBox, FALSE, FALSE, 0);

	menubar->MenuBar = gtk_menu_bar_new();
	//Menu
  	menubar->FileMenu = gtk_menu_new();
  	menubar->EditMenu = gtk_menu_new();
  	menubar->ClipMenu = gtk_menu_new();
  	menubar->SequenceMenu = gtk_menu_new();
  	menubar->GraphicsMenu = gtk_menu_new();
  	menubar->ViewMenu = gtk_menu_new();
  	menubar->WindowMenu = gtk_menu_new();
  	menubar->HelpMenu = gtk_menu_new();

  	//Menu Titles
  	menubar->FileMi = gtk_menu_item_new_with_label("File");
  	menubar->EditMi = gtk_menu_item_new_with_label("Edit");
  	menubar->ClipMi = gtk_menu_item_new_with_label("Clip");
  	menubar->SequenceMi = gtk_menu_item_new_with_label("Sequence");
  	menubar->GraphicsMi = gtk_menu_item_new_with_label("Graphics");
  	menubar->ViewMi = gtk_menu_item_new_with_label("View");
  	menubar->WindowMi = gtk_menu_item_new_with_label("Window");
  	menubar->HelpMi = gtk_menu_item_new_with_label("Help");

  	//Submenu
  	menubar->QuitMi = gtk_menu_item_new_with_label("Exit");
	menubar->ImportMi = gtk_menu_item_new_with_label("Import");
 	menubar->ExportMi = gtk_menu_item_new_with_label("Export");
  	menubar->SaveMi = gtk_menu_item_new_with_label("Save");
  	menubar->SaveAsMi = gtk_menu_item_new_with_label("Save As");
  	menubar->NewMi = gtk_menu_item_new_with_label("New");

  	//Attach Menu label to the Menu 
  	gtk_menu_item_set_submenu(GTK_MENU_ITEM(menubar->FileMi),menubar->FileMenu);
  	gtk_menu_item_set_submenu(GTK_MENU_ITEM(menubar->EditMi),menubar->EditMenu);
  	gtk_menu_item_set_submenu(GTK_MENU_ITEM(menubar->ClipMi),menubar->ClipMenu);
  	gtk_menu_item_set_submenu(GTK_MENU_ITEM(menubar->SequenceMi),menubar->SequenceMenu);
  	gtk_menu_item_set_submenu(GTK_MENU_ITEM(menubar->GraphicsMi),menubar->GraphicsMenu);
  	gtk_menu_item_set_submenu(GTK_MENU_ITEM(menubar->ViewMi),menubar->ViewMenu);
  	gtk_menu_item_set_submenu(GTK_MENU_ITEM(menubar->WindowMi),menubar->WindowMenu);
  	gtk_menu_item_set_submenu(GTK_MENU_ITEM(menubar->HelpMi),menubar->HelpMenu);

  	//Attach Menu items
  	gtk_menu_shell_append(GTK_MENU_SHELL(menubar->FileMenu),menubar->NewMi);
  	gtk_menu_shell_append(GTK_MENU_SHELL(menubar->FileMenu),menubar->SaveMi);
  	gtk_menu_shell_append(GTK_MENU_SHELL(menubar->FileMenu),menubar->SaveAsMi);
  	gtk_menu_shell_append(GTK_MENU_SHELL(menubar->FileMenu),menubar->ImportMi);
  	gtk_menu_shell_append(GTK_MENU_SHELL(menubar->FileMenu),menubar->ExportMi);
  	gtk_menu_shell_append(GTK_MENU_SHELL(menubar->FileMenu),menubar->QuitMi);
	
  	//Attach to Menu bar
  	gtk_menu_shell_append(GTK_MENU_SHELL(menubar->MenuBar),menubar->FileMi);
  	gtk_menu_shell_append(GTK_MENU_SHELL(menubar->MenuBar),menubar->EditMi);
  	gtk_menu_shell_append(GTK_MENU_SHELL(menubar->MenuBar),menubar->ClipMi);
  	gtk_menu_shell_append(GTK_MENU_SHELL(menubar->MenuBar),menubar->SequenceMi);
  	gtk_menu_shell_append(GTK_MENU_SHELL(menubar->MenuBar),menubar->GraphicsMi);
  	gtk_menu_shell_append(GTK_MENU_SHELL(menubar->MenuBar),menubar->ViewMi);
  	gtk_menu_shell_append(GTK_MENU_SHELL(menubar->MenuBar),menubar->WindowMi);
  	gtk_menu_shell_append(GTK_MENU_SHELL(menubar->MenuBar),menubar->HelpMi);
  	
	gtk_box_pack_start(GTK_BOX(menubar->MenuBarBox),menubar->MenuBar, FALSE, FALSE, 0);

  	//Onclick Quit 
	//g_signal_connect_swapped (G_OBJECT(menubar->QuitMi), "activate", G_CALLBACK (gtk_widget_destroy), menubar->MainWindow);
	
	char *filepath = NULL;
  	g_signal_connect(G_OBJECT(menubar->ImportMi), "activate", G_CALLBACK(GetFilePath), filepath);
  	g_signal_connect(G_OBJECT(menubar->SaveAsMi), "activate", G_CALLBACK(ActivateSaveDialog), NULL);
	
	if(filepath!=NULL)
		g_print(filepath);
		
  	//g_signal_connect(G_OBJECT(menubar->ImportMi), "activate", G_CALLBACK(GetFilePath), NULL);
  	//g_signal_connect(G_OBJECT(menubar->NewMi), "activate", G_CALLBACK(NewProject), menubar);

}
