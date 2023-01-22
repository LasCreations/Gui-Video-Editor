#include "../lib/window.h"


void activate(int argc,char **argv){
	
	
	/* Initialize GTK */
	gtk_init (&argc, &argv);  
	
	MainWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);  
	MainBox = gtk_box_new(GTK_ORIENTATION_VERTICAL,10); //Set the box Vertically ... 10 is used for padding
	
	gtk_window_set_title(GTK_WINDOW (MainWindow), "Video Editor"); // Set Screen Title
	
	gtk_window_maximize(GTK_WINDOW(MainWindow));   //maximize screen 
	
	g_signal_connect(MainWindow, "destroy", G_CALLBACK(gtk_main_quit), NULL);
	
	addToolBar();

	gtk_widget_show_all(MainWindow); //Show Window

	gtk_main(); /*This code enters the GTK+ main loop. From this point, the application sits and waits for events to happen.*/ 
}

static void FileChooser(){
	GtkWidget *FileChooserDialog = gtk_file_chooser_dialog_new("Select A File", NULL, GTK_FILE_CHOOSER_ACTION_OPEN, 
                                                             "Abort", GTK_RESPONSE_CANCEL, "Open",
                                                             GTK_RESPONSE_ACCEPT, NULL);
  
	GtkFileChooser *file_chooser;
	
	char *filepath;
	//char uri[] = "file:";

	gtk_widget_show(FileChooserDialog);
  
	if(gtk_dialog_run(GTK_DIALOG(FileChooserDialog)) == GTK_RESPONSE_ACCEPT){
		file_chooser = GTK_FILE_CHOOSER(FileChooserDialog);
		filepath = gtk_file_chooser_get_filename(file_chooser);
		//strcat(uri,filepath);
		//VideoPlayerData(uri);
		g_print("%s", filepath);
		gtk_widget_destroy(FileChooserDialog);
		VideoPlayerData(filepath);
		g_free (filepath);
	} else{
		gtk_widget_destroy(FileChooserDialog);
	}
}

void addToolBar(){

	GtkWidget *Tool_Bar_Box;
	GtkWidget *Menubar;
	GtkWidget *FileMenu, *EditMenu, *ClipMenu, *SequenceMenu, *GraphicsMenu, *ViewMenu, *WindowMenu, *HelpMenu;
	GtkWidget *FileMi, *EditMi, *ClipMi, *SequenceMi, *GraphicsMi, *ViewMi, *WindowMi, *HelpMi;
	GtkWidget *QuitMi, *ImportMi; //File Menu Items

	Tool_Bar_Box = gtk_box_new(GTK_ORIENTATION_VERTICAL,10); //Set the box Vertically ... 10 is used for padding

	gtk_box_pack_start(GTK_BOX(MainBox), Tool_Bar_Box, FALSE, FALSE, 0);
	
	Menubar = gtk_menu_bar_new();
  
	//Menu
	FileMenu = gtk_menu_new();
	EditMenu = gtk_menu_new();
	ClipMenu = gtk_menu_new();
	SequenceMenu = gtk_menu_new();
	GraphicsMenu = gtk_menu_new();
	ViewMenu = gtk_menu_new();
	WindowMenu = gtk_menu_new();
	HelpMenu = gtk_menu_new();

	//Menu Titles
	FileMi = gtk_menu_item_new_with_label("File");
	EditMi = gtk_menu_item_new_with_label("Edit");
	ClipMi = gtk_menu_item_new_with_label("Clip");
	SequenceMi = gtk_menu_item_new_with_label("Sequence");
	GraphicsMi = gtk_menu_item_new_with_label("Graphics");
	ViewMi = gtk_menu_item_new_with_label("View");
	WindowMi = gtk_menu_item_new_with_label("Window");
	HelpMi = gtk_menu_item_new_with_label("Help");

	//Submenu
	QuitMi = gtk_menu_item_new_with_label("Quit");
	ImportMi = gtk_menu_item_new_with_label("Import");

	//Attach Menu label to the Menu 
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(FileMi), FileMenu);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(EditMi), EditMenu);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(ClipMi), ClipMenu);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(SequenceMi), SequenceMenu);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(GraphicsMi), GraphicsMenu);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(ViewMi), ViewMenu);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(WindowMi), WindowMenu);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(HelpMi), HelpMenu);

	//Attach Menu items
	gtk_menu_shell_append(GTK_MENU_SHELL(FileMenu), ImportMi);
	gtk_menu_shell_append(GTK_MENU_SHELL(FileMenu), QuitMi);

	//Attach to Menu bar
	gtk_menu_shell_append(GTK_MENU_SHELL(Menubar), FileMi);
	gtk_menu_shell_append(GTK_MENU_SHELL(Menubar), EditMi);
	gtk_menu_shell_append(GTK_MENU_SHELL(Menubar), ClipMi);
	gtk_menu_shell_append(GTK_MENU_SHELL(Menubar), SequenceMi);
	gtk_menu_shell_append(GTK_MENU_SHELL(Menubar), GraphicsMi);
	gtk_menu_shell_append(GTK_MENU_SHELL(Menubar), ViewMi);
	gtk_menu_shell_append(GTK_MENU_SHELL(Menubar), WindowMi);
	gtk_menu_shell_append(GTK_MENU_SHELL(Menubar), HelpMi);
  
	gtk_box_pack_start(GTK_BOX(Tool_Bar_Box), Menubar, FALSE, FALSE, 0);

	//Onclick Quit
	g_signal_connect(G_OBJECT(QuitMi), "activate", G_CALLBACK(gtk_main_quit), NULL);
  
	//Onclick Import
	g_signal_connect(G_OBJECT(ImportMi), "activate", G_CALLBACK(FileChooser), NULL);
  

	gtk_container_add(GTK_CONTAINER(MainWindow), MainBox);
}
