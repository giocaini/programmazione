#include "Mappa.h"
#include <iostream>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	Mappa map;
	ptr_nodo head = new nodo;
	head = map.setMappa(2);
	ptr_control control = new controllo;
	control = map.setControl(head);
	//char nome [10] = "Mimmo";
	Giocatore g (1);

	map.setNord(g, control);
	return 0;
}
