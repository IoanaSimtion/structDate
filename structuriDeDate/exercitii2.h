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