#pragma once
#include <fstream>
#include <string>
#include <vector>
using namespace std;
/*
LEGENDA:

color = "B"  w�ze� czarny (Black)
color = "R"  w�ze� czerwony (Red)
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

	RBTNode * findRBT(int k);		// Wyszukuje w�ze� o kluczu k
	RBTNode * minRBT(RBTNode * p);	// Wyszukuje najmniejszy w�ze� w p
	RBTNode * succRBT(RBTNode * p);	// Wyszukuje nast�pnik p

	RBTNode* sibling(RBTNode*node);
	RBTNode* uncle(RBTNode*node);
	RBTNode* parent(RBTNode*node);
	RBTNode* grandparent(RBTNode*node);

	void rot_L(RBTNode * A); // Rotacja w lewo wzgl�dem A
	void rot_R(RBTNode * A); // Rotacja w prawo wzgl�dem A

	void pushTree(int key);
	void popTree(int key);
	void popMine(int key);

	void display();
	RBTree();
	~RBTree();
};

