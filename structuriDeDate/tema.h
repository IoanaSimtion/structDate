#include "lista.h"
#include <math.h>
#include <fstream>
#pragma once

//todo functie ce citeste o lista

void citireLista(Lista& lista) {

	ifstream f("elemente.txt");

	int d;

	f >> d;

	for (int i = 0; i < d; i++) {

		int data;

		f >> data;

		lista.addSfarsit(data);
	}
}


//exercitiul 2


//a) afisati nr care au in componenta cifra minima


//todo functie ce memoreaza fr cifrelor unui nr

void frCifrNr(int fr[], int nr) {

	while (nr) {

		fr[nr % 10]++;

		nr /= 10;

	}
}


//todo functie ce memoreaza fr cifrelor nr din lista

void frCifreLista(Lista lista, int fr[]) {

	Node* aux = lista.iterator();

	for (int i = 0; i < lista.size() - 1; i++) {

		frCifrNr(fr, aux->data);

		aux = aux->next;
	}
}


//todo functie ce returneaza cifra minima din lista

int cifraMinima(Lista lista) {

	int fr[100]{};

	frCifreLista(lista, fr);

	for (int i = 0; i < 10; i++) {

		if (fr[i] != 0) {

			return i;

		}

	}
}


//todo functie ce verifica daca un nr contine o cifra

bool contineCifra(int nr, int cifra) {

	while (nr) {

		if (nr % 10 == cifra) {

			return true;

		}

		nr /= 10;
	}

	return false;
}


//todo functie ce afiseaza nr care contin cifra minima

void afisareNrCifrMin(Lista lista) {
	
	Node* aux = lista.iterator();

	for (int i = 0; i < lista.size() - 1; i++) {

		if (contineCifra(aux->data, cifraMinima(lista))) {

			cout << aux->data << ' ';
		}

		aux = aux->next;
	}

}


//b) afisati in ordine inversa elementele palindrome
//ce au cifra/ cifrele de mijloc un patrat perfect


//todo functie ce returneaza nr de cifre al unui nr

int numarCifre(int nr) {

	int ct = 0;

	while (nr) {

		nr /= 10;

		ct++;

	}

	return ct;
}

//todo functie ce determina cifra/cifrele de mijloc ale unui nr

int cifrMijloc(int nr) {

	if (numarCifre(nr) % 2 == 0) {

		nr = nr / pow(10, numarCifre(nr) / 2 - 1);

		return nr % 100;

	}
	else {

		nr = nr / pow(10, numarCifre(nr) / 2);

		return nr % 10;

	}

}


//todo functie ce verifica daca un nr este patrat perfect

bool ePatratPerfect(int nr) {

	if (sqrt(nr) == int(sqrt(nr))) {

		return true;

	}
	
	return false;

}


//todo functie ce returneaza oglinditul unui numar

int oglindit(int nr) {

	int ogl = 0;

	while (nr) {

		ogl = ogl * 10 + nr % 10;

		nr /= 10;

	}

	return ogl;
}


//todo functie ce verifica daca un nr e palindrom

bool ePalindrom(int nr) {

	if (nr == oglindit(nr)) {

		return true;

	}

	return false;
}



//todo functie ce afiseaza in ord inversa elem palindrome cu cifra de mijl pp

void afisareElem(Lista lista) {

	for (int i = lista.size() - 2; i >= 0; i--) {

		if (ePalindrom(lista.nodePoz(i)->data) && ePatratPerfect(cifrMijloc((lista.nodePoz(i)->data)))) {

			cout << lista.nodePoz(i)->data << ' ';
		}
	}
}


//c) realizati un nou nr din cifra minima fiecarui elem


//todo functie ce returneaza cifra minima a unui nr









//solutia 2

void sol2() {

	Lista x;

	citireLista(x);

	cout << "Lista: " << endl << endl;

	x.afisare();

	cout << endl << endl;


	cout << "a) Cifra minima din lista este " << cifraMinima(x) << endl;

	cout << "   Elementele care contin cifra minima sunt: ";

	afisareNrCifrMin(x);

	cout << endl << endl;


	cout << "b) Elementele palindrome ce au nr de mijloc un patrat perfect, afisate in ordine inversa, sunt: ";

	afisareElem(x);

	cout << endl << endl;




}