#pragma once
#include <fstream>
#include <string>
#include <vector>
using namespace std;
/*
LEGENDA:

color = "B"  wêze³ czarny (Black)
color = "R"  wêze³ czerwony (Red)
*/
struct RBTNode {
	RBTNode * parent;
	RBTNode * left;
	RBTNode * right;
	char color;
	int data;
};
class RBTree
{

private:
	RBTNode * S;
	int size;

public:
	RBTNode * root;

	void release(RBTNode * p);				// Usuwa rekurencyjnie drzewo 
	void findElement(int key);
	bool findElementBool(int key);

	RBTNode * findRBT(int k);		// Wyszukuje wêze³ o kluczu k
	RBTNode * minRBT(RBTNode * p);	// Wyszukuje najmniejszy wêze³ w p
	RBTNode * succRBT(RBTNode * p);	// Wyszukuje nastêpnik p

	RBTNode* sibling(RBTNode*node);
	RBTNode* uncle(RBTNode*node);
	RBTNode* parent(RBTNode*node);
	RBTNode* grandparent(RBTNode*node);

	void rot_L(RBTNode * A); // Rotacja w lewo wzglêdem A
	void rot_R(RBTNode * A); // Rotacja w prawo wzglêdem A

	void pushTree(int key);
	void popTree(int key);
	void popMine(int key);

	void display();
	RBTree();
	~RBTree();
};

