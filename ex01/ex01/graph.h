#pragma once
#include <stdio.h>    
#include <stdlib.h> 
#include "dynamicArr.h"
#include "neighbor.h"
using namespace std;

class Graph {
private:
	DynamicArr<Neighbor> _vertexArr;


public:
	Graph() {};
	Graph(int numOfVertexes);
	void makeEmptyGraph(int numOfVertexes);
	bool isAdjacent(int u, int v);
	Neighbor* getAdjList(int u);
	void addEdge(int u, int v);
	void removeEdge(int u, int v);
	void printGraph();
	int isEmpty();
	Graph* transpose();


};