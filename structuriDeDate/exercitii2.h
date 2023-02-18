#include "lista.h"
#include <math.h>
#include <fstream>
#pragma once


//FISA


//exercitiul 42


//todo functie ce citeste o lista

void citireLista(Lista& x, int& n) {

	ifstream f("lista.txt");

	f >> n;

	for (int i = 0; i < pow(2, n); i++) {

		int nr;

		f >> nr;

		x.addSfarsit(nr);

	}

}


//todo functie ce afiseaza o lista

void afisareLista(Lista lista) {

	Node* aux = lista.iterator();

	for (int i = 0; i < lista.size(); i++) {

		cout << aux->data << ' ';

		aux = aux->next;

	}
}


//todo functie ce creaza alta lista din cea initiala (b[1]=a[1]*a[2], ...)

void listaProdus(Lista& lista, int n) {

	Node* aux = lista.iterator();

	for (int i = 0; i < pow(2, n - 1); i ++) {

		lista.setareValoarePoz(i, (aux->data * aux->next->data));

		aux = aux->next;

		aux = aux->next;

	}

}

//todo functie ce verifica daca toate elementele din lista sunt < S

bool verificareElemente(Lista lista, int S) {

	Node* aux = lista.iterator();

	for (int i = 0; i < lista.size(); i++) {

		if (aux->data >= S) {

			return false;

		}
	}

	return true;
}


//todo functie ce verifica daca produsul elem din vector e < S

bool produsElemS(Lista lista, int n, int S) {

	Node* aux = lista.iterator();

	for (int i = 0; i < pow(2, n - 1); i++) {

		if (aux->data * aux->next->data >= S) {

			return false;

		}

		aux = aux->next;
		
		aux = aux->next;
	}

	return true;
}


//todo functie ce sterge elemente din lista

void stergereSfLista(Lista& lista, int n) {

	for (int i = pow(2, n - 1); i < pow(2, n); i++) {

		lista.stergereSfarsit();

	}
}


//todo functie care executa operatia descrisa cat timp elem sunt < S

void operatieLista(Lista& lista, int n, int S) {

	while (produsElemS(lista, n, S)) {

		listaProdus(lista, n);

		stergereSfLista(lista, n);

		n--;
	}

}




void sol42() {

	Lista x;

	int n = 0, S;

	citireLista(x, n);

	cout << "Lista: " << endl << endl;

	afisareLista(x);

	//x.head = NULL;

	/*listaProdus(x, n);

	stergereLista(x, n);

	afisareLista(x);*/


	cout << endl << endl;

	cout << "S=";
	
	cin >> S;

	cout << endl << "Lista obtinuta este: " << endl << endl;

	operatieLista(x, n, S);

	afisareLista(x);
}



//exercitiul 43 - TEMA


//todo functie ce citeste o lista

void citireLista2(Lista& lista, int& n) {

	ifstream f("lista2.txt");

	f >> n;

	for (int i = 0; i < n; i++) {

		int x;

		f >> x;

		lista.addSfarsit(x);

	}
}







void sol43() {

	Lista x, sol;

	int n, k = 6;

	citireLista2(x, n);

	afisareLista(x);

}


//exercitiul 45



//todo functie ce citeste 2 liste

void citireListe(Lista& l1, Lista& l2) {

	ifstream f("liste.txt");

	int n, m;
	
	f >> n >> m;

	for (int i = 0; i < n; i++) {

		int x;

		f >> x;

		l1.addSfarsit(x);

	}

	for (int i = 0; i < m; i++) {

		int y;

		f >> y;

		l2.addSfarsit(y);

	}

}


//todo functie ce interclaseaza 2 liste

void interclasare(Lista l1, Lista l2, Lista& l3) {

	int i = 0, j = 0;

	int n = l1.size(), m = l2.size();

	/*cout << l1.size() << endl;

	cout << l2.size() << endl;*/

	while (i < n && j < m) {

		if (l1.nodePoz(i)->data < l2.nodePoz(j)->data) {

			if (l1.nodePoz(i)->data % 2 == 1) {

				l3.addSfarsit(l1.nodePoz(i)->data);
								
			}

			i++;
		}
		else {

			if (l2.nodePoz(i)->data % 2 == 1) {

				l3.addSfarsit(l2.nodePoz(i)->data);

			}

			j++;

		}
		
		//cout << "i=" << i << endl << "j=" << j << endl << endl;
	}

	

	if (j >= m) {

		while (i < n) {

			if (l1.nodePoz(i)->data % 2 == 1) {

				l3.addSfarsit(l1.nodePoz(i)->data);
				
			}
			
			i++;
		}

	}

	if (i >= n) {

		while (j < m) {

			if (l2.nodePoz(j)->data % 2 == 1) {

				l3.addSfarsit(l2.nodePoz(j)->data);
				
			}

			j++;

		}

	}

	//l3.afisare();
}




void sol45() {

	Lista x, y, z;

	citireListe(x, y);

	y.sortCrescator();

	cout << "Lista 1" << endl << endl;

	x.afisare();

	cout << endl << endl;

	cout << "Lista 2" << endl << endl;

	y.afisare();

	cout << endl << endl;

	cout << "Lista obtinuta in urma interclasarii " << endl << endl;

	interclasare(x, y, z);

	z.afisare();

	cout << endl << endl;
}



//exercitiul 46


void citireListaCp(Lista& lista) {

	ifstream f("listaCubPerfect.txt");

	int n;

	f >> n;

	for (int i = 0; i < n; i++) {

		int x;

		f >> x;

		lista.addSfarsit(x);

	}

}



//todo functie ce verifica daca un numar este cub perfect


bool cubPerfect(int n) {

	int x = cbrt(n);

	if (x * x * x == n) {

		return true;

	}

	return false;

}


//todo functie ce returneaza prima aparitie a unui cub perfect 

int pozPrimulCubPerf(Lista lista) {

	Node* aux = lista.iterator();

	for (int i = 0; i < lista.size(); i++) {

		if (cubPerfect(aux->data)) {

			return i;

		}

		aux = aux->next;

	}

	return -1;
}


//todo functie ce returneaza poz ultimului cub perfect

int pozUltimulCubPerf(Lista lista) {

	for (int i = lista.size() - 1; i >= 0; i--) {

		if (cubPerfect(lista.nodePoz(i)->data)) {

			return i;

		}
	}

	return -1;
}


//todo functie ce sterge elementele cuprinse intre 2 poz

void stergereElementePoz(Lista& lista, int poz1, int poz2) {

	for (int j = poz1; j <= poz2; j++) {

		lista.stergerePozitie(poz1);

	}

}



void sol46() {

	Lista x;

	citireListaCp(x);

	cout << "Lista" << endl << endl;

	x.afisare();

	cout << endl << endl;

	cout << "Lista dupa stergerea elementelor cuprinse intre primul si ultimul cub perfect" << endl << endl;

	stergereElementePoz(x, pozPrimulCubPerf(x), pozUltimulCubPerf(x));

	x.afisare();

	cout << endl << endl;

}



//exercitiul 47 



//todo functie ce inverseaza elementele intre 2 poz date

void inversareElemente(Lista& lista, int poz1, int poz2) {

	for (int i = 0; i <= poz2 - poz1; i++) {

		int aux = lista.nodePoz(poz1)->data;

		lista.setareValoarePoz(poz1, lista.nodePoz(poz2)->data);

		lista.setareValoarePoz(poz2, aux);

		poz1++;

		poz2--;

	}

}


void sol47() {

	Lista x;

	citireListaCp(x);

	cout << "Lista initiala: " << endl << endl;

	x.afisare();

	cout << endl << endl;

	int m, i, j;

	cout << "m=";
	
	cin >> m;

	for (int i = 0; i < m; i++) {

		cout << "Introduceti o pereche de indici: " << endl;

		cin >> i >> j;

		cout << "Lista obtinuta in urma rotirii elementelor cuprinse intre poz " << i << " si " << j << " este: " << endl << endl;

		inversareElemente(x, i, j);

		x.afisare();

		cout << endl << endl;

	}

}



//exercitiul 36



//todo functie ce returneaza nr de cifre a unui nr

int numarCifre(int n) {

	int ct = 0;

	while (n) {

		n /= 10;

		ct++;

	}

	return ct;

}


//todo functie ce returneaza nr obtinut din alipirea cifrelor a 2 nr

int alipireCifre(int a, int b) {

	if (a < 0) {

		a = a * (-1);

	}

	if (b < 0) {

		b = b * (-1);

	}

	return a * pow(10, numarCifre(b)) + b;

}


//todo functie ce insereaza in lista

void inserare(Lista& lista) {

	for (int i = 0; i < lista.size() - 1; i++) {

		if (lista.nodePoz(i)->data < 0 && lista.nodePoz(i + 1)->data >= 0) {

			lista.addPozitie(i + 1, alipireCifre(lista.nodePoz(i)->data, lista.nodePoz(i + 1)->data));

			i++;
		}

	}

}



void sol36() {

	Lista x;

	int n;

	citireLista2(x, n);

	cout << "Lista initiala: " << endl << endl;

	x.afisare();

	cout << endl << endl;

	cout << "Lista dupa inserare: " << endl << endl;

	inserare(x);

	x.afisare();

	cout << endl << endl;


}



//exercitiul 38


//todo functie ce returneaza nr max de subsiruri 




//exercitiul 37


void citireListaK(Lista& lista, int& k) {

	ifstream f("listaStergere.txt");

	int n;

	f >> n;

	f >> k;

	for (int i = 0; i < 2 * n; i++) {

		int x;

		f >> x;

		lista.addSfarsit(x);

	}
}


//todo functie ce determina suma elementelor din lista

int sumaElemente(Lista lista) {

	int suma = 0;

	for (int i = 0; i < lista.size(); i++) {

		suma += lista.nodePoz(i)->data;

	}

	return suma;

}



//todo functie ce sterge elem din k in k

void stergereK(Lista lista, int n, int poz1, int k) {

	int j = 0;

	for (int i = 0; i < n; i++) {

		if (poz1 > n) {

			poz1 = 0;

		}

		lista.stergerePozitie(poz1);

		poz1 = poz1 + k;

	}

}


//todo functie ce sterge elemente incepand cu o poz

void stergereElemListaPoz(Lista lista) {



}









void sol37() {

	Lista x;

	int k;

	citireListaK(x, k);

	cout << "Lista: " << endl << endl;

	x.afisare();

	cout << endl << endl;

	cout << "Lista dupa stergere: " << endl << endl;


	


}