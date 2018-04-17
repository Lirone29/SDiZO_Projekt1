#include "stdafx.h"
#include "RBTreeT.h"


#include "stdafx.h"
#include "RBTreeT.h"
#include <iomanip>
#include <cmath>
#include <queue>
#include <iostream>
#include <fstream>
#include <windows.h>
#include <cstdlib>
#include <math.h>
#include <string>
#include <vector>

using namespace std;

RBTreeT::RBTreeT()
{
	S.color = 'B';          // Inicjujemy stra¿nika
	S.up = &S;
	S.left = &S;
	S.right = &S;
	root = &S;           // Korzeñ wskazuje stra¿nika
}

// Destruktor drzewa
RBTreeT::~RBTreeT()
{
	DFSReleaseT(root);       // Rekurencyjnie usuwamy wêz³y
}

// Usuwa rekurencyjnie drzewo czerwono-czarne
void RBTreeT::DFSReleaseT(RBTNodeT * p)
{
	if (p != &S && p != nullptr)
	{
		DFSReleaseT(p->left);   // usuwamy lewe poddrzewo
		DFSReleaseT(p->right);  // usuwamy prawe poddrzewo
		delete p;              // usuwamy sam wêze³
	}
}

// Wypisuje zawartoœæ drzewa
void RBTreeT::printRBTT()
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
	std::vector<RBTNodeT*> vec;
	RBTNodeT* tmp = root;
	vec.push_back(tmp);
	for (int i = 1; i <= elemNr; i++) {
		if (tmp != &S && tmp != nullptr) {
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
			if (vec[index] != nullptr && vec[index] != &S && vec[index]->key != 0) {
				digitWidth = (int)floor(log10(abs(vec[index]->key))) + 1;
				if (vec[index]->color == 'R') {
					digitWidth++;
				}
			}

			for (int x = 0; x < width / pow(2, i) - digitWidth; x++) {
				std::cout << " ";
			}

			if (vec[index] != &S && vec[index] != nullptr) {
				if (vec[index]->color == 'R') {
					SetConsoleTextAttribute(hOut, FOREGROUND_RED | BACKGROUND_INTENSITY);
					std::cout << vec[index]->key << "R";
					SetConsoleTextAttribute(hOut, BACKGROUND_INTENSITY);
				}
				else {
					std::cout << vec[index]->key;
				}
			}
			else {
				if (vec[index] == &S)
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

// Wyszukuje wêze³ o kluczu k
// Jeœli wêze³ nie zostanie znaleziony, to zwraca
// wskazanie puste NULL
RBTNodeT * RBTreeT::findRBTT(int k)
{
	RBTNodeT * p;

	p = root;
	while ((p != &S) && (p->key != k))
		if (k < p->key) p = p->left;
		else           p = p->right;
		if (p == &S) return NULL;
		return p;
}

// Wyszukuje najmniejszy wêze³ w poddrzewie
// o korzeniu p
RBTNodeT * RBTreeT::minRBTT(RBTNodeT * p)
{
	if (p != &S)
		while (p->left != &S) p = p->left;
	return p;
}

// Zwraca nastêpnik p
RBTNodeT * RBTreeT::succRBTT(RBTNodeT * p)
{
	RBTNodeT * r;

	if (p != &S)
	{
		if (p->right != &S) return minRBTT(p->right);
		else
		{
			r = p->up;
			while ((r != &S) && (p == r->right))
			{
				p = r;
				r = r->up;
			}
			return r;
		}
	}
	return &S;
}

// Wykonuje rotacjê w lewo wzglêdem A
void RBTreeT::rot_LT(RBTNodeT * A)
{
	RBTNodeT * B, *p;

	B = A->right;
	if (B != &S)
	{
		p = A->up;
		A->right = B->left;
		if (A->right != &S) A->right->up = A;

		B->left = A;
		B->up = p;
		A->up = B;

		if (p != &S)
		{
			if (p->left == A) p->left = B; else p->right = B;
		}
		else root = B;
	}
}

// Wykonuje rotacjê w prawo wzglêdem A
void RBTreeT::rot_RT(RBTNodeT * A)
{
	RBTNodeT * B, *p;

	B = A->left;
	if (B != &S)
	{
		p = A->up;
		A->left = B->right;
		if (A->left != &S) A->left->up = A;

		B->right = A;
		B->up = p;
		A->up = B;

		if (p != &S)
		{
			if (p->left == A) p->left = B; else p->right = B;
		}
		else root = B;
	}
}

// Wstawia do drzewa wêze³ o kluczu k
void RBTreeT::insertRBTT(int k)
{
	RBTNodeT * X, *Y;

	X = new RBTNodeT;        // Tworzymy nowy wêze³
	X->left = &S;          // Inicjujemy pola
	X->right = &S;
	X->up = root;
	X->key = k;
	if (X->up == &S) root = X; // X staje siê korzeniem
	else
		while (true)             // Szukamy liœcia do zast¹pienia przez X
		{
			if (k < X->up->key)
			{
				if (X->up->left == &S)
				{
					X->up->left = X;  // X zastêpuje lewy liœæ
					break;
				}
				X->up = X->up->left;
			}
			else
			{
				if (X->up->right == &S)
				{
					X->up->right = X; // X zastêpuje prawy liœæ
					break;
				}
				X->up = X->up->right;
			}
		}
	X->color = 'R';         // Wêze³ kolorujemy na czerwono
	while ((X != root) && (X->up->color == 'R'))
	{
		if (X->up == X->up->up->left)
		{
			Y = X->up->up->right; // Y -> wujek X

			if (Y->color == 'R')  // Przypadek 1
			{
				X->up->color = 'B';
				Y->color = 'B';
				X->up->up->color = 'R';
				X = X->up->up;
				continue;
			}

			if (X == X->up->right) // Przypadek 2
			{
				X = X->up;
				rot_LT(X);
			}

			X->up->color = 'B'; // Przypadek 3
			X->up->up->color = 'R';
			rot_RT(X->up->up);
			break;
		}
		else
		{                  // Przypadki lustrzane
			Y = X->up->up->left;

			if (Y->color == 'R') // Przypadek 1
			{
				X->up->color = 'B';
				Y->color = 'B';
				X->up->up->color = 'R';
				X = X->up->up;
				continue;
			}

			if (X == X->up->left) // Przypadek 2
			{
				X = X->up;
				rot_RT(X);
			}

			X->up->color = 'B'; // Przypadek 3
			X->up->up->color = 'R';
			rot_LT(X->up->up);
			break;
		}
	}
	root->color = 'B';
	size++;
}

// Usuwa z drzewa wêze³ X
void RBTreeT::removeRBTT(int key)
{
	RBTNodeT * X = findRBTT(key);
	RBTNodeT * W, *Y, *Z;
	if (X == nullptr || X == &S) return;
	if ((X->left == &S) || (X->right == &S)) Y = X;
	else                                    Y = succRBTT(X);

	if (Y->left != &S) Z = Y->left;
	else              Z = Y->right;

	Z->up = Y->up;

	if (Y->up == &S) root = Z;
	else if (Y == Y->up->left) Y->up->left = Z;
	else                      Y->up->right = Z;

	if (Y != X) X->key = Y->key;

	if (Y->color == 'B')   // Naprawa struktury drzewa czerwono-czarnego
		while ((Z != root) && (Z->color == 'B'))
			if (Z == Z->up->left)
			{
				W = Z->up->right;

				if (W->color == 'R')
				{              // Przypadek 1
					W->color = 'B';
					Z->up->color = 'R';
					rot_LT(Z->up);
					W = Z->up->right;
				}

				if ((W->left->color == 'B') && (W->right->color == 'B'))
				{              // Przypadek 2
					W->color = 'R';
					Z = Z->up;
					continue;
				}

				if (W->right->color == 'B')
				{              // Przypadek 3
					W->left->color = 'B';
					W->color = 'R';
					rot_RT(W);
					W = Z->up->right;
				}

				W->color = Z->up->color; // Przypadek 4
				Z->up->color = 'B';
				W->right->color = 'B';
				rot_LT(Z->up);
				Z = root;         // To spowoduje zakoñczenie pêtli
			}
			else
			{                // Przypadki lustrzane
				W = Z->up->left;

				if (W->color == 'R')
				{              // Przypadek 1
					W->color = 'B';
					Z->up->color = 'R';
					rot_RT(Z->up);
					W = Z->up->left;
				}

				if ((W->left->color == 'B') && (W->right->color == 'B'))
				{              // Przypadek 2
					W->color = 'R';
					Z = Z->up;
					continue;
				}

				if (W->left->color == 'B')
				{              // Przypadek 3
					W->right->color = 'B';
					W->color = 'R';
					rot_LT(W);
					W = Z->up->left;
				}

				W->color = Z->up->color;  // Przypadek 4
				Z->up->color = 'B';
				W->left->color = 'B';
				rot_RT(Z->up);
				Z = root;         // To spowoduje zakoñczenie pêtli
			}

	Z->color = 'B';

	delete Y;
}
