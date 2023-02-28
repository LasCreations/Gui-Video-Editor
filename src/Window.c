/*:
 * @file Window.c
 * @author Lascelle Mckenzie
 * @details 
*/

#include "../lib/Window.h"


void Destroy(GtkWidget *widget, gpointer data){
    gtk_main_quit();
}

void Create(int argc, char **argv){
	
	Widget *test = malloc(sizeof(struct Widget)); 
	
	gtk_init(&argc, &argv);
	
	test->base = gtk_window_new(GTK_WINDOW_TOPLEVEL);

	gtk_window_set_title(GTK_WINDOW(test->base), "Hello World!");

	gtk_window_maximize(GTK_WINDOW(test->base));
	
	Construct(test);
	
	/* Connect the main window to the destroy */
	g_signal_connect(G_OBJECT(test->base), "destroy", G_CALLBACK(Destroy), NULL);

	gtk_widget_show_all(test->base);
	
	gtk_main();
}

void Construct(Widget *test){
	Widget *MainWindow = malloc(sizeof(struct Widget));
	Widget *MainBox= malloc(sizeof(struct Widget));
	Widget *Tool_Bar_Box= malloc(sizeof(struct Widget));
	Widget *Menubar= malloc(sizeof(struct Widget));
	Widget *FileMenu= malloc(sizeof(struct Widget));
	Widget *EditMenu= malloc(sizeof(struct Widget));
	Widget *ClipMenu= malloc(sizeof(struct Widget));
	Widget *SequenceMenu= malloc(sizeof(struct Widget));
	Widget *GraphicsMenu= malloc(sizeof(struct Widget));
	Widget *ViewMenu= malloc(sizeof(struct Widget));
	Widget *WindowMenu= malloc(sizeof(struct Widget));
	Widget *HelpMenu= malloc(sizeof(struct Widget));
	Widget *FileMi= malloc(sizeof(struct Widget));
	Widget *EditMi= malloc(sizeof(struct Widget));
	Widget *ClipMi= malloc(sizeof(struct Widget));
	Widget *SequenceMi= malloc(sizeof(struct Widget));
	Widget *GraphicsMi= malloc(sizeof(struct Widget));
	Widget *ViewMi= malloc(sizeof(struct Widget));
	Widget *WindowMi= malloc(sizeof(struct Widget));
	Widget *HelpMi= malloc(sizeof(struct Widget));
	Widget *QuitMi= malloc(sizeof(struct Widget));
	Widget *ImportMi = malloc(sizeof(struct Widget));

  	
	
	Tool_Bar_Box->base = gtk_box_new(GTK_ORIENTATION_VERTICAL,10); //Set the box Vertically ... 10 is used for padding
	MainBox->base= gtk_box_new(GTK_ORIENTATION_VERTICAL,10); //Set the box Vertically ... 10 is used for padding
	gtk_container_add(GTK_CONTAINER(test->base), MainBox->base);
	gtk_box_pack_start(GTK_BOX(MainBox->base), Tool_Bar_Box->base, FALSE, FALSE, 0);	
	Menubar->base = gtk_menu_bar_new();

	//Menu
  	FileMenu->base = gtk_menu_new();
  	EditMenu->base = gtk_menu_new();
  	ClipMenu->base = gtk_menu_new();
  	SequenceMenu->base = gtk_menu_new();
  	GraphicsMenu->base = gtk_menu_new();
  	ViewMenu->base = gtk_menu_new();
  	WindowMenu->base = gtk_menu_new();
  	HelpMenu->base = gtk_menu_new();

  	//Menu Titles
  	FileMi->base = gtk_menu_item_new_with_label("File");
  	EditMi->base = gtk_menu_item_new_with_label("Edit");
  	ClipMi->base = gtk_menu_item_new_with_label("Clip");
  	SequenceMi->base = gtk_menu_item_new_with_label("Sequence");
  	GraphicsMi->base = gtk_menu_item_new_with_label("Graphics");
  	ViewMi->base = gtk_menu_item_new_with_label("View");
  	WindowMi->base = gtk_menu_item_new_with_label("Window");
  	HelpMi->base = gtk_menu_item_new_with_label("Help");

  	//Submenu
  	QuitMi->base = gtk_menu_item_new_with_label("Quit");
  	ImportMi->base = gtk_menu_item_new_with_label("Import");

  	//Attach Menu label to the Menu 
  	gtk_menu_item_set_submenu(GTK_MENU_ITEM(FileMi->base),FileMenu->base);
  	gtk_menu_item_set_submenu(GTK_MENU_ITEM(EditMi->base),EditMenu->base);
  	gtk_menu_item_set_submenu(GTK_MENU_ITEM(ClipMi->base),ClipMenu->base);
  	gtk_menu_item_set_submenu(GTK_MENU_ITEM(SequenceMi->base),SequenceMenu->base);
  	gtk_menu_item_set_submenu(GTK_MENU_ITEM(GraphicsMi->base),GraphicsMenu->base);
  	gtk_menu_item_set_submenu(GTK_MENU_ITEM(ViewMi->base),ViewMenu->base);
  	gtk_menu_item_set_submenu(GTK_MENU_ITEM(WindowMi->base),WindowMenu->base);
  	gtk_menu_item_set_submenu(GTK_MENU_ITEM(HelpMi->base),HelpMenu->base);

  	//Attach Menu items
  	gtk_menu_shell_append(GTK_MENU_SHELL(FileMenu->base),ImportMi->base);
  	gtk_menu_shell_append(GTK_MENU_SHELL(FileMenu->base),QuitMi->base);
	
  	//Attach to Menu bar
  	gtk_menu_shell_append(GTK_MENU_SHELL(Menubar->base),FileMi->base);
  	gtk_menu_shell_append(GTK_MENU_SHELL(Menubar->base),EditMi->base);
  	gtk_menu_shell_append(GTK_MENU_SHELL(Menubar->base),ClipMi->base);
  	gtk_menu_shell_append(GTK_MENU_SHELL(Menubar->base),SequenceMi->base);
  	gtk_menu_shell_append(GTK_MENU_SHELL(Menubar->base),GraphicsMi->base);
  	gtk_menu_shell_append(GTK_MENU_SHELL(Menubar->base),ViewMi->base);
  	gtk_menu_shell_append(GTK_MENU_SHELL(Menubar->base),WindowMi->base);
  	gtk_menu_shell_append(GTK_MENU_SHELL(Menubar->base),HelpMi->base);
  	
  	gtk_box_pack_start(GTK_BOX(Tool_Bar_Box->base),Menubar->base, FALSE, FALSE, 0);

  	//Onclick Quit 
	g_signal_connect_swapped (G_OBJECT(QuitMi->base), "activate", G_CALLBACK (gtk_widget_destroy), test->base);

  	//Onclick Import
  	g_signal_connect(G_OBJECT(ImportMi->base), "activate", G_CALLBACK(FileChooser), NULL);
}

void FileChooser(){
	Widget *FileChooserDialog = malloc(sizeof(struct Widget));

	FileChooserDialog->base	= gtk_file_chooser_dialog_new("Select A File", NULL, GTK_FILE_CHOOSER_ACTION_OPEN, 
                                                           "Abort", GTK_RESPONSE_CANCEL, "Open",
                                                             GTK_RESPONSE_ACCEPT, NULL);
	GtkFileChooser *file_chooser;
	char *filepath;
	char uri[1000] = "file:";
	gtk_widget_show(FileChooserDialog->base);
	if(gtk_dialog_run(GTK_DIALOG(FileChooserDialog->base)) == GTK_RESPONSE_ACCEPT){
		file_chooser = GTK_FILE_CHOOSER(FileChooserDialog->base);
		filepath = gtk_file_chooser_get_filename(file_chooser);
		strcat(uri,filepath);
		//VideoPlayerData(uri, &window);
		g_print("%s", filepath);
		g_free (filepath);
		gtk_widget_destroy(FileChooserDialog->base);
	} else{
		gtk_widget_destroy(FileChooserDialog->base);
	}
}
