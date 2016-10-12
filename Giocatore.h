#ifndef GIOCATORE_H
#define GIOCATORE_H
#include <iostream>
#include <cstring>

class Giocatore {
	protected:
		char nome [20];
		int id;
		int x;  // pos x attuale
		int y;  // pos y attuale
		bool w;
	public:

		// Costruttore
		Giocatore (int id);

		// Set
		void setX (int x);
		void setY (int y);

		// Get
		int getX ();
		int getY ();
};

#endif
