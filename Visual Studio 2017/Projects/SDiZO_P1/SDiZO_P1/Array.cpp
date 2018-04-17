#include "stdafx.h"
#include "Array.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void Array::displayArray()
{
	for (int i = 0; i < numberOfIndex; i++) {
		cout << "Array[" << i << "]= " << array[i] <<endl;
	}
}

void Array::pushInside(int index, int key)
{
	if (index > numberOfIndex) {
		cout << "Brak takiego indeksu" << endl;
		return;
	}
	if (numberOfIndex > 0) {                                 //if contains at least 1 element
		int *tmp = new int[numberOfIndex + 1];               //make temp array with bigger size
		for (int i = 0; i < index; i++) {
			tmp[i] = array[i];                      //copy old array to temp from 0 to elem before index
		}
		tmp[index] = key;                       //insert newData at given index
		for (int i = index; i < numberOfIndex; i++) {
			tmp[i + 1] = array[i];                  //keep copying from index
		}
		delete[] array;
		array = tmp;
		numberOfIndex++;
	}
	else
	{                                          //if has no elements
		array = new int[1];
		array[0] = key;
		numberOfIndex++;
	}
}

void Array::pushFront(int key)
{
	if (numberOfIndex >0) {
		numberOfIndex++;
		int *bufor = new int[numberOfIndex];
		for (int i = 0; i < (numberOfIndex-1); i++) 
		{
			bufor[i + 1] = array[i];
		}
		delete[] array;
		array = bufor;
		array[0] = key;
	}
	else {
		array = new int;
		array[0] = key;
		numberOfIndex++;
	}
}

void Array::pushEnd(int key)
{
	if (numberOfIndex > 0) {
		int *p = new int[numberOfIndex + 1];
		for (int i = 0; i < numberOfIndex; i++) {
			p[i] = array[i];
		}
		delete[] array;
		array = p;
		array[numberOfIndex] = key;
		numberOfIndex++;
	}
	else {
		array = new int[1];
		array[0] = key;
		numberOfIndex++;
	}
}

void Array::popInside(int index)
{
	if ((numberOfIndex > 0) && (index < numberOfIndex)) {                             //if contains at least 1 element
		if (index == 0) {
			popFront();
		}
		else if (index == (numberOfIndex - 1)) {
			popBack();
		}
		else {
			int* tmp = new int[numberOfIndex - 1];           //create temp array with smaller size
			for (int i = 0; i < index; i++) {
				tmp[i] = array[i];                  //copy old array to temp from 0 to elem before index
			}
			for (int i = index; i < numberOfIndex - 1; i++) {
				tmp[i] = array[i + 1];              //keep copying ignoring item at index
			}
			delete[] array;                         //free old memory
			array = tmp;                            //switch array's pointer
			numberOfIndex--;                                 //decrease size
		}
	}
	return;
}

void Array::popBack()
{
	if (numberOfIndex > 0) {
		numberOfIndex--;
		int *bufor = new int[numberOfIndex];
		for (int i = 0; i < numberOfIndex; i++)
		{
			bufor[i] = array[i];
		}
		delete[] array;
		array = bufor;
	}
	else {
		delete[] array;
		array = NULL;
		return;
	}
}

void Array::popFront()
{
	if (numberOfIndex >0) {
		numberOfIndex--;
		int *bufor = new int[numberOfIndex];
		for (int i = numberOfIndex; i > 0; i--)
		{
			bufor[i-1] = array[i];
		}
		delete[] array;
		array = bufor;
	}
	else {
		delete[] array;
		return;
	}
}

bool Array::findElemArray(int key)
{

	for (int i = 0; i < (numberOfIndex + 1); i++)
	{
		if (array[i] == key) {
			cout << "Znalezniono podany element" << endl;
			return true;
		}
	}
	cout << "Nie ma podanego elementu w tablicy" << endl;
	return false;
}

void Array::findElemArrayReturn(int key)
{
	for (int i = 0; i < (numberOfIndex + 1); i++)
	{
		if (array[i] == key) { cout << "Istnieje podany element w tablicy" << endl; return; }
	}
	cout << "Nie ma podanej wartoœci w tablicy" << endl;
	return;
}

Array::Array()
{
	numberOfIndex = 0;
	array = NULL;
}


Array::~Array()
{
	delete[] array;
}
