#include "Mappa.h"

nodo stanza;

controllo control;

Mappa::Mappa() {
	
}

void Mappa::setPos(int x, int y) {
	stanza.x = x;
	stanza.y = y;
}

void Mappa::incrementaNumeroNodi() {
	Mappa::numeroNodi++;
}

ptr_nodo Mappa::setMappa (int numeroGiocatori){
	ptr_nodo node = new nodo;
	node->x = 0;
	node->y = 0;
	node->est = NULL;
	node->ovest = NULL;
	node->nord = NULL;
	node->sud = NULL;
	return node;
}

ptr_control Mappa :: setControl (nodo* head) {
	ptr_control control = new controllo;
	control->x = 0;
	control->y = 0;
	control->nodo = head;
	return control;
}

nodo* Mappa::getNodoCorrente(Giocatore g, ptr_control control) {
	if (control != NULL) {
		if ((g.getX() == control->x) && (g.getY() == control->y)) {
			return control->nodo;
		}
		while (control->next != NULL) {
			control = control->next;
			if ((g.getX() == control->x) && (g.getY() == control->y)) {
				return control->nodo;
			}
		}
	}
	return NULL;
}

void Mappa::setNord(Giocatore g, ptr_control control) {
	bool trovato = false;
	nodo* corrente = NULL;
	corrente = getNodoCorrente(g, control);
	// Controllo, tramite la lista controllo, se il nodo a nord è già esistente
	if (control != NULL) {
		// Se è già esistente, lo collego a Nord del nodo corrente
		if (control->y == corrente->y + 1 && control->x == corrente->x) {
			corrente->nord = control->nodo;
			corrente->nord->sud = corrente;
		}
		// Scorro tutta la lista dei nodi già esistenti
		while ((control->next != NULL) && (!trovato)) {
			control = control->next;
			// Analogo al metodo sopra
			if (control->y == corrente->y + 1 && control->x == corrente->x) {
				corrente->nord = control->nodo;
				corrente->nord->sud = corrente;
				trovato = true;
				// Trovato, smetto di scorrere la lista
			}
		}
	}
	// Nodo non esistente, ne creo uno nuovo
	if (corrente->nord == NULL) {
		nodo* nuovo = NULL;
		corrente->nord = nuovo;
		nuovo->x = corrente->x;
		nuovo->y = corrente->y + 1;
		nuovo->sud = corrente;
		// Se la lista controllo è vuota
		if (control == NULL) {
			control = new controllo;
			control->nodo = nuovo;
			control->x = nuovo->x;
			control->y = nuovo->y;
		}
		else {
			// Scorro in fondo alla lista controllo per aggiornarla aggiungendo il nuovo nodo creato
			while (control->next != NULL) {
				control = control->next;
			}
			// Sono in coda
			control->next = new controllo;
			control->next->nodo = nuovo;
			control->next->x = nuovo->x;
			control->next->y = nuovo->y;
		}
		/*g.setY(g.getY() + 1);*/
	}
}

void Mappa::setSud(Giocatore g, ptr_control control) {
	bool trovato = false;
	ptr_nodo corrente = NULL;
	corrente = getNodoCorrente(g, control);
	// Controllo, tramite la lista controllo, se il nodo a nord è già esistente
	if (control != NULL) {
		// Se è già esistente, lo collego a Nord del nodo corrente
		if (control->y == corrente->y - 1 && control->x == corrente->x) {
			corrente->sud = control->nodo;
			corrente->sud->nord = corrente;
		}
		// Scorro tutta la lista dei nodi già esistenti
		while ((control->next != NULL) && (!trovato)) {
			control = control->next;
			// Analogo al metodo sopra
			if (control->y == corrente->y - 1 && control->x == corrente->x) {
				corrente->sud = control->nodo;
				corrente->sud->nord = corrente;
				trovato = true;
				// Trovato, smetto di scorrere la lista
			}
		}
	}
	// Nodo non esistente, ne creo uno nuovo
	if (corrente->sud == NULL) {
		ptr_nodo nuovo = NULL;
		corrente->sud = nuovo;
		nuovo->x = corrente->x;
		nuovo->y = corrente->y - 1;
		nuovo->sud = corrente;
		// Se la lista controllo è vuota
		if (control == NULL) {
			control = new controllo;
			control->nodo = nuovo;
			control->x = nuovo->x;
			control->y = nuovo->y;
		}
		else {
			// Scorro in fondo alla lista controllo per aggiornarla aggiungendo il nuovo nodo creato
			while (control->next != NULL) {
				control = control->next;
			}
			// Sono in coda
			control->next = new controllo;
			control->next->nodo = nuovo;
			control->next->x = nuovo->x;
			control->next->y = nuovo->y;
		}
		/*g.setY(g.getY() + 1);*/
	}
}

void Mappa::setEst(Giocatore g, ptr_control control) {
	bool trovato = false;
	ptr_nodo corrente = NULL;
	corrente = getNodoCorrente(g, control);
	// Controllo, tramite la lista controllo, se il nodo a nord è già esistente
	if (control != NULL) {
		// Se è già esistente, lo collego a Nord del nodo corrente
		if (control->y == corrente->y && control->x == corrente->x + 1) {
			corrente->est = control->nodo;
			corrente->est->ovest = corrente;
		}
		// Scorro tutta la lista dei nodi già esistenti
		while ((control->next != NULL) && (!trovato)) {
			control = control->next;
			// Analogo al metodo sopra
			if (control->y == corrente->y && control->x == corrente->x + 1) {
				corrente->est = control->nodo;
				corrente->est->ovest = corrente;
				trovato = true;
				// Trovato, smetto di scorrere la lista
			}
		}
	}
	// Nodo non esistente, ne creo uno nuovo
	if (corrente->est == NULL) {
		ptr_nodo nuovo = NULL;
		corrente->est = nuovo;
		nuovo->x = corrente->x + 1;
		nuovo->y = corrente->y;
		nuovo->est = corrente;
		// Se la lista controllo è vuota
		if (control == NULL) {
			control = new controllo;
			control->nodo = nuovo;
			control->x = nuovo->x;
			control->y = nuovo->y;
		}
		else {
			// Scorro in fondo alla lista controllo per aggiornarla aggiungendo il nuovo nodo creato
			while (control->next != NULL) {
				control = control->next;
			}
			// Sono in coda
			control->next = new controllo;
			control->next->nodo = nuovo;
			control->next->x = nuovo->x;
			control->next->y = nuovo->y;
		}
		/*g.setY(g.getY() + 1);*/
	}
}

void Mappa::setOvest(Giocatore g, ptr_control control) {
	bool trovato = false;
	ptr_nodo corrente = NULL;
	corrente = getNodoCorrente(g, control);
	// Controllo, tramite la lista controllo, se il nodo a nord è già esistente
	if (control != NULL) {
		// Se è già esistente, lo collego a Nord del nodo corrente
		if (control->y == corrente->y && control->x == corrente->x - 1) {
			corrente->ovest = control->nodo;
			corrente->ovest->est = corrente;
		}
		// Scorro tutta la lista dei nodi già esistenti
		while ((control->next != NULL) && (!trovato)) {
			control = control->next;
			// Analogo al metodo sopra
			if (control->y == corrente->y && control->x == corrente->x - 1) {
				corrente->ovest = control->nodo;
				corrente->ovest->est = corrente;
				trovato = true;
				// Trovato, smetto di scorrere la lista
			}
		}
	}
	// Nodo non esistente, ne creo uno nuovo
	if (corrente->ovest == NULL) {
		ptr_nodo nuovo = NULL;
		corrente->ovest = nuovo;
		nuovo->x = corrente->x - 1;
		nuovo->y = corrente->y;
		nuovo->ovest = corrente;
		// Se la lista controllo è vuota
		if (control == NULL) {
			control = new controllo;
			control->nodo = nuovo;
			control->x = nuovo->x;
			control->y = nuovo->y;
		}
		else {
			// Scorro in fondo alla lista controllo per aggiornarla aggiungendo il nuovo nodo creato
			while (control->next != NULL) {
				control = control->next;
			}
			// Sono in coda
			control->next = new controllo;
			control->next->nodo = nuovo;
			control->next->x = nuovo->x;
			control->next->y = nuovo->y;
		}
		/*g.setY(g.getY() + 1);*/
	}
}

/*Mappa :: nodo* Mappa :: getNodo () {
	return corrente;
}*/
