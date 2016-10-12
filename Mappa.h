#ifndef MAPPA_H
#define MAPPA_H
#include "Giocatore.h"

struct nodo {
	int x;
	int y;
	nodo* nord;
	nodo* sud;
	nodo* est;
	nodo* ovest;
};

struct controllo {
	int x;
	int y;
	nodo* nodo; // nodo di coordinate (x,y)
	controllo* next;
};

typedef nodo* ptr_nodo;
typedef controllo* ptr_control;

class Mappa {
	protected:
		int numeroNodi; // Totale nodi
		int numeroGiocatori; //Totale giocatori
		// Includere altri elementi GDR qui
	public:
		// Costruttore
		Mappa();

		// Metodi
		void incrementaNumeroNodi();

		// Setter
		void setPos(int x, int y);
		void setNord(Giocatore g, ptr_control control);
		void setSud(Giocatore g, ptr_control control);
		void setEst(Giocatore g, ptr_control control);
		void setOvest(Giocatore g, ptr_control control);
		ptr_nodo setMappa (int numeroGiocatori);
		ptr_control setControl (ptr_nodo head);

		// Getter
		ptr_nodo getNodoCorrente(Giocatore g, ptr_control control);
		int getX();
		int getY();
		ptr_nodo getNord();
		ptr_nodo getSud();
		ptr_nodo getEst();
		ptr_nodo getOvest();
		ptr_nodo getNodo();
};

#endif
