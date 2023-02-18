#include "node.h";

#pragma once

struct Stiva {


	Node* top = NULL;


	void push(int data) {

		if (top == NULL) {

			top = new Node();

			top->data = data;

			top->next = NULL;

		}
		else {

			Node* nou = new Node();

			nou->data = data;

			nou->next = top;

			top = nou;

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


	int size() {

		int ct = 0;

		Node* aux = top;

		while (aux != NULL) {

			aux = aux->next;

			ct++;

		}
		
		return ct;
	}

	Node* getNode(int poz) {

		int ct = 0;
		
		Node* aux = top;

		while (aux != NULL && ct != poz) {

			aux = aux->next;

			ct++;

		}

		return aux;

	}

	bool isEmpty() {

		if (top == NULL) {

			return true;

		}
		
		return false;

	}

};
	