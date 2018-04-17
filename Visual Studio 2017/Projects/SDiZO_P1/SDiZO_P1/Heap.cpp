#include "stdafx.h"
#include "Heap.h"
#include <queue>
#include <cmath>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

Heap::Heap()
{
	array = NULL;
	size = 0;
}

Heap::~Heap()
{
	delete[] array;
}

bool Heap::findElement(int data)
{
	return findElementRec(0, data);
}

void Heap::pushHeap(int key)
{
	if (size == 0) {
		array = new int[1];
		array[0] = key;
		size++;
	}
	else {
		int *bufor = new int[size + 1];
		for (int i = 0; i < size; i++) {
			bufor[i] = array[i];
			//if(i==(size-1)) delete[] array;
		}
		size++;
		bufor[size - 1] = key;
		delete[] array;
		array = bufor;
		fixUp();
	}
}

void Heap::popHeap(int key)
{
	int index = findElement2(key);
	if ((size == 0) || (size == 1)) {
		array[0] = NULL;
		size = 0;
	}
	else {
		size--;
		int *bufor = new int[size];
		for (int i = 0; i < (index); i++) {
			bufor[i] = array[i];
		}
		for (int i = index; i < size; i++) {
			bufor[i] = array[i + 1];
		}
		delete[] array;
		array = bufor;
		fixUp();
	}
}

int Heap::leftDesc(int index)
{
	return ((2 * index) + 1);
}

int Heap::rightDesc(int index)
{
	return ((2 * index) + 2);
}

int Heap::parent(int index)
{
	return (int)floor((index - 1) / 2);
}

void Heap::fixUp()
{
	if (size > 0) {
		int i = size - 1;
		int parentIndex = parent(i);
		do {
			if (array[i] > array[parentIndex]) {

				int bufor = array[parentIndex];		//swap elements
				array[parentIndex] = array[i];
				array[i] = bufor;
			}
			i = parentIndex;
			parentIndex = parent(i);              //keep checking specific path
		} while (i > 0);

	}
	else return;
}

void Heap::fixDown(int index)
{
	if (size > 1) {                       //if there are at least 2 elements
		int i = index;                  //i = index of element we start repairing
		int l = leftDesc(i);			 //l = index of i's left descendant
		int r = rightDesc(i);			//r = index of i's right descendant
		if (r > size) r = NULL;
		if (l > size) l = NULL;
		while (l < size) {
			if (array[i] < array[r] || array[i] < array[l]) {
				if (array[r] > array[l]) {
					int p = array[i];
					array[i] = array[r];
					array[r] = p;
					i = r;

				}
				else {
					int p = array[i];
					array[i] = array[l];
					array[l] = p;
					i = l;
				}
			}
			int l = leftDesc(i);
			int r = rightDesc(i);
		}
	}
}

int Heap::findElement2(int data)  //zwraca index obiektu, który ma podana do funkcji wartoœæ
{
	if (size > 0) {
		for (int i = 0; i < size; i++) {
			if (array[i] == data) {
				return i;
			}
		}
	}
	return NULL;
}

bool Heap::findElementRec(int index, int data)
{
	if (index >= size) return false;
	if (array[index] == data) return true;
	if (array[index] > data) return false;
	if (findElementRec(leftDesc(index), data)) return true;
	if (findElementRec(rightDesc(index), data)) return true;
}

void Heap::popRoot()
{
	if (size > 0) {
		array[0] = array[size - 1];
		int *p = new int[size - 1];
		for (int i = 0; i < size - 1; i++) {
			p[i] = array[i];
		}
		delete[] array;
		array = p;
		size--;
		fixDown(0);
	}
}

void Heap::findE(int key)
{
	findERec(0, key);
}

void Heap::findERec(int index, int key)
{
	if (index >= size) {
		std::cout << "Brak dalszych potomkow" << endl;
		return;
	};
	if (array[index] == key) { std::cout << "Istnieje podany element w drzewie" << endl; return; };
	findERec(leftDesc(index), key);
	findERec(rightDesc(index), key);
	return;
}

void Heap::disHeap()
{
	int index = 0;
	int width = (size + 10);
	int heigth = (int)log2(size) + 1;
	int elemCounter = 1;
	int elemC = size;
	for (int i = 0; i < heigth; i++) {
		elemCounter = (int)pow(2, i);
		do {
			for (int a = 0; a < (floor(width - 1 / 2)); a++) {
				cout << "  ";
			};
			if (index < size) {
				if (array[index] > 1000) cout << "_" << array[index] << "_";
				//else if (array[index]>1000) cout << " _" << array[index] << "_ ";
				else cout << "_" << array[index] << "_";
				index++;
				elemCounter--;
			}
			else {
				elemCounter = 0; break;
			}
			for (int a = 0; a < (ceil(width - 1 / 2)); a++) {
				cout << "   ";
			};
		} while (elemCounter != 0);
		width = (int)ceil(width / 2);
		cout << endl;
		cout << endl;
	}
	cout << endl << "Index == " << index << endl;
}
