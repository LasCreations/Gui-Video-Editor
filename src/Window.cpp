/*:
 * @file Window.c
 * @author Lascelle Mckenzie
 * @details 
*/


#include "../lib/Window.h"

void Window::activate(GtkApplication *app, gpointer user_data){
	GtkWidget *MainWindow = gtk_application_window_new (app);
  	
	gtk_window_set_title (GTK_WINDOW (MainWindow), "Video-Editor");
  	
	gtk_window_maximize(GTK_WINDOW(MainWindow));

	gtk_widget_show_all (MainWindow);
}

int Window::Create(int argc, char **argv){

	/* Initialize GStreamer */
	//gst_init (&argc, &argv);
 
	/* Initialize GTK */
	gtk_init (&argc, &argv);

	GtkApplication *app;
	
	int status;

  	app = gtk_application_new ("org.gtk.example",G_APPLICATION_DEFAULT_FLAGS);
  	
	g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
  	
	status = g_application_run (G_APPLICATION (app), argc, argv);
  	
	g_object_unref (app);
	
	return status;
}


