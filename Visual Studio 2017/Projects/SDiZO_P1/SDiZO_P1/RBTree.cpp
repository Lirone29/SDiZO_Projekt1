#include "stdafx.h"
#include "RBTree.h"
#include <iomanip>
#include <cmath>
#include <queue>
#include <iostream>
#include <fstream>
#include <windows.h>
#include <cstdlib>
using namespace std;

void RBTree::release(RBTNode * p)
{
	if (p != S) //Porównanie do stra¿nika
	{
		void DFSRelease();					// Usuwa rekurencyjnie drzewo
		void DFSRelease();
		delete p;
	};
}

void RBTree::display()
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, BACKGROUND_INTENSITY);
	int size1 = size;
	int height = (int)ceil(log(size1) + 1);       // +1 handle the last leaves
	int width = (int)pow(2, height) * height;

	int elemNr = 0;
	for (int i = 0; i < height; i++)
		elemNr += (int)pow(2, i);
	std::vector<RBTNode*> vec;
	RBTNode* tmp = root;
	vec.push_back(tmp);
	for (int i = 1; i <= elemNr; i++) {
		if (tmp != S && tmp != nullptr) {
			vec.push_back(tmp->left);
			vec.push_back(tmp->right);
		}
		else {
			vec.push_back(nullptr);
			vec.push_back(nullptr);
		}
		tmp = vec[i];
	}

	// display (similar to heap print func)
	int index = 0;
	for (int i = 0; i <= height; i++) {                     // for each level of the tree
		for (int j = 0; j < pow(2, i); j++) {               // for each node on that tree level
			int digitWidth = 1;
			if (vec[index] != nullptr && vec[index] != S && vec[index]->data != 0) {
				digitWidth = (int)floor(log10(abs(vec[index]->data))) + 1;
				if (vec[index]->color == 'R') {
					digitWidth++;
				}
			}

			for (int x = 0; x < width / pow(2, i) - digitWidth; x++) {
				std::cout << " ";
			}

			if (vec[index] != S && vec[index] != nullptr) {
				if (vec[index]->color == 'R') {
					SetConsoleTextAttribute(hOut, FOREGROUND_RED | BACKGROUND_INTENSITY);
					std::cout << vec[index]->data << "R";
					SetConsoleTextAttribute(hOut, BACKGROUND_INTENSITY);
				}
				else {
					std::cout << vec[index]->data;
				}
			}
			else {
				if (vec[index] == S)
					std::cout << "S";
				else
					std::cout << "-";
			}
			index++;


			for (int x = 0; x < width / (pow(2, i)); x++) {
				std::cout << " ";
			}

		}
	}
	cout << endl << endl;
	SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
}

void RBTree::findElement(int key)
{
	bool anwser = findElementBool(key);
	if (anwser == true) std::cout << "Istnieje podany element!\n";
	else std::cout << "Nie ma podanego elementu w RB Tree\ n";
	return;
}

bool RBTree::findElementBool(int key)
{
	RBTNode *node = root;
	while (node != S && node->data != key)
	{
		if (key > node->data) {
			node = node->right;
		}
		else {
			node = node->left;
		}
	}
	return node != S;
}

RBTNode * RBTree::findRBT(int key)
{
	RBTNode * p;
	p = root;
	while ((p != S) && (p->data != key) && p != nullptr)
		if (key < p->data && (p->right != nullptr)) {
			p = p->left;
		}
		else {
			p = p->right;
		}
		if (p == S) return S;
		return p;
}

RBTNode * RBTree::minRBT(RBTNode * p)
{
	while (p->left != S) {
		p = p->left;
	}
	return p;
}

RBTNode * RBTree::succRBT(RBTNode *p)
{
	RBTNode * r;

	if (p != S)
	{
		if (p->right != S) return minRBT(p->right);
		else
		{
			r = p->parent;
			while ((r != S) && (p == r->right))
			{
				p = r;
				r = r->parent;
			}
			return r;
		}
	}
	return S;
}

RBTNode * RBTree::sibling(RBTNode * node)
{
	RBTNode * p = node->parent;
	;
	if (p == S) {
		return S;
	}
	if (node == p->left) {
		return p->right;
	}
	else {
		return p->left;
	}
}

RBTNode * RBTree::uncle(RBTNode * node)
{
	RBTNode * p = parent(node);
	RBTNode * g = grandparent(node);
	if (g == S) {
		return S;
	}
	return sibling(p);
}

RBTNode * RBTree::parent(RBTNode * node)
{
	return node->parent;;
}

RBTNode * RBTree::grandparent(RBTNode * node)
{
	RBTNode *p = parent(node);
	if (p == S) {
		return S;
	}
	return parent(p);
}

void RBTree::rot_L(RBTNode * A)
{
	RBTNode * p = A->right;

	A->right = p->left;
	if (A->right != S) //A==p->left
	{
		A->right->parent = p;
	}

	p->parent = A->parent;

	if (A->parent == S) {
		root = p;
	}
	else if (A == A->parent->left) { //przypisanie p wierzo³ka  wy¿ej jeœli istnieje parent A
		A->parent->left = p;
	}
	else {
		A->parent->right = p;
	}
	p->left = A;
	A->parent = p;
}

void RBTree::rot_R(RBTNode * A)
{
	RBTNode *p = A->left;
	A->left = p->right;

	if (A->left != S)
	{
		A->left->parent = p;
	}
	p->parent = A->parent;

	if (A->parent == S) {
		root = p;
	}
	else if (A == A->parent->right) { // Czy A jest prawym/lewym potomkiem
		A->parent->right = p;
	}
	else {
		A->parent->left = p;
	}
	p->right = A;
	A->parent = p;
}

void RBTree::pushTree(int key)
{
	RBTNode *newElem = new RBTNode;
	newElem->left = S;
	newElem->right = S;
	newElem->parent = root;
	newElem->data = key;
	RBTNode *tmp;

	if (newElem->parent == S) {
		root = newElem;
	}
	else {
		while (true) {
			if (key > newElem->parent->data && key != NULL) {              // if data is greater than newElems parent data
				if (newElem->parent->right == S) {
					newElem->parent->right = newElem;
					break;
				}
				newElem->parent = newElem->parent->right;
			}

			else if (key < newElem->parent->data) {       // if data is smaller than newElems parent data
				if (newElem->parent->left == S) {
					newElem->parent->left = newElem;
					break;
				}
				newElem->parent = newElem->parent->left;
			}
			else {                                        // if adding element is not possible (equal data)
				delete newElem;
				return;
			}
		}

		// fix red-black tree conditions
		newElem->color = 'R';
		while (newElem != root && newElem->parent->color == 'R') {
			if (newElem->parent == grandparent(newElem)->left) {
				tmp = uncle(newElem);

				// case 1 (uncle is red)
				if (tmp->color == 'R') {
					newElem->parent->color = 'B';
					tmp->color = 'B';
					grandparent(newElem)->color = 'R';
					newElem = grandparent(newElem);
					continue;
				}

				// case 2 (newElem is right child)
				if (newElem == parent(newElem)->right) {
					newElem = parent(newElem);
					rot_L(newElem);
				}

				// case 3
				parent(newElem)->color = 'B';
				grandparent(newElem)->color = 'R';
				rot_R(grandparent(newElem));
				break;
			}
			else {            // mirror cases
				tmp = uncle(newElem);

				// mirror case 1
				if (tmp->color == 'R') {
					parent(newElem)->color = 'B';
					tmp->color = 'B';
					grandparent(newElem)->color = 'R';
					newElem = grandparent(newElem);
					continue;
				}

				// mirror case 2
				if (newElem == parent(newElem)->left) {
					newElem = parent(newElem);
					rot_R(newElem);
				}

				// mirror case 3
				parent(newElem)->color = 'B';
				grandparent(newElem)->color = 'R';
				rot_L(grandparent(newElem));
				break;
			}
		}
	}
	root->color = 'B';
	size++;
}

void RBTree::popTree(int data) {      //deletes element with specific data
	RBTNode * deleteNode = findRBT(data);  //find element with given data
	if (deleteNode == S || deleteNode == nullptr) return;
	if (deleteNode != S) {                                //if element is found
		RBTNode* A, *B, *C;
		if (deleteNode->left == S || deleteNode->right == S) {    //if it has at least 1 children
			A = deleteNode;
		}
		else {
			A = succRBT(deleteNode);
		}

		// fixing parent pointers
		if (A->left != S) {                          //if successor has left child
			B = A->left;
		}
		else {
			B = A->right;
		}

		B->parent = A->parent;

		// fixing child pointers
		if (A->parent == S) {                        //if successor is root
			root = B;
		}
		else if (A == A->parent->left) {              //if successor is left child
			A->parent->left = B;                //skip successor in parent->left pointer
		}
		else {                                //if successor is right child
			A->parent->right = B;               //skip successor in parent->right pointer
		}


		// swap data if necessary
		if (A != deleteNode) {
			deleteNode->data = A->data;
		}

		// fix tree structure
		if (A->color == 'B') {
			while (B != root && B->color == 'B') {
				if (B == parent(B)->left) {
					C = sibling(B);

					// case 1
					if (C->color == 'R') {
						C->color = 'B';
						parent(B)->color = 'R';
						rot_L(parent(B));
						C = sibling(B);
					}

					// case 2
					if (C->left->color == 'B' && C->right->color == 'B') {
						C->color = 'R';
						B = parent(B);
						continue;
					}

					// case 3
					if (C->right->color == 'B') {
						C->left->color = 'B';
						C->color = 'R';
						rot_R(C);
						C = sibling(B);
					}

					// case 4
					C->color = parent(B)->color;
					parent(B)->color = 'B';
					C->right->color = 'B';
					rot_L(parent(B));

					B = root;


				}
				else {
					// mirror situations
					C = sibling(B);

					// mirror case 1
					if (C->color == 'R') {
						C->color = 'B';
						parent(B)->color = 'R';
						rot_R(parent(B));
						C = sibling(B);
					}

					// mirror case 2
					if ((C->left->color == 'B') && (C->right->color == 'B')) {
						C->color = 'R';
						B = parent(B);
						continue;
					}

					// mirror case 3
					if (C->left->color == 'B') {
						C->right->color = 'B';
						C->color = 'R';
						rot_L(C);
						C = sibling(B);
					}

					// mirror case 4
					C->color = parent(B)->color;
					parent(B)->color = 'B';
					C->left->color = 'B';
					rot_R(parent(B));

					B = root;
				}
			}
		}
		B->color = 'B';
		delete A;
	}

}
void RBTree::popMine(int key) {

	if (root == nullptr)
	{
		return;
	}
	RBTNode * deleteNode = findRBT(key); // deleteNode == X
	RBTNode *W = nullptr;
	RBTNode *Y = nullptr;
	RBTNode *Z = nullptr;
	//K1
	if ((deleteNode == S) || (deleteNode == nullptr))return;
	if ((deleteNode->left == S) || (deleteNode->right == S))
	{
		Y = deleteNode;
	}
	else
	{
		Y = succRBT(deleteNode);
	}
	//K2
	if (Y->left != S || Y != nullptr) Z = Y->left;
	else
	{
		Z = Y->right;
	}

	Z->parent = Y->parent;
	if (Y->parent == S || Y->parent == nullptr) {
		root = Z;
	}
	else
	{
		if (Y = Y->parent->left) Y->parent->left = Z;
		else
		{
			Y->parent->right = Z;
		}
	}
	if (Y != deleteNode) deleteNode->data = Y->data;
	if (Y->color != 'R')
		while ((Z != root) && (Z->color == 'B')) {
			//K11
			if (Z != Z->parent->right) {
				W = Z->parent->right;

				if (W->color != 'B') {
					W->color = 'B';
					Z->parent->color = 'R';
					rot_L(parent(Z));
					W = Z->parent->right;
				}
				if ((W->left->color == 'R') || (W->right->color == 'R')) {

					if (W->right->color != 'R')
					{
						W->left->color = 'B';
						W->color = 'R';
						rot_R(W);
						W = Z->parent->right;
						W->color = Z->parent->color;
						Z->parent->color = 'B';
						W->right->color = 'B';
						rot_L(Z->parent);
						Z = root;
						continue;
					}
				}
				W->color = 'R';
				Z = Z->parent;
				continue;
			}

			W = Z->parent->left;

			//Przypadki lustrzane
			if (W->color != 'B') {
				W->color = 'B';
				Z->parent->color = 'R';
				rot_R(Z->parent);
				W = Z->parent->left;
			}
			//K38
			if ((W->left->color != 'R') && (W->right->color != 'R')) {
				W->color = 'R';
				Z = Z->parent;
				continue;
			}
			//K42
			if ((W->left->color != 'R')) { //&& ((W->left->color == 'R') || (W->right->color == 'R')
				W->right->color = 'B';
				W->color = 'R';
				rot_L(W);
				W = Z->parent->left;
			}
			//K47
			W->color = Z->parent->color;
			Z->parent->color = 'B';
			W->left->color = 'B';
			rot_R(Z->parent);
			Z = root;
			continue;
		}

	//K51
	Z->color = 'B';
	delete Y;
	return;
}

RBTree::RBTree()
{
	S = new RBTNode;
	// declare sentinel
	S->left = nullptr;
	S->right = nullptr;
	S->color = 'B';
	S->data = NULL;
	root = S;                           // make root sentinel
	size = 0;
}

RBTree::~RBTree()
{
	release(root);
}
