#include "Giocatore.h"
#include <string.h>

Giocatore::Giocatore(int id) {
	//strcpy_s(nome, 20, this->nome);
	this->id = id;
	x = 0;
	y = 0;
	w = false;
}

void Giocatore::setX(int x) {
	this->x = x;
}

void Giocatore::setY(int y) {
	this->y = y;
}

int Giocatore::getX() {
	return x;
}

int Giocatore::getY() {
	return y;
}
/*bool Giocatore::winner() {
	return true;
}*/

