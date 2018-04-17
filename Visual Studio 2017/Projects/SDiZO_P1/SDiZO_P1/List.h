#pragma once
#include <iostream>
#include <stdlib.h>
using namespace std;

struct ElemList {
	int data;
	ElemList *next;
	ElemList *prev;
};
class List
{
public:
	ElemList *head;
	ElemList *tail;
	int count;

	void pushElemFront(int key);
	void pushElemEnd(int key);
	void pushElemInside(int key1, int key2);

	void buildList1();
	ElemList *findElemList(int key);
	void remove(ElemList *p);

	bool findElem(int key);
	void findElemOnly(int key);
	void popElemInside(int key);
	void popElemFront();
	void popElemEnd();
	void display();
	List();
	~List();
};

