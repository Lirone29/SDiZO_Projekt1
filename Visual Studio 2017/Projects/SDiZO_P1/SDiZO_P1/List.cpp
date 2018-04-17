#include "stdafx.h"
#include "List.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
#include "list.h"
using namespace std;

void List::pushElemFront(int key)
{
	if (!head) {
		head = new ElemList;
		head->data = key;
		head->next = nullptr;
		head->prev = nullptr;
		count++;
		tail = head;
	}
	else
	{
		ElemList *p = new ElemList;
		p->data = key;
		p->next = head;
		head->prev = p;
		p->prev = nullptr;
		head = p;
		count++;
	}
}

void List::pushElemEnd(int key)
{
	if (!head) {                        //if adding 1st element
		head = new ElemList;
		head->data = key;
		head->next = nullptr;
		head->prev = nullptr;
		count++;
	}
	else {
		ElemList *p = head;
		ElemList *newElem = new ElemList;
		while (p->next) {             //find last element
			p = p->next;
		}
		newElem->data = key;
		newElem->prev = p;            //newElem->prev points to last element
		newElem->next = nullptr;        //newElem is the last element
		p->next = newElem;            //current lastElem->next points to newElem
		count++;                         //increase the size
	}
}

void List::pushElemInside(int key1, int key2)
{
	ElemList *bufor = new ElemList;
	ElemList *p = new ElemList;
	p->data = NULL;
	bufor = head;
	int i = count;
	if ((i == 0) && (p->data == NULL)) {
		p->data = key2;
		head = p;
		count++;
		return;
	}
	while (i != 0)
	{
		if (bufor->data == key1) {
			p->data = key2;
			p->next = bufor->next;
			p->prev = bufor;
			bufor->next = p;
			count++;
			return;
		}
		bufor = bufor->next;
		i--;
	}
}

void List::buildList1()
{
	fstream plik;
	string linia;
	int licznik;
	int var;
	plik.open("20.txt");
	plik >> licznik;
	cout << licznik << endl;
	for (int i = licznik; i > 0; i--) {
		plik >> var;
		this->pushElemFront(var);
	}
	plik.close();
}

ElemList *List::findElemList(int key)
{
	ElemList *bufor = head;
	int i = count;
	for (int i = count; i > 0; i--) {
		if ((bufor->data) == key)
			return (bufor);
	}
	if (i == 0) { cout << "Brak podanego elementu na liscie"; } return NULL;
}

bool List::findElem(int key)
{
	ElemList *tmp = head;
	for (int i = 0; i < count; i++) {
		if (tmp->data == key) {
			return true;
		}
		tmp = tmp->next;
	}
	return false;
}

void List::findElemOnly(int key)
{
	ElemList *tmp = head;
	for (unsigned int i = 0; i < count; i++) {
		if (tmp->data == key) {
			cout << "Istnieje podany element" << endl;
			return;
		}
		tmp = tmp->next;
	}
	cout << "Nie ma takiego elementu" << endl;
}

void List::popElemInside(int key) //podawana powinna byæ tylko wartoœæ
{
	if (head->data == key)                  //jeœli zawartosc jest równa 0 
	{
		popElemFront();
		return;
	}
	ElemList *tmp = head;
	int i = 0;
	while (i != (count - 1))
	{
		i++;
		tmp = tmp->next;
	}
	if ((tmp != nullptr) && (tmp->data == key))
	{
		popElemEnd();
		return;
	}
	ElemList *p = head;
	for (int i = 0; i < count - 2; i++) {
		if (p->next->data == key) break;
		p = p->next;            //znajdz element z podan¹ wartoœci¹
	}
	if (p->next->next != nullptr)
		p->next->next->prev = p;
	p->next = p->next->next;    //skip element at given index in pointers  
	count--;
}

void List::popElemFront()
{
	if (count)remove(head); return;
	if (head->next) {                   //if there is more than 1 element
		(head->next)->prev = nullptr;
		head = head->next;              //makes element at index 1 the new head
	}
	else {                              //if there is 1 or 0 elements
		head = nullptr;
	}

	if (count != 0) {                      //if there were more than 0 elements
		count--;                         //decrease the size
	}
	return;
}
void List::popElemEnd()
{
	if (count) remove(tail);
	return;
}

void List::remove(ElemList * e)
{
	count--;
	if (e == nullptr) return;
	if (e->prev) e->prev->next = e->next;
	else        head = e->next;
	if (e->next) e->next->prev = e->prev;
	else        tail = e->prev;
	delete e;
	return;
}
void List::display()
{
	std::cout << "\n";
	ElemList *p = head;
	std::cout << "\n";
	while (p) {
		std::cout << " " << p->data << endl;
		p = p->next;
	}
	std::cout << "\n";
}

List::List()
{
	head = tail = nullptr;
	count = 0;
}

List::~List()
{
	if (head) {
		ElemList *curr = head;
		ElemList *next = curr->next;
		while (curr->next) {

			next = curr->next;
			delete curr;
			curr = next;
		}
		delete next;
	}
}
