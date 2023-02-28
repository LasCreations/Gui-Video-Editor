#include <gtk/gtk.h>

#include "../lib/Window.h"

int main(int argc, char **argv){
	
	Window *window = new Window;
	window->Create(argc, argv);	
	return 0;
}


