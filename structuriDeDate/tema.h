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

int cifraMinima(int n) {

	int cifrMin = 9;

	while (n) {

		if (n % 10 < cifrMin) {

			cifrMin = n % 10;

		}

		n /= 10;
	}

	return cifrMin;
}


//todo functie ce formeaza un nr din cifra minima fiecarui elem

int numarCifreMinime(Lista lista) {

	Node* aux = lista.iterator();

	int nr = 0;

	for (int i = 0; i < lista.size(); i++) {

		nr = nr * 10 + cifraMinima(aux->data);

		aux = aux->next;

	}

	return nr;
}


//d) cate nr prime intre ele cu pozitia pe care stau exista in lista?


//todo functie ce returneaza cmmdc a 2 numere

int cmmdc(int a, int b) {

	int r;

	if (b == 0) {

		if (a == 0) {

			return -1;

		}
		else {

			return a;
		}
	}

	else
	{
		do {
			r = a % b;
			a = b;
			b = r;
		} while (r != 0);
	}

	return a;
}


//todo functie ce returneaza numarul de nr prime intre ele cu pozitia pe care stau exista in lista

int contorNrPrim(Lista lista) {

	Node* aux = lista.iterator();

	int ct = 0;

	for (int i = 0; i < lista.size() - 1; i++) {

		if (cmmdc(aux->data, i) == 1) {

			ct++;

		}

		aux = aux->next;

	}

	return ct;
}


//e) sa se verifice daca toate nr din lista au cifrele consecutive de la st->dr


//todo funtie ce verifica daca un nr are cifrele consecutive de la st->dr

bool cifreConsecutive(int nr) {

	while (nr>9) {

		if (nr % 10 - (nr / 10) % 10 != 1) {

			return false;

		}

		nr /= 10;

	}

	return true;
}


//todo functie ce verifica daca toate nr din lista au cifrele consecutive de la st->dr

bool cifreConsecutiveLista(Lista lista) {

	Node* aux = lista.iterator();

	for (int i = 0; i < lista.size(); i++) {

		if (!cifreConsecutive(aux->data)) {

			return false;

		}

		aux = aux->next;
	}

	return true;
}






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


	cout << "c) Numarul format din cifra minima a fiecarui element este " << numarCifreMinime(x);

	cout << endl << endl;


	cout << "d) In lista exista " << contorNrPrim(x) << " numere prime intre ele cu pozitia pe care se afla";

	cout << endl << endl;


	if (cifreConsecutiveLista(x)) {

		cout << "e) Toate numerele din lista au cifrele in ordine consecutiva de la st -> dr";

	}
	else {

		cout << "e) Nu toate numerele din lista au cifrele in ordine consecutiva de la st -> dr";

	}

	cout << endl << endl;
	
}



//exercitiul 3




//a) sa se verifice daca toate elementele pare au in descompunere in factori primi pe 2^k


//todo functie ce verifica daca un nr il are pe 2^k in desc in factori primi

bool desc2K(int n, int k) {

	int p = 0;

	while (n % 2 == 0) {

		p++;

		n /= 2;
	}

	if (p >= k) {

		return true;
	}

	return false;

}


//todo functie ce verifica daca toate elementele pare au in descompunere in factori primi pe 2^k

bool descElementeK(Lista lista, int k) {

	Node* aux = lista.iterator();

	for (int i = 0; i < lista.size(); i++) {

		if (desc2K(aux->data, k) == 0 && aux->data % 2 == 0) {

			return false;

		}

		aux = aux->next;

	}

	return true;
}


//b) pt fiecare nr care nu este pp si are aceeasi paritate cu cel din dr si cel din st, afisati desc in factori primi


//todo functie ce afiseaza desc in factori primi a unui nr

void descFactPrimi(int n) {

	int d = 2, p;

	do {

		p = 0;

		while (n % d == 0) {

			p++;

			n /= d;

		}

		if (p != 0) {

			cout << d << "^" << p << "  ";

		}

		d++;

	} while (n > 1);
}


//todo functie ce afiseaza desc in factori primi a nr din lista

void afisareDescElem(Lista lista) {

	for (int i = 1; i < lista.size() - 1; i++) {

		if (!ePatratPerfect(lista.nodePoz(i)->data)) {

			if (lista.nodePoz(i)->data % 2 == 0) {

				if (lista.nodePoz(i - 1)->data % 2 == 0 && lista.nodePoz(i + 1)->data % 2 == 0) {

					cout << lista.nodePoz(i)->data << ": ";

					descFactPrimi(lista.nodePoz(i)->data);

					cout << endl;

				}
			}
			else {

				if(lista.nodePoz(i)->data % 2 == 1) {

					if (lista.nodePoz(i - 1)->data % 2 == 1 && lista.nodePoz(i + 1)->data % 2 == 1) {

						cout << lista.nodePoz(i)->data << ": ";

						descFactPrimi(lista.nodePoz(i)->data);

						cout << endl;

					}
				}
				
			}
		}
	}
}


//c) sunt toate cifrele egale intre ele in a doua septim a listei?


//todo functie ce verifica daca un nr are toate cifrele egale

bool nrCifrEgale(int n) {

	while (n>9) {

		if (n % 10 != (n / 10) % 10) {

			return false;

		}

		n /= 10;
		
	}

	return true;
}


//todo functie ce verifica daca sunt toate cifrele egale intre ele in a doua septime a listei

bool cifreEgale(Lista lista) {

	for (int i = lista.size() / 7; i < 2 * lista.size() / 7; i++) {

		if (!nrCifrEgale(lista.nodePoz(i)->data)) {

			return false;

		}
		else {

			if (lista.nodePoz(i)->data % 10 != lista.nodePoz(i)->data % 10) {

				return false;

			}
		}
	}

	return true;
}


//d) afisati toate elementele, din care se vor sterege cifrele pare sau divizibile cu 3


//todo functie ce sterge cifrele pare sau divizibile cu 3

int elemNou(int n) {

	int m = 0;

	while (n) {

		if ((n % 10) % 2 != 0 || (n % 10) % 3 != 0) {

			m = m + (n % 10) * 10;

		}

		n /= 10;
		
	}

	return m;
}


//e) nr de nr prime ce nu sunt prime intre ele cu poz pe care stau


//todo functie ce verifica daca un numar este prim

bool prim(int n) {

	for (int d = 2; d < sqrt(n); d++) {

		if (n % d == 0) {

			return false;

		}
	}

	return true;
}

//todo functie ce returneaza numarul de nr prime care nu sunt prime intre ele cu pozitia pe care stau exista in lista

int contorElemPrim(Lista lista) {

	Node* aux = lista.iterator();

	int ct = 0;

	for (int i = 0; i < lista.size() - 1; i++) {

		if (prim(aux->data)) {

			if (cmmdc(aux->data, i) != 1) {

				ct++;

			}
		}

		aux = aux->next;

	}

	return ct;
}





void sol3() {

	Lista x;

	citireLista(x);

	cout << "Lista: " << endl << endl;

	x.afisare();

	cout << endl << endl;

	int k = 2;

	cout << "k=" << k << endl;

	if (descElementeK(x, k)) {

		cout << "a) Toate elementele pare au in descompunere in factori primi pe 2^" << k;
	}
	else {

		cout << "a) Nu toate elementele pare au in descompunere in factori primi pe 2^" << k;
	}

	cout << endl << endl;


	cout << "b) Descompunerea in factori primi a numerelor care nu sunt patrate perfecte si au aceeasi paritate cu vecinii din dreapta si din stanga: " << endl;

	afisareDescElem(x);

	cout << endl;


	if (cifreEgale(x)) {

		cout << "c) Toate cifrele sunt egale intre ele in a doua septim a listei";
	}
	else {

		cout << "c) Nu toate cifrele sunt egale intre ele in a doua septim a listei";

	}

	cout << endl << endl;


	cout << "e) In lista exista " << contorElemPrim(x) << " elemente prime care nu sunt prime intre ele cu pozitia pe care stau";

	cout << endl << endl;


	cout << "f) Cel mai mic mutiplu comun dntre " << x.nodePoz(7)->data << " si " << x.nodePoz(12)->data << " este ";

	cout << (x.nodePoz(7)->data * x.nodePoz(12)->data) / cmmdc(x.nodePoz(7)->data, x.nodePoz(12)->data);

	cout << endl << endl;


}