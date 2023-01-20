//Standard Library
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Gui Library
#include <gtk/gtk.h>

#include <libavcodec/avcodec.h>

#include <libavutil/opt.h>
#include <libavutil/imgutils.h>

#include <libavformat/avformat.h>

#include <libswresample/swresample.h>



static void activate (GtkApplication* app, gpointer user_data){
  
  GtkWidget *window;

  GtkWidget *vbox;
  GtkWidget *menubar;
  GtkWidget *fileMenu;
  GtkWidget *fileMi;
  GtkWidget *quitMi;


  window = gtk_application_window_new (app);

  gtk_window_set_title(GTK_WINDOW (window), "Video Editor"); // Set Screen Title
  gtk_window_maximize(GTK_WINDOW(window));   //maximize screen
  

  vbox = gtk_vbox_new(FALSE, 0);
  gtk_container_add(GTK_CONTAINER(window), vbox);

  menubar = gtk_menu_bar_new();
  fileMenu = gtk_menu_new();

  fileMi = gtk_menu_item_new_with_label("File");
  quitMi = gtk_menu_item_new_with_label("Quit");

  gtk_menu_item_set_submenu(GTK_MENU_ITEM(fileMi), fileMenu);
  gtk_menu_shell_append(GTK_MENU_SHELL(fileMenu), quitMi);
  gtk_menu_shell_append(GTK_MENU_SHELL(menubar), fileMi);
  gtk_box_pack_start(GTK_BOX(vbox), menubar, FALSE, FALSE, 0);

  gtk_widget_show_all (window);
}

int main (int argc,char **argv){
  
  GtkApplication *app;
  int status;
  
  app = gtk_application_new ("org.gtk.example", G_APPLICATION_DEFAULT_FLAGS);
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
  
  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref(app);
  
  return status;
}




