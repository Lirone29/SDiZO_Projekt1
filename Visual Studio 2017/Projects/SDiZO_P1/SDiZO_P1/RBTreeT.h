#pragma once
#pragma once
#include <iostream>

using namespace std;
/*
color = "B"  wêze³ czarny (Black)
color = "R"  wêze³ czerwony (Red)
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
	RBTNodeT S;             // Wêze³ stra¿nika
	RBTNodeT * root;        // Korzeñ drzewa czerwono-czarnego
	int size;

public:
	void printRBTT();
	RBTreeT();             // Konstruktor klasy
	~RBTreeT();            // Destruktor klasy
	void DFSReleaseT(RBTNodeT * p);			// Usuwa rekurencyjnie drzewo

	RBTNodeT * findRBTT(int k);			// Wyszukuje wêze³ o kluczu k
	RBTNodeT * minRBTT(RBTNodeT * p);	// Wyszukuje najmniejszy wêze³ w p
	RBTNodeT * succRBTT(RBTNodeT * p);	// Wyszukuje nastêpnik p
	void rot_LT(RBTNodeT * A);			// Rotacja w lewo wzglêdem A
	void rot_RT(RBTNodeT * A);			// Rotacja w prawo wzglêdem A
	void insertRBTT(int k);				// Wstawia wêze³ o kluczu k
	void removeRBTT(int k);				// Usuwa wêze³ X

};



