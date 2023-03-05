
#include "../include/ImportDialog.h"

char *GetFilePath(GtkWidget *widget, gpointer user_data){
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
		user_data = filepath;
		return filepath;
		//VideoMain(window,uri);	
	}else{
	    gtk_widget_destroy(FileChooserDialog);
	}
}
