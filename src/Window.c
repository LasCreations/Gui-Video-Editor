#include "../lib/Window.h"
Window window;


static void FileChooser(){
  GtkWidget *FileChooserDialog = gtk_file_chooser_dialog_new("Select A File", NULL, GTK_FILE_CHOOSER_ACTION_OPEN, 
                                                             "Abort", GTK_RESPONSE_CANCEL, "Open",
                                                             GTK_RESPONSE_ACCEPT, NULL);
  
  GtkFileChooser *file_chooser;
  char *filepath;
  char uri[] = "file:";

  gtk_widget_show(FileChooserDialog);
  
  if(gtk_dialog_run(GTK_DIALOG(FileChooserDialog)) == GTK_RESPONSE_ACCEPT){
     file_chooser = GTK_FILE_CHOOSER(FileChooserDialog);
     filepath = gtk_file_chooser_get_filename(file_chooser);
     //strcat(uri,filepath);
	//VideoPlayerData(uri);
     //g_print("%s", filepath);
     g_free (filepath);
     gtk_widget_destroy(FileChooserDialog);
  } else{
     gtk_widget_destroy(FileChooserDialog);
  }
}


void activate (GtkApplication* app,gpointer user_data){
	
	window.MainWindow = gtk_application_window_new (app);
  	
	gtk_window_set_title (GTK_WINDOW (window.MainWindow), "Video-Editor");
  	
	gtk_window_maximize(GTK_WINDOW(window.MainWindow));

	
	window.Tool_Bar_Box = gtk_box_new(GTK_ORIENTATION_VERTICAL,10); //Set the box Vertically ... 10 is used for padding
  
	window.MainBox = gtk_box_new(GTK_ORIENTATION_VERTICAL,10); //Set the box Vertically ... 10 is used for padding

	gtk_container_add(GTK_CONTAINER(window.MainWindow), window.MainBox);
  	
	gtk_box_pack_start(GTK_BOX(window.MainBox), window.Tool_Bar_Box, FALSE, FALSE, 0);
	
	window.Menubar = gtk_menu_bar_new();
  
 	 //Menu
  	window.FileMenu = gtk_menu_new();
  	window.EditMenu = gtk_menu_new();
  	window.ClipMenu = gtk_menu_new();
  	window.SequenceMenu = gtk_menu_new();
  	window.GraphicsMenu = gtk_menu_new();
  	window.ViewMenu = gtk_menu_new();
  	window.WindowMenu = gtk_menu_new();
  	window.HelpMenu = gtk_menu_new();

  	//Menu Titles
  	window.FileMi = gtk_menu_item_new_with_label("File");
  	window.EditMi = gtk_menu_item_new_with_label("Edit");
  	window.ClipMi = gtk_menu_item_new_with_label("Clip");
  	window.SequenceMi = gtk_menu_item_new_with_label("Sequence");
  	window.GraphicsMi = gtk_menu_item_new_with_label("Graphics");
  	window.ViewMi = gtk_menu_item_new_with_label("View");
  	window.WindowMi = gtk_menu_item_new_with_label("Window");
  	window.HelpMi = gtk_menu_item_new_with_label("Help");

  	//Submenu
  	window.QuitMi = gtk_menu_item_new_with_label("Quit");
  	window.ImportMi = gtk_menu_item_new_with_label("Import");

  	//Attach Menu label to the Menu 
  	gtk_menu_item_set_submenu(GTK_MENU_ITEM(window.FileMi), window.FileMenu);
  	gtk_menu_item_set_submenu(GTK_MENU_ITEM(window.EditMi), window.EditMenu);
  	gtk_menu_item_set_submenu(GTK_MENU_ITEM(window.ClipMi), window.ClipMenu);
  	gtk_menu_item_set_submenu(GTK_MENU_ITEM(window.SequenceMi), window.SequenceMenu);
  	gtk_menu_item_set_submenu(GTK_MENU_ITEM(window.GraphicsMi), window.GraphicsMenu);
  	gtk_menu_item_set_submenu(GTK_MENU_ITEM(window.ViewMi), window.ViewMenu);
  	gtk_menu_item_set_submenu(GTK_MENU_ITEM(window.WindowMi), window.WindowMenu);
  	gtk_menu_item_set_submenu(GTK_MENU_ITEM(window.HelpMi), window.HelpMenu);

  	//Attach Menu items
  	gtk_menu_shell_append(GTK_MENU_SHELL(window.FileMenu), window.ImportMi);
  	gtk_menu_shell_append(GTK_MENU_SHELL(window.FileMenu), window.QuitMi);
	
  	//Attach to Menu bar
  	gtk_menu_shell_append(GTK_MENU_SHELL(window.Menubar), window.FileMi);
  	gtk_menu_shell_append(GTK_MENU_SHELL(window.Menubar), window.EditMi);
  	gtk_menu_shell_append(GTK_MENU_SHELL(window.Menubar), window.ClipMi);
  	gtk_menu_shell_append(GTK_MENU_SHELL(window.Menubar), window.SequenceMi);
  	gtk_menu_shell_append(GTK_MENU_SHELL(window.Menubar), window.GraphicsMi);
  	gtk_menu_shell_append(GTK_MENU_SHELL(window.Menubar), window.ViewMi);
  	gtk_menu_shell_append(GTK_MENU_SHELL(window.Menubar), window.WindowMi);
  	gtk_menu_shell_append(GTK_MENU_SHELL(window.Menubar), window.HelpMi);
  	
  	gtk_box_pack_start(GTK_BOX(window.Tool_Bar_Box), window.Menubar, FALSE, FALSE, 0);

  	//Onclick Quit 
	g_signal_connect_swapped (G_OBJECT(window.QuitMi), "activate", G_CALLBACK (gtk_widget_destroy), window.MainWindow);

  	//Onclick Import
  	g_signal_connect(G_OBJECT(window.ImportMi), "activate", G_CALLBACK(FileChooser), NULL);
	
	gtk_widget_show_all (window.MainWindow);	
}

int main(int argc, char **argv){
	
	GtkApplication *app;
	
	int status;

  	app = gtk_application_new ("org.gtk.example",G_APPLICATION_DEFAULT_FLAGS);
  	
	g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
  	
	status = g_application_run (G_APPLICATION (app), argc, argv);
  	
	g_object_unref (app);

  	return status;
}

