#pragma once
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <new.h>

class Array
{
private:
	int *array;
public:
	int numberOfIndex;
	void displayArray();
	void pushInside(int index,int key);
	void pushFront(int key);
	void pushEnd(int key);
	void popInside(int key);
	void popBack();
	void popFront();
	bool findElemArray(int key);
	void findElemArrayReturn(int key);
	Array();
	~Array();
};

