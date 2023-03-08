#ifndef SAVE_DIALOG_H
#define SAVE_DIALOG_H

#include<gtk/gtk.h>


#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

//Error Functions
#include <errno.h>
#include <asm-generic/errno-base.h>                                                                                                                   

#include <string.h>
#include <stdlib.h>

extern int errno;

void ActivateSaveDialog(GtkWidget *window, gpointer user_data);


#endif
