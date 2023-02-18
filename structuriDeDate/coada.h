#include "node.h";

#pragma once


struct Coada {

	Node* top = NULL;

	
	void push(int data) {

		if (top == NULL) {

			top = new Node();

			top->data = data;

			top->next = NULL;

		}
		else {

			Node* nou = new Node();

			Node* aux = top;

			while (aux->next != NULL) {

				aux = aux->next;

			}

			aux->next = nou;

			nou->data = data;

			nou->next = NULL;

		}

	}


	void pop() {

		top = top->next;

	}


	void afisare() {

		Node* aux = top;

		while (aux != NULL) {

			cout << aux->data << ' ';

			aux = aux->next;

		}

	}

};