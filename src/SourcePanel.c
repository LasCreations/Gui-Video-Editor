#include "../include/SourcePanel.h"

void AddSourcePanel(GtkWidget *ProjectVideoBox, GtkWidget *window){
	GtkWidget *VideoBox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,1); 
	gtk_box_pack_start(GTK_BOX(ProjectVideoBox), VideoBox, FALSE, FALSE, 0);
	//VideoMain(window, VideoBox, "file:///home/lascelle/Videos/Sample2.mp4");
	SetData(window, VideoBox,"file:///home/lascelle/Videos/Sample2.mp4");
	//g_print("Hello");
}
