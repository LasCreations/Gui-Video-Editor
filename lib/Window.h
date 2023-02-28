#ifndef WINDOW_H
#define WINDOW_H

#include <gtk/gtk.h>
#include <stdio.h>

class Window{
	private:

	public:
		Window(){
			
		}
		
		void activate(GtkApplication* app,gpointer user_data);
		int Create(int argc, char **argv);
};

#endif
