/*:
 * @file Window.c
 * @author Lascelle Mckenzie
 * @details 
*/

#include "../include/Window.h"

void Destroy(GtkWidget *widget, gpointer data){
	gtk_main_quit();
}

void Create(int argc, char **argv){

	
	WindowData *window = malloc(sizeof(struct WindowData));

	/* Initialize GTK */
	gtk_init(&argc, &argv);

	/* Initialize GStreamer */
	gst_init(&argc, &argv);

	window->MainWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);

	gtk_window_set_title(GTK_WINDOW(window->MainWindow), "Video-Editor");

	gtk_window_maximize(GTK_WINDOW(window->MainWindow));

	Construct(window);
	
	/* Connect the main window to the destroy */
	g_signal_connect(G_OBJECT(window->MainWindow), "destroy", G_CALLBACK(Destroy), NULL);

	gtk_widget_show_all(window->MainWindow);
	
	gtk_main();
}

void Construct(WindowData *window){
		
	//Making Boxes to store information
	window->Tool_Bar_Box = gtk_box_new(GTK_ORIENTATION_VERTICAL,10); //Set the box Vertically ... 10 is used for padding
	window->MainBox= gtk_box_new(GTK_ORIENTATION_VERTICAL,10); //Set the box Vertically ... 10 is used for padding
	
	
	//Add Container to Screen
	gtk_container_add(GTK_CONTAINER(window->MainWindow), window->MainBox);
	
	//Add Tool Bar
	gtk_box_pack_start(GTK_BOX(window->MainBox), window->Tool_Bar_Box, FALSE, FALSE, 0);	

	window->Menubar = gtk_menu_bar_new();

	//Menu
  	window->FileMenu = gtk_menu_new();
  	window->EditMenu = gtk_menu_new();
  	window->ClipMenu = gtk_menu_new();
  	window->SequenceMenu = gtk_menu_new();
  	window->GraphicsMenu = gtk_menu_new();
  	window->ViewMenu = gtk_menu_new();
  	window->WindowMenu = gtk_menu_new();
  	window->HelpMenu = gtk_menu_new();

  	//Menu Titles
  	window->FileMi = gtk_menu_item_new_with_label("File");
  	window->EditMi = gtk_menu_item_new_with_label("Edit");
  	window->ClipMi = gtk_menu_item_new_with_label("Clip");
  	window->SequenceMi = gtk_menu_item_new_with_label("Sequence");
  	window->GraphicsMi = gtk_menu_item_new_with_label("Graphics");
  	window->ViewMi = gtk_menu_item_new_with_label("View");
  	window->WindowMi = gtk_menu_item_new_with_label("Window");
  	window->HelpMi = gtk_menu_item_new_with_label("Help");

  	//Submenu
  	window->QuitMi = gtk_menu_item_new_with_label("Exit");
  	window->ImportMi = gtk_menu_item_new_with_label("Import");
  	window->ExportMi = gtk_menu_item_new_with_label("Export");
  	window->SaveMi = gtk_menu_item_new_with_label("Save");
  	window->SaveAsMi = gtk_menu_item_new_with_label("Save As");
  	window->NewMi = gtk_menu_item_new_with_label("New");

  	//Attach Menu label to the Menu 
  	gtk_menu_item_set_submenu(GTK_MENU_ITEM(window->FileMi),window->FileMenu);
  	gtk_menu_item_set_submenu(GTK_MENU_ITEM(window->EditMi),window->EditMenu);
  	gtk_menu_item_set_submenu(GTK_MENU_ITEM(window->ClipMi),window->ClipMenu);
  	gtk_menu_item_set_submenu(GTK_MENU_ITEM(window->SequenceMi),window->SequenceMenu);
  	gtk_menu_item_set_submenu(GTK_MENU_ITEM(window->GraphicsMi),window->GraphicsMenu);
  	gtk_menu_item_set_submenu(GTK_MENU_ITEM(window->ViewMi),window->ViewMenu);
  	gtk_menu_item_set_submenu(GTK_MENU_ITEM(window->WindowMi),window->WindowMenu);
  	gtk_menu_item_set_submenu(GTK_MENU_ITEM(window->HelpMi),window->HelpMenu);

  	//Attach Menu items
  	gtk_menu_shell_append(GTK_MENU_SHELL(window->FileMenu),window->NewMi);
  	gtk_menu_shell_append(GTK_MENU_SHELL(window->FileMenu),window->SaveMi);
  	gtk_menu_shell_append(GTK_MENU_SHELL(window->FileMenu),window->SaveAsMi);
  	gtk_menu_shell_append(GTK_MENU_SHELL(window->FileMenu),window->ImportMi);
  	gtk_menu_shell_append(GTK_MENU_SHELL(window->FileMenu),window->ExportMi);
  	gtk_menu_shell_append(GTK_MENU_SHELL(window->FileMenu),window->QuitMi);
	
  	//Attach to Menu bar
  	gtk_menu_shell_append(GTK_MENU_SHELL(window->Menubar),window->FileMi);
  	gtk_menu_shell_append(GTK_MENU_SHELL(window->Menubar),window->EditMi);
  	gtk_menu_shell_append(GTK_MENU_SHELL(window->Menubar),window->ClipMi);
  	gtk_menu_shell_append(GTK_MENU_SHELL(window->Menubar),window->SequenceMi);
  	gtk_menu_shell_append(GTK_MENU_SHELL(window->Menubar),window->GraphicsMi);
  	gtk_menu_shell_append(GTK_MENU_SHELL(window->Menubar),window->ViewMi);
  	gtk_menu_shell_append(GTK_MENU_SHELL(window->Menubar),window->WindowMi);
  	gtk_menu_shell_append(GTK_MENU_SHELL(window->Menubar),window->HelpMi);
  	
	gtk_box_pack_start(GTK_BOX(window->Tool_Bar_Box),window->Menubar, FALSE, FALSE, 0);

  	//Onclick Quit 
	g_signal_connect_swapped (G_OBJECT(window->QuitMi), "activate", G_CALLBACK (gtk_widget_destroy), window->MainWindow);

  	//Onclick Import
  	g_signal_connect(G_OBJECT(window->ImportMi), "activate", G_CALLBACK(FileChooser), window);
  	g_signal_connect(G_OBJECT(window->NewMi), "activate", G_CALLBACK(NewProject), window);
}

void NewProject(GtkWidget *menuItem,WindowData *window){
	window->NewProjectBox = gtk_box_new(GTK_ORIENTATION_VERTICAL,10); 
	gtk_box_pack_start(GTK_BOX(window->MainBox), window->NewProjectBox, FALSE, FALSE, 0);	
	window->NewProjectButtonBox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,10);
	window->ProjectName =  gtk_entry_new();	
	window->Create = gtk_button_new_with_label("Create");
	window->Cancel = gtk_button_new_with_label("Cancel");

	gtk_box_pack_start(GTK_BOX(window->NewProjectBox), window->ProjectName, FALSE, FALSE, 0);	
	gtk_box_pack_start(GTK_BOX(window->NewProjectBox), window->NewProjectButtonBox, FALSE, FALSE, 0);	


	gtk_box_pack_start(GTK_BOX(window->NewProjectButtonBox), window->Create, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(window->NewProjectButtonBox), window->Cancel, FALSE, FALSE, 0);
	
	g_signal_connect(window->Create,"clicked",G_CALLBACK(create_button_clicked),window);
	g_signal_connect(window->Cancel,"clicked",G_CALLBACK(cancel_button_clicked),window);
	gtk_widget_show_all(window->NewProjectBox);
}


void cancel_button_clicked(GtkWidget *menuItem,WindowData *window){
	gtk_widget_destroy(window->NewProjectBox);
}

void create_button_clicked(GtkWidget *menuItem,WindowData *window){
	const gchar* FolderName = gtk_entry_get_text(GTK_ENTRY(window->ProjectName));
	char projectFolder[1000] ="../projects/"; 
	strcat(projectFolder,FolderName);

	//Check if error occured
	if(mkdir(projectFolder, S_IRWXU | S_IRWXG | S_IRWXO) == -1){
		//Error Creating folder
		perror("Error");
		if(errno == EEXIST){
			//Folder Already Exists
			//Make a default Folder
			g_print("Created a folder called Default Folder");
		}
	}
	gtk_widget_destroy(window->NewProjectBox);
}

void FileChooser(GtkWidget *menuItem,WindowData *window){
	GtkWidget *FileChooserDialog = gtk_file_chooser_dialog_new("Select A File", NULL, GTK_FILE_CHOOSER_ACTION_OPEN, 
							 "Abort", GTK_RESPONSE_CANCEL, "Open",GTK_RESPONSE_ACCEPT, NULL);
	GtkFileChooser *file_chooser;
	char uri[1000]="file://";
	char *filepath;
	gtk_widget_show(FileChooserDialog);
	if(gtk_dialog_run(GTK_DIALOG(FileChooserDialog)) == GTK_RESPONSE_ACCEPT){
		file_chooser = GTK_FILE_CHOOSER(FileChooserDialog);
		filepath = gtk_file_chooser_get_filename(file_chooser);
		gtk_widget_destroy(FileChooserDialog);
		strcat(uri,filepath);
		g_print("%s\n", uri);	
		VideoMain(window,uri);	
	}else{
	    gtk_widget_destroy(FileChooserDialog);
	}
}
