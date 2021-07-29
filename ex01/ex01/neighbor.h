#pragma once
#include <stdio.h>    
#include <stdlib.h> 
using namespace std;

typedef struct
{
	int value;
	Vertex* next;
	Vertex* prev;
}Vertex;

class Neighbor {
private:
	Vertex* _head = nullptr;
	Vertex* _tail = nullptr;
	int _length = 0;

public:
	void addHead(int vertex);
	void addTail(int vertex);
	void deleteNeighbor(int vertex);
	Vertex* find(int vertex);
};