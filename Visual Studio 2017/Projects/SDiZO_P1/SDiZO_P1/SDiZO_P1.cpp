//SDiZO_P1.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.

#include "stdafx.h"
#include "Array.h"
#include "List.h"
#include "Heap.h"
#include "RBTree.h"
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include <limits>
#include "RBTreeT.h"

//Autor:
//Eliza Kalata, 235543
//Data: 16.04.2018
//Projekt 1 SDiZO

using namespace std;

const int ELEM_NUMBER = 20;
const int TEST_COUNT = 1;
const int PRECISION = 7;
const string FILE_PATH = "20.txt";

void test_list();
void test_array();
void test_heap();
void test_rbtree();

int structuresMenu();

Heap heapObject;
Array arrayObject;
List listObject;
RBTreeT rbtreeObject;
RBTree displayObject;

vector<int> file;
vector<int> read_file(string file);
int key1, key2;
int anwser, anwser1, anwser2;

void dispalyChoose()
{
	cout << "Wybierz jaka operacje chcesz wykonac:" << endl;
	cout << "1. Zbuduj z pliku" << endl;
	cout << "2. Usun" << endl;
	cout << "3. Dodaj" << endl;
	cout << "4. Znajdz" << endl;
	cout << "5. Wyswietl " << endl;
	cout << "6. Exit" << endl;
	return;
}

void intro() {
	cout << "Witam w programie, prosze wybrac strukture do zrealizowania: \n";
	cout << " 1. Array [Tablica] \n";
	cout << " 2. List [Lista] \n";
	cout << " 3. Heap [Kopiec] \n";
	cout << " 4. Red - Black Tree [ Drzewo Czerowono-Czarne] \n";
	cout << " 5. Exit \n";
	return;
}

void arrayMenu();
void listMenu();
void heapMenu();
void rbtreeMenu();

void initialize() {

	srand(time(NULL));                          //set rand

	cout.precision(PRECISION);           //set number precision
	cout << fixed;

	arrayObject = Array();
	listObject = List();
	heapObject = Heap();
	rbtreeObject = RBTreeT();

	displayObject = RBTree();

	file = read_file(FILE_PATH);
}

int main()
{
	initialize();

	//test_list();	cout << "\n";		//DONE
	//test_array();	cout << "\n";		//DONE
	//test_heap();	cout << "\n";		//DONE
	//test_rbtree();cout << "\n";		//DONE

	std::cout << "\n";

	int tmp = 0;
	while (tmp != 5) {
		tmp = structuresMenu();
	}

	exit(0);
}

int structuresMenu()
{
	do {
		anwser = NULL;
		intro();
		std::cin >> anwser;

		switch (anwser) {
		case 1: {
			arrayMenu();
		}
				break;
		case 2: {
			listMenu();
		}
				break;
		case 3: {
			heapMenu();
		}
				break;
		case 4: {
			rbtreeMenu();
		}
				break;
		case 5: {
			exit(0);
		}
				break;
		default: {
			cout << "Error! Podales niew³aœciwy numer!\n Wybierz ponownie strukturê do zrealizowania\n";
		}
				 break;
		};

	} while (anwser != 5);
	return 5;
}
void arrayMenu() {
	anwser = NULL;
	while (anwser != 6) {
		cout << "\nArray [Tablica]" << endl;
		dispalyChoose();
		std::cin >> anwser;

		switch (anwser)
		{
		case 1: {
			arrayObject = Array();
			for (int i = 0; i < file.size(); i++) {
				arrayObject.pushFront(file[i]);
			}; }
				break;
		case 2: {
			cout << "Podaj warosc ktora chcesz usunac z tablicy" << endl;
			cout << "1. Usuwanie z poczatku" << endl;
			cout << "2. Usuwanie ze srodka" << endl;
			cout << "3. Usuwanie z konca" << endl;
			std::cin >> anwser1;
			switch (anwser1)
			{
			case 1: {
				arrayObject.popFront();
			}
					break;
			case 2: {
				cout << "Podaj indeks jaka chcesz usunac" << endl;
				cin >> key1;
				arrayObject.popInside(key1);
			}
					break;
			case 3: {
				arrayObject.popBack();
			}
					break;
			default: { cout << "podales zly numer" << endl; }
					 break;
			};
		};
				break;
		case 3: {
			cout << "Podaj warosc ktora chcesz dodac do listy" << endl;
			cout << "1. Dodawanie do poczatku" << endl;
			cout << "2. Dodawanie do srodka" << endl;
			cout << "3. Dodanie do konca" << endl;
			cin >> anwser2;
			switch (anwser2) {
			case 1: {
				cout << "Podal element:" << endl;
				cin >> key1;
				arrayObject.pushFront(key1);
			}
					break;
			case 2: {
				cout << "Podaj index na ktory chcesz wstawiæ element" << endl;
				cin >> key1;
				cout << "Podaj warosc jak¹ chcesz dodac pod wskazanym indeksem" << endl;
				cin >> key2;
				arrayObject.pushInside(key1, key2);
			}
					break;
			case 3: {
				cout << "Podaj element:" << endl;
				cin >> key1;
				arrayObject.pushEnd(key1);
			}
					break;
			default: { cout << "podales zly numer" << endl; }	break;
			}

		}
				break;
		case 4: {
			cout << "Podaj wartosc jaka chcesz znalezc" << endl;
			cin >> key2;
			arrayObject.findElemArray(key2);
		}
				break;
		case 5: {
			arrayObject.displayArray();
		}
		case 6:
			break;
		default: cout << "Error 1" << endl;
			break;
		};
	}
}
void listMenu() {
	anwser = NULL;
	while (anwser != 6) {
		cout << " 2. List [Lista] \n";
		dispalyChoose();
		std::cin >> anwser;
		int searchedValue = NULL; //Wartoœæ szukana 
		int key1 = NULL;
		int key2 = NULL;
		switch (anwser)
		{
		case 1: {
			listObject = List();
			for (int i = 0; i < file.size(); i++) {
				listObject.pushElemFront(file[i]);
			}
		}
				break;
		case 2: {
			int anwser = 0;
			cout << "Podaj warosc ktora chcesz usunac z listy" << endl;
			cout << "1. Usuwanie z poczatku" << endl;
			cout << "2. Usuwanie ze srodka" << endl;
			cout << "3. Usuwanie z konca" << endl;
			cin >> anwser;
			switch (anwser)
			{
			case 1: {
				listObject.popElemFront();
			}
					break;
			case 2: {
				key1 = NULL;
				cout << "Podaj wartosc jaka chcesz usunac" << endl;
				cin >> key1;
				listObject.popElemInside(key1);
			}
					break;
			case 3: {
				listObject.popElemEnd();
			}
					break;
			default: { cout << "podales zly numer" << endl; }
					 break;
			}
		};
				break;
		case 3: {
			int anwser = 0;
			cout << "Podaj warosc ktora chcesz dodac do listy" << endl;
			cout << "1. Dodawanie do poczatku" << endl;
			cout << "2. Dodawanie do srodka" << endl;
			cout << "3. Dodanie do konca" << endl;
			cin >> anwser;
			switch (anwser) {
				{
			case 1: {
				key1 = NULL;
				cout << "Podal element:" << endl;
				cin >> key1;
				listObject.pushElemFront(key1);
			}
					break;
			case 2: {
				key1 = NULL;
				key2 = NULL;
				cout << "Podaj warosc po ktorej chcesz dodac element" << endl;
				cin >> key1;
				cout << "Podaj warosc jak¹ chcesz dodac po wskazanym powyzej elemencie" << endl;
				cin >> key2;
				listObject.pushElemInside(key1, key2);
			}
					break;
			case 3: {
				key1 = NULL;
				cout << "Podaj element:" << endl;
				cin >> key1;
				listObject.pushElemEnd(key1);
			}
					break;
			default: { cout << "podales zly numer" << endl; }
					 break;
				}
			};
		}
				break;
		case 4: {
			cout << "Podaj wartosc jaka chcesz znalezc" << endl;
			cin >> searchedValue;
			listObject.findElemOnly(searchedValue);
		};
				break;
		case 5: {
			listObject.display();
		};
				break;
		default: {cout << "Error 2" << endl; };
				 break;
		}
	}
};
void heapMenu() {
	anwser = NULL;
	while (anwser != 6) {
		cout << " 3. Heap [Kopiec]" << endl;
		dispalyChoose();
		std::cin >> anwser;
		switch (anwser)
		{
		case 1: {
			heapObject = Heap();
			for (int i = 0; i < file.size(); i++) {
				heapObject.pushHeap(file[i]);
			}
		};
				break;
		case 2: {
			cout << "Podaj Element do usuniêcia" << endl;
			cin >> key1;
			heapObject.popHeap(key1); };
				break;
		case 3: {
			cout << "Podaj element do wstawienia" << endl;
			cin >> key1;
			heapObject.pushHeap(key1);
		}
				break;
		case 4: {
			cout << "Podaj element do wyszukania" << endl;
			cin >> key1;
			heapObject.findE(key1);
		};
				break;
		case 5: {
			heapObject.disHeap();
		};
				break;
		default: {cout << "podales niewlasciwy numer!" << endl; }
				 break;
		}
	}
}
void rbtreeMenu() {
	anwser = NULL;
	while (anwser != 6) {
		cout << "\n 4. Red - Black Tree [Drzewo Czerowono-Czarne]";
		dispalyChoose();
		cin >> anwser;
		switch (anwser)
		{
		case 1: {
			displayObject = RBTree();
			//rbtreeObject = RBTreeT();
			for (int i = 0; i < file.size(); i++) {
				displayObject.pushTree(file[i]);
			}
		}
				break;
		case 2: {
			cout << "Podaj element do usuniecia" << endl;
			cin >> key1;
			displayObject.popTree(key1);
			// rbtreeObject.removeRBTT(key1);
		}
				break;
		case 3: {
			cout << "Podaj element do wstawienia" << endl;
			cin >> key1;
			displayObject.pushTree(key1);
		}
				break;
		case 4: {
			cout << "Podaj element do wyszukania" << endl;
			cin >> key1;
			displayObject.findElement(key1);
			//rbtreeObject.findRBTT(key1);
		}
				break;
		case 5: {
			//rbtreeObject.printRBTT();
			displayObject.display();
		}
				break;

		default: {cout << "podales niewlasciwy numer!" << endl; }
				 break;
		}
	}
}

void test_list() {

	double time_push_front[TEST_COUNT][ELEM_NUMBER];
	double time_push_back[TEST_COUNT][ELEM_NUMBER];
	double time_push_inside[TEST_COUNT][ELEM_NUMBER];
	double time_pop_front[TEST_COUNT][ELEM_NUMBER];
	double time_pop_back[TEST_COUNT][ELEM_NUMBER];
	double time_pop_inside[TEST_COUNT][ELEM_NUMBER];
	double time_find_element[TEST_COUNT][ELEM_NUMBER];

	double push_front_result = 0;
	double push_back_result = 0;
	double push_inside_result = 0;
	double pop_front_result = 0;
	double pop_back_result = 0;
	double pop_inside_result = 0;
	double find_element_result = 0;

	cout << "Testing list: \n" << ELEM_NUMBER << endl;

	for (int j = 0; j < TEST_COUNT; j++) {

		clock_t begin;
		clock_t end;

		//PUSH_FRONT
		List list1 = List();
		for (int i = 0; i < ELEM_NUMBER; i++) {
			begin = clock();
			list1.pushElemFront(rand() % 100);
			end = clock();
			time_push_front[j][i] = double(end - begin) / CLOCKS_PER_SEC;
		}

		//PUSH_BACK
		List list2 = List();
		for (int i = 0; i < ELEM_NUMBER; i++) {
			begin = clock();
			list2.pushElemEnd(rand() % 100);
			end = clock();
			time_push_back[j][i] = double(end - begin) / CLOCKS_PER_SEC;
		}

		//PUSH_RANDOM
		List list3 = List();
		for (int i = 0; i < ELEM_NUMBER; i++) {
			begin = clock();
			list3.pushElemInside(rand() % 100, rand() % (list3.count + 1));
			end = clock();
			time_push_inside[j][i] = double(end - begin) / CLOCKS_PER_SEC;
		}

		//FIND_ELEMENT
		for (int i = 0; i < ELEM_NUMBER; i++) {
			begin = clock();
			list1.findElem(rand() % 100);
			end = clock();
			time_find_element[j][i] = double(end - begin) / CLOCKS_PER_SEC;
		}

		//POP_FRONT
		for (int i = 0; i < ELEM_NUMBER; i++) {
			begin = clock();
			list1.popElemFront();
			end = clock();
			time_pop_front[j][i] = double(end - begin) / CLOCKS_PER_SEC;
		}

		//POP_BACK
		for (int i = 0; i < ELEM_NUMBER; i++) {
			begin = clock();
			list2.popElemEnd();
			end = clock();
			time_pop_back[j][i] = double(end - begin) / CLOCKS_PER_SEC;
		}

		//POP_RANDOM
		for (int i = 0; i < ELEM_NUMBER; i++) {
			begin = clock();
			list3.popElemInside(rand() % (list3.count + 1));
			end = clock();
			time_pop_inside[j][i] = double(end - begin) / CLOCKS_PER_SEC;
		}
	}
	for (int j = 0; j < TEST_COUNT; j++) {
		for (int i = 0; i < ELEM_NUMBER; i++) {
			push_front_result += time_push_front[j][i];
			push_back_result += time_push_back[j][i];
			push_inside_result += time_push_inside[j][i];
			pop_front_result += time_pop_front[j][i];
			pop_back_result += time_pop_back[j][i];
			pop_inside_result += time_pop_inside[j][i];
			find_element_result += time_find_element[j][i];
		}
	}

	push_front_result /= (TEST_COUNT * ELEM_NUMBER);
	push_back_result /= (TEST_COUNT * ELEM_NUMBER);
	push_inside_result /= (TEST_COUNT * ELEM_NUMBER);
	pop_front_result /= (TEST_COUNT * ELEM_NUMBER);
	pop_back_result /= (TEST_COUNT * ELEM_NUMBER);
	pop_inside_result /= (TEST_COUNT * ELEM_NUMBER);
	find_element_result /= (TEST_COUNT * ELEM_NUMBER);

	cout << "pushFront time:   " << push_front_result << "\n";
	cout << "pushBack time:    " << push_back_result << "\n";
	cout << "pushInside time:  " << push_inside_result << "\n";
	cout << "popFront time:    " << pop_front_result << "\n";
	cout << "popBack time:     " << pop_back_result << "\n";
	cout << "popInside time:   " << pop_inside_result << "\n";
	cout << "findElement time: " << find_element_result << "\n";
}
void test_array() {

	double time_push_front[TEST_COUNT][ELEM_NUMBER];
	double time_push_back[TEST_COUNT][ELEM_NUMBER];
	double time_push_inside[TEST_COUNT][ELEM_NUMBER];
	double time_pop_front[TEST_COUNT][ELEM_NUMBER];
	double time_pop_back[TEST_COUNT][ELEM_NUMBER];
	double time_pop_inside[TEST_COUNT][ELEM_NUMBER];
	double time_find_element[TEST_COUNT][ELEM_NUMBER];

	double push_front_result = 0;
	double push_back_result = 0;
	double push_inside_result = 0;
	double pop_front_result = 0;
	double pop_back_result = 0;
	double pop_inside_result = 0;
	double find_element_result = 0;

	cout << "Testing array: \n" << ELEM_NUMBER << endl;

	for (int j = 0; j < TEST_COUNT; j++) {

		clock_t begin;
		clock_t end;

		//PUSH_FRONT
		Array array1 = Array();
		for (int i = 0; i < ELEM_NUMBER; i++) {
			begin = clock();
			array1.pushFront(rand() % 100);
			end = clock();
			time_push_front[j][i] = double(end - begin) / CLOCKS_PER_SEC;
		}

		//PUSH_BACK
		Array array2 = Array();
		for (int i = 0; i < ELEM_NUMBER; i++) {
			begin = clock();
			array2.pushEnd(rand() % 100);
			end = clock();
			time_push_back[j][i] = double(end - begin) / CLOCKS_PER_SEC;
		}

		//PUSH_INSIDE
		Array array3 = Array();
		for (int i = 0; i < ELEM_NUMBER; i++) {
			begin = clock();
			array3.pushInside((rand() % (array3.numberOfIndex + 1)), (rand() % 100));
			end = clock();
			time_push_inside[j][i] = double(end - begin) / CLOCKS_PER_SEC;
		}

		//FIND_ELEMENT
		for (int i = 0; i < ELEM_NUMBER; i++) {
			begin = clock();
			array1.findElemArray(rand() % 100);
			end = clock();
			time_find_element[j][i] = double(end - begin) / CLOCKS_PER_SEC;
		}

		//POP_FRONT
		for (int i = 0; i < ELEM_NUMBER; i++) {
			begin = clock();
			array1.popFront();
			end = clock();
			time_pop_front[j][i] = double(end - begin) / CLOCKS_PER_SEC;
		}

		//POP_BACK
		for (int i = 0; i < ELEM_NUMBER; i++) {
			begin = clock();
			array2.popBack();
			end = clock();
			time_pop_back[j][i] = double(end - begin) / CLOCKS_PER_SEC;
		}

		//POP_INSIDE
		for (int i = 0; i < ELEM_NUMBER; i++) {
			begin = clock();
			//array3.popInside(rand() % 2);
			array3.popInside(rand() % (array3.numberOfIndex));
			end = clock();
			time_pop_inside[j][i] = double(end - begin) / CLOCKS_PER_SEC;
		}

	}

	for (int j = 0; j < TEST_COUNT; j++) {
		for (int i = 0; i < ELEM_NUMBER; i++) {
			push_front_result += time_push_front[j][i];
			push_back_result += time_push_back[j][i];
			push_inside_result += time_push_inside[j][i];
			pop_front_result += time_pop_front[j][i];
			pop_back_result += time_pop_back[j][i];
			pop_inside_result += time_pop_inside[j][i];
			find_element_result += time_find_element[j][i];
		}
	}

	push_front_result /= (TEST_COUNT * ELEM_NUMBER);
	push_back_result /= (TEST_COUNT * ELEM_NUMBER);
	push_inside_result /= (TEST_COUNT * ELEM_NUMBER);
	pop_front_result /= (TEST_COUNT * ELEM_NUMBER);
	pop_back_result /= (TEST_COUNT * ELEM_NUMBER);
	pop_inside_result /= (TEST_COUNT * ELEM_NUMBER);
	find_element_result /= (TEST_COUNT * ELEM_NUMBER);

	cout << "pushFront time:	" << push_front_result << "\n";
	cout << "pushBack time:		" << push_back_result << "\n";
	cout << "pushInside time:	" << push_inside_result << "\n";
	cout << "popFront time:		" << pop_front_result << "\n";
	cout << "popBack time:		" << pop_back_result << "\n";
	cout << "popInside time:	" << pop_inside_result << "\n";
	cout << "findElement time:	" << find_element_result << "\n";
};
void test_heap() {

	double time_push[TEST_COUNT][ELEM_NUMBER];
	double time_pop[TEST_COUNT][ELEM_NUMBER];
	double time_find_element[TEST_COUNT][ELEM_NUMBER];

	double push_result = 0;
	double pop_result = 0;
	double find_element_result = 0;

	cout << "Testing heap: \n " << ELEM_NUMBER << endl;

	for (int j = 0; j < TEST_COUNT; j++) {
		clock_t begin;
		clock_t end;

		//PUSH
		Heap heap1 = Heap();
		for (int i = 0; i < ELEM_NUMBER; i++) {
			begin = clock();
			heap1.pushHeap(rand() % (ELEM_NUMBER / 2));
			end = clock();
			time_push[j][i] = double(end - begin) / CLOCKS_PER_SEC;
		}

		//FIND_ELEMENT
		for (int i = 0; i < ELEM_NUMBER; i++) {
			begin = clock();
			heap1.findElement(rand() % (ELEM_NUMBER / 2));
			end = clock();
			time_find_element[j][i] = double(end - begin) / CLOCKS_PER_SEC;
		}

		//POP
		for (int i = 0; i < ELEM_NUMBER; i++) {
			begin = clock();
			heap1.popHeap(rand() % (ELEM_NUMBER / 2));
			end = clock();
			time_pop[j][i] = double(end - begin) / CLOCKS_PER_SEC;
		}

	}

	for (int j = 0; j < TEST_COUNT; j++) {
		for (int i = 0; i < ELEM_NUMBER; i++) {
			push_result += time_push[j][i];
			pop_result += time_pop[j][i];
			find_element_result += time_find_element[j][i];
		}
	}
	push_result /= (TEST_COUNT * ELEM_NUMBER);
	pop_result /= (TEST_COUNT * ELEM_NUMBER);
	find_element_result /= (TEST_COUNT * ELEM_NUMBER);

	cout << "push time:			" << push_result << "\n";
	cout << "pop time:			" << pop_result << "\n";
	cout << "find element time: " << find_element_result << "\n";
}
void test_rbtree() {

	double time_push[TEST_COUNT][ELEM_NUMBER];
	double time_pop[TEST_COUNT][ELEM_NUMBER];
	double time_find_element[TEST_COUNT][ELEM_NUMBER];

	double push_result = 0;
	double pop_result = 0;
	double find_element_result = 0;

	std::cout << "Testing Red-Black Tree: " << ELEM_NUMBER << endl;;

	for (int j = 0; j < TEST_COUNT; j++) {

		clock_t begin;
		clock_t end;

		//PUSH
		RBTreeT rbtree1 = RBTreeT();
		for (int i = 0; i < ELEM_NUMBER; i++) {
			begin = clock();
			rbtree1.insertRBTT(rand() % (ELEM_NUMBER));
			end = clock();
			time_push[j][i] = double(end - begin) / CLOCKS_PER_SEC;
		}

		//FIND_ELEMENT
		for (int i = 0; i < ELEM_NUMBER; i++) {
			begin = clock();
			rbtree1.findRBTT(rand() % (ELEM_NUMBER));
			end = clock();
			time_find_element[j][i] = double(end - begin) / CLOCKS_PER_SEC;
		}

		//POP
		for (int i = 0; i < ELEM_NUMBER; i++) {
			begin = clock();
			rbtree1.removeRBTT(rand() % (ELEM_NUMBER / 2));
			end = clock();
			time_pop[j][i] = double(end - begin) / CLOCKS_PER_SEC;
		}
	}

	for (int j = 0; j < TEST_COUNT; j++) {
		for (int i = 0; i < ELEM_NUMBER; i++) {
			push_result += time_push[j][i];
			pop_result += time_pop[j][i];
			find_element_result += time_find_element[j][i];
		}
	}
	push_result /= (TEST_COUNT * ELEM_NUMBER);
	pop_result /= (TEST_COUNT * ELEM_NUMBER);
	find_element_result /= (TEST_COUNT * ELEM_NUMBER);

	std::cout << "push time:		" << push_result << "\n";
	std::cout << "pop time:			" << pop_result << "\n";
	std::cout << "find element time:" << find_element_result << "\n";
}

vector<int> read_file(string filename) {
	ifstream file;
	file.open(filename);

	vector<int> vec;
	int size;

	if (file.is_open()) {
		string size_str;
		getline(file, size_str);
		size = stoi(size_str);
		for (int i = 0; i < size; i++) {
			string tmp;
			getline(file, tmp);
			vec.push_back(stoi(tmp));
		}
	}
	return vec;
}