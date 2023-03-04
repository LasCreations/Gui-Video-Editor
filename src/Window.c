#include "../include/Window.h"

void Destroy(GtkWidget *widget, gpointer data){
	gtk_main_quit();
}

void Create(int argc, char **argv){
	gtk_init(&argc, &argv);
	
	GtkWidget *MainWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	
	GtkWidget *MainBox = gtk_box_new(GTK_ORIENTATION_VERTICAL,10);

	gtk_window_set_title(GTK_WINDOW(MainWindow), "Video-Editor");
	gtk_window_maximize(GTK_WINDOW(MainWindow));

	const gchar *authors[] = {"ad Chi", NULL};
	gtk_show_about_dialog(GTK_WINDOW(MainWindow),
                    "program-name", "jjkjk",
                    "version", "0.0.1",
                    "copyright", "(C) 2017 ad Chi",
                    "license-type", GTK_LICENSE_GPL_3_0,
                    "website", "https://github.com/kjk",
                    "comments", "Totally kj",
                    "authors", authors,
                    "documenters", NULL,
                    "logo-icon-name", "start-here",
                    "title", "About kj kj",
                    NULL);

	gtk_container_add(GTK_CONTAINER(MainWindow),MainBox);

	AddMenuBar(MainBox, MainWindow);
	
	AddToolBar(MainBox, MainWindow);

	g_signal_connect(G_OBJECT(MainWindow), "destroy", G_CALLBACK(Destroy), NULL);

	gtk_widget_show_all(MainWindow);
	
	gtk_main();
}
