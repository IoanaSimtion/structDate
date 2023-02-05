#include "lista.h"
#include <math.h>
#include <fstream>
#pragma once

//1. 

//a) cate nr prime sunt in lista

//todo functie de prim

bool ePrim(int numar) {

	if (numar == 2) {

		return true;

	}

	for (int i = 2; i < sqrt(numar); i++) {

		if (numar % i == 0) {

			return false;

		}
		else {

			return true;
		}
	}
}

//todo functie ce returneaza nr de elem prime din lista

int contorNumerePrime(Lista lista) {

	Node* aux = lista.iterator();

	int ct = 0;

	for (int i = 0; i < lista.size() - 1; i++) {

		if (ePrim(aux->data)) {

			ct++;

		}

		aux = aux->next;

	}

	return ct;
	
 }

void citireElemente(Lista& x) {

	int d;
	ifstream f("elemente.txt");
	f >> d;
	for (int i = 0; i < d; i++) {
		int data;
		f >> data;
		x.addSfarsit(data);
	}

}


//b) cea mai mica, cea mai mare valoare din lista

//todo functie ce returneaza val max din lista

int maximLista(Lista lista) {

	Node* aux = lista.iterator();
	
	int maxim = INT_MIN;

	for (int i = 0; i < lista.size(); i++) {

		if (aux->data > maxim) {

			maxim = aux->data;

		}

		aux = aux->next;
	}

	return maxim;

}

//todo functie ce returneaza valoarea minima din lista

int minimLista(Lista lista) {

	int minim = INT_MAX;

	Node* aux = lista.iterator();

	for (int i = 0; i < lista.size(); i++) {

		if (aux->data < minim) {

			minim = aux->data;

		}

		aux = aux->next;

	}

	return minim;
}

//todo functie ce memoreaza fr cifrelor unui nr

void frCifr(int nr, int fr[]) {

	while (nr) {

		fr[nr % 10]++;
		
		nr /= 10;

	}
}

//todo functie ce memoreaza fr cifrelor din lista

void frecventaCifre(Lista lista, int fr[]) {

	Node* aux = lista.iterator();

	for (int i = 0; i < lista.size() - 1; i++) {

		frCifr(aux->data, fr);

		aux = aux->next;

	}

}

//todo functie ce returneaza cea mai mica cifra din lista

int cifraMin(Lista lista) {

	int fr[100]{};

	frecventaCifre(lista, fr);

	for (int i = 0; i < 10; i++) {

		if (fr[i] != 0) {

			return i;
		}

	}
}

//todo functie ce returneaza cifra maxima

int cifraMax(Lista lista) {

	int fr[100]{};

	frecventaCifre(lista, fr);

	for (int i = 9; i >= 0; i--) {

		if (fr[i] != 0) {

			return i;

		}
	}

}


//c) afisati rast nr cu propr ca prima cifra = ultima cifra

//todo functie ce verifica daca un nr are prima cifra = ultima cifra

bool primaUltimaCifra(int nr) {

	int uc = nr % 10;

	while (nr > 10) {

		nr /= 10;

	}

	if (uc == nr % 10) {

		return true;

	}

	return false;
}


//todo functie ce returneaza rasturnartul unui numar

int rasturnat(int nr) {

	int rast = 0;

	while (nr) {

		rast = rast * 10 + nr % 10;

		nr /= 10;
	}

	return rast;
}

//todo functie ce afiseaza rast nr cu proprietatea pc=uc

void afisareRast(Lista lista) {

	Node* aux = lista.iterator();

	for (int i = 0; i < lista.size(); i++) {

		if (primaUltimaCifra(aux->data)) {

			cout << "numarul: " << aux->data << endl;
			cout << "rasturnatul: " << rasturnat(aux->data) << endl;

		}

		aux = aux->next;
	}
}


//d) au toate nr din lista propr ca au exact k divizori proprii

//todo functie ce returneaza nr de divizori proprii ai unui nr

int nrDivizoriPropr(int nr) {

	int ct = 0;

	for (int i = 2; i < nr / 2; i++) {

		if (nr % 1 == 0) {

			ct++;

		}
	}

	return ct;
}

//todo functie ce verifica daca toate nr au k div propr

bool kDivPropr(Lista lista, int k) {

	Node* aux = lista.iterator();

	for (int i = 0; i < lista.size(); i++) {

		if (nrDivizoriPropr(aux->data) != k) {

			return false;

		}
	}

	return true;
}


//e) produsul nr din a doua treime ce au aceeasi paritate cu poz pe care stau

int produsNumere(Lista lista) {

	int produs = 1;

	Node* aux = lista.iterator();

	int d = lista.size();

	for (int i = 0; i < d / 3; i++) {

		aux = aux->next;

		//cout << aux->data << endl;

	}

	for (int i = d / 3; i <= 2 * (d / 3); i++) {

		//cout << aux->data << endl;

		if ((aux->data % 2 == 0 && i % 2 == 0) || (aux->data % 2 == 1 && i % 2 == 1)) {

			produs = produs * aux->data;

		}

		aux = aux->next;

	}

	return produs;
}


//g) afisati produsul cifrelor la fiecare element al listei ce are cifra de control un numar par

//todo functie ce returneaza cifra de control a unui nr

int cifraControl(int nr) {

	if (nr % 9 == 0) {
		
		return 9;

	}

	return nr % 9;
}

//todo functie ce returneaza produsul cifrelor unui nr

int produCifre(int nr) {

	int prod = 1;

	while (nr) {

		prod = prod * (nr % 10);

		nr /= 10;

	}

	return prod;
}


//todo functie ce afiseaza prod cifrelor la fiecare element al listei ce are cifra de control un numar par

void afisareProdusCifrContr(Lista lista) {

	Node* aux = lista.iterator();

	for (int i = 0; i < lista.size(); i++) {

		if (cifraControl(aux->data) % 2 == 0) {

			cout << "numar: " << aux->data << endl;

			cout << "produsul cifrelor: " << produCifre(aux->data) << endl;

		}

		aux = aux->next;
	}
}


//h) afisati in ord inversa toate nr superprime din vector

//todo functie ce verifica daca un numar este superprim

bool eSuperprim(int nr) {

	while (nr) {

		if (!ePrim(nr)) {

			return false;

		}

		nr /= 10;
	}

	return true;
}

//todo functie ce afiseaza toate nr superprime

void afisareSuperprim(Lista lista) {

	for (int i = lista.size() - 2; i >= 0; i--) {

		if (eSuperprim(lista.nodePoz(i)->data)) {

			cout << lista.nodePoz(i)->data << ' ';
			
		}
	}
}




void sol1() {

	Lista x;

	citireElemente(x);

	cout << "Lista: " << endl << endl;

	x.afisare();

	cout << endl << endl;

	cout << "a) In lista exista " << contorNumerePrime(x) << " elemente prime " << endl << endl;

	cout << "b) Valoarea maxima din lista este " << maximLista(x) << endl;
	cout << "   Valoarea minima din lista este " << minimLista(x) << endl << endl;
	cout << "   Cifra maxima din lista este " << cifraMax(x) << endl;
	cout << "   Cifra minima din lista este " << cifraMin(x) << endl << endl;

	cout << "c) Rasturnatul numerelor cu proprietatea ca prima cifra = ultima cifra: " << endl;
	afisareRast(x);
	cout << endl;

	int k = 5;

	cout << "k=" << k << endl;

	if (kDivPropr(x, k)) {
		cout << "d) Toate numerele din lista au " << k << " divizori proprii" << endl << endl;
	}
	else {

		cout << "d) Nu toate nrumerele din lista au " << k << " divizori proprii" << endl << endl;

	}

	cout << "e) Produsul numerelor din a doua treime ce au aceeasi paritate cu poz pe care stau este " << produsNumere(x) << endl << endl;

	cout << "g) Produsul cifrelor elementelor ce au cifra de control un numar par: " << endl;
	afisareProdusCifrContr(x);
	cout << endl;

	cout << "h) Numerele superprime, afisate in ordine inversa, sunt: " << endl;
	afisareSuperprim(x);
}
