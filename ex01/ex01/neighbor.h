#pragma once
#include <stdio.h>    
#include <stdlib.h> 
using namespace std;

typedef struct
{
	int value;
	Vertex* next;
	Vertex* prev;
	bool color = false;
}Vertex;

class Neighbor {
private:
	Vertex* _head = nullptr;
	Vertex* _tail = nullptr;
	int _length = 0;

public:
	~Neighbor();
	int getLength() { return _length; }
	Vertex* getHead() { return _head; }
	Vertex* getTail() { return _tail; }
	void addHead(int vertex);
	void addTail(int vertex);
	void deleteNeighbor(int vertex);
	void deleteNeighbor(Vertex* v);
	Vertex* find(int vertex);
	bool isEmpty() { return !!_head; }
};