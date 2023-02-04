#pragma once
#include"node.h"
struct Lista{

	Node* head=NULL;

	void addStart(int data) {


		if (head == NULL) {


			head = new Node();

			head->data = data;
			head->next = NULL;

		}
		else {

			Node* nou = new Node();

			nou->data = data;

			nou->next = head;

			head = nou;
		}

	}

	void afisare() {

		Node* aux = head;
		while (aux != NULL) {

			cout << aux->data << ' ';

			aux = aux->next;
			
		}
	}

	void addSfarsit(int data) {
	
		if (head == NULL) {

			head = new Node();

			head->data = data;

			head->next = NULL;

		}
		else {


			Node* nou = new Node();

			Node* aux = head;

			while (aux->next != NULL) {

				aux = aux->next;
			}

			aux->next = nou;

			nou->data = data;

			nou->next = NULL;

		}

	}

	void addPozitie(int poz, int data) {
		
		if (poz == 0) {

			addStart(data);
			return;
		}
		Node* temp = head;

		int ct = 0;

		while (temp != NULL && ct != poz - 1) {

			temp = temp->next;
			ct++;
		}


		if (temp == NULL) {

			addSfarsit(data);

			return;
		}

		Node* nou = new Node();

		nou->data = data;

		nou->next = temp->next;

		temp->next = nou;
		
	}

	void stergereStart() {
		head = head->next;
	}

	void stergereSfarsit() {
		Node* aux = head;
		while (aux->next->next != NULL) {
			aux = aux->next;
		}
		aux->next = NULL;
	}

	void stergerePozitie(int poz) {
		
		Node* aux = head;
		int ct = 0;

		if (poz == 0) {
			stergereStart();
			return;
		}
		
		while (aux != NULL && ct != poz - 1) {
			aux = aux->next;
			ct++;
		}

		if (aux == NULL) {
			stergereSfarsit();
			return;
		}
		aux->next = aux->next->next;
		
		

	}

	int size() {
		int ct = 0;
		Node* aux = head;
		while (aux != NULL) {
			aux = aux->next;
			ct++;
		}
		return ct;
	}
		
};