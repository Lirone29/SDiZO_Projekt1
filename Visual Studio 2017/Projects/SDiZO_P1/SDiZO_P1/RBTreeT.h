#pragma once
#pragma once
#include <iostream>

using namespace std;
/*
color = "B"  w�ze� czarny (Black)
color = "R"  w�ze� czerwony (Red)
*/

struct RBTNodeT {
	RBTNodeT * up;
	RBTNodeT * left;
	RBTNodeT * right;
	char color;
	int key;
};
// Definicja typu obiektowego TRBTree
class RBTreeT
{
private:
	RBTNodeT S;             // W�ze� stra�nika
	RBTNodeT * root;        // Korze� drzewa czerwono-czarnego
	int size;

public:
	void printRBTT();
	RBTreeT();             // Konstruktor klasy
	~RBTreeT();            // Destruktor klasy
	void DFSReleaseT(RBTNodeT * p);			// Usuwa rekurencyjnie drzewo

	RBTNodeT * findRBTT(int k);			// Wyszukuje w�ze� o kluczu k
	RBTNodeT * minRBTT(RBTNodeT * p);	// Wyszukuje najmniejszy w�ze� w p
	RBTNodeT * succRBTT(RBTNodeT * p);	// Wyszukuje nast�pnik p
	void rot_LT(RBTNodeT * A);			// Rotacja w lewo wzgl�dem A
	void rot_RT(RBTNodeT * A);			// Rotacja w prawo wzgl�dem A
	void insertRBTT(int k);				// Wstawia w�ze� o kluczu k
	void removeRBTT(int k);				// Usuwa w�ze� X

};



