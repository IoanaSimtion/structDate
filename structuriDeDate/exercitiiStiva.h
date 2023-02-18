#include "stiva.h";

#pragma once


//1. sa se verifice folosind o stiva daca un text este corect balantat 
//(asdas][)


//todo functie ce memoreaza caracterele unui cuv pe stiva

void memorareStiva(Stiva& s, char cuv[20]) {

	for (int i = 0; i < strlen(cuv); i++) {

		s.push(cuv[i]);

	}

}


//todo functie ce verifica daca un text e corect balantat






void sol1() {

	Stiva s;

	char text[20] = "(mama(()))";

	memorareStiva(s, text);

	s.afisare();
}


