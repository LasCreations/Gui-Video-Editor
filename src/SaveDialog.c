

#include "../include/SaveDialog.h"

void ActivateSaveDialog(GtkWidget *window, gpointer user_data){
	GtkWidget *FileChooserDialog = gtk_file_chooser_dialog_new("Save File", NULL, GTK_FILE_CHOOSER_ACTION_SAVE, "Cancel",
							    GTK_RESPONSE_CANCEL, "Save",GTK_RESPONSE_ACCEPT, NULL);


	GtkFileChooser *chooser = GTK_FILE_CHOOSER (FileChooserDialog);
	
	if (gtk_dialog_run (GTK_DIALOG (FileChooserDialog)) == GTK_RESPONSE_ACCEPT){
		char *filename;
		filename = gtk_file_chooser_get_filename (chooser);
		g_print(filename);
		g_free (filename);
	}
	gtk_widget_destroy (FileChooserDialog);

}
