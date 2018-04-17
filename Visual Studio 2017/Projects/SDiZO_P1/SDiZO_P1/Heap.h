#pragma once
class Heap
{
private:
	int size;
	int* array;

	int leftDesc(int index);
	int rightDesc(int index);
	int parent(int index);

	void fixUp();
	void fixDown(int index);
	int findElement2(int data);
	bool findElementRec(int index, int data);
	void popRoot();

public:
	Heap();
	~Heap();

	void findE(int key);
	void findERec(int index, int key);
	void disHeap();

	bool findElement(int data);
	void pushHeap(int key);
	void popHeap(int key);
};

