#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <gtk/gtk.h>
#include <libavcodec/avcodec.h>

#include <libavutil/opt.h>
#include <libavutil/imgutils.h>

#include <libavformat/avformat.h>

#include <libswresample/swresample.h>


static void FileChooser(){
  GtkWidget *fc_dialog;
  GtkFileChooser *fc;
  char *filename;

  fc_dialog = gtk_file_chooser_dialog_new("Title", NULL, GTK_FILE_CHOOSER_ACTION_OPEN, "Abort", GTK_RESPONSE_CANCEL, "Open", GTK_RESPONSE_ACCEPT, NULL);

  gtk_widget_show(fc_dialog);
  
  if(gtk_dialog_run(GTK_DIALOG(fc_dialog)) == GTK_RESPONSE_ACCEPT){
     fc = GTK_FILE_CHOOSER(fc_dialog);
     filename = gtk_file_chooser_get_filename(fc);
     g_print("%s", filename);
     g_free (filename);
     gtk_widget_destroy(fc_dialog);}
  else{
     gtk_widget_destroy(fc_dialog);
  }
}

int main (int argc,char **argv){
  
  GtkWidget *MainWindow;
  
  GtkWidget *Tool_Bar_Box;

  GtkWidget *Menubar;
  GtkWidget *FileMenu, *EditMenu, *ClipMenu, *SequenceMenu, *GraphicsMenu, *ViewMenu, *WindowMenu, *HelpMenu;
  
  GtkWidget *FileMi, *EditMi, *ClipMi, *SequenceMi, *GraphicsMi, *ViewMi, *WindowMi, *HelpMi;

  GtkWidget *QuitMi, *ImportMi; //File Menu Items

  gtk_init(&argc, &argv);
  /*The gtk_init function initializes GTK+ and parses some standard command line options. This function must be called before using any other GTK+ functions.*/

  MainWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  
  gtk_window_set_title(GTK_WINDOW (MainWindow), "Video Editor"); // Set Screen Title
  gtk_window_maximize(GTK_WINDOW(MainWindow));   //maximize screen
  
  Tool_Bar_Box = gtk_box_new(GTK_ORIENTATION_VERTICAL,10); //Set the box Vertically ... 10 is used for padding

  gtk_container_add(GTK_CONTAINER(MainWindow), Tool_Bar_Box);

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
  
  g_signal_connect(MainWindow, "destroy", G_CALLBACK(gtk_main_quit), NULL);  
  
  gtk_widget_show_all(MainWindow); //Show Window
  
  gtk_main(); /*This code enters the GTK+ main loop. From this point, the application sits and waits for events to happen.*/

  return 0;
}


