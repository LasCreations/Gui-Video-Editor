#include "../include/Window.h"

int main(int argc, char **argv){
	gtk_init(&argc, &argv);
	gst_init (&argc, &argv);
	Create(argc, argv); //Call To Create Window Function Upon Start up
	return 0;
}
