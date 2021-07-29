#include "graph.h"

Graph::Graph(int numOfVertexes) {
	_vertexArr.resize(numOfVertexes);
}
void Graph::makeEmptyGraph(int numOfVertexes) {
	_vertexArr.resize(numOfVertexes);
}

bool Graph::isAdjacent(int u, int v) {
	return !!_vertexArr[u].find(v);
}

Neighbor* Graph::getAdjList(int u) {
	return &_vertexArr[u];
}

void Graph::addEdge(int u, int v) {
	_vertexArr[u].addTail(v);
}

void Graph::removeEdge(int u, int v) {
	_vertexArr[u].deleteNeighbor(v);
}

void Graph::printGraph() {
	Vertex* temp = nullptr;
	for (int i = 0;i < _vertexArr.size();i++) {
		temp = _vertexArr[i].getHead();
		while (temp) {
			cout << "(" << i << ", " << temp->value << ") ";
			temp = temp->next;
		}
		cout << "\n";
	}
}

int Graph::isEmpty() {
	if (_vertexArr.size())
		return 0;
	return 1;
}

Graph* Graph::transpose() {
	Vertex* temp = nullptr;
	Graph* transgender = new Graph(_vertexArr.size());
	for (int i = 0;i < _vertexArr.size();i++) {
		temp = _vertexArr[i].getHead();
		while (temp) {
			transgender->addEdge(temp->value, i);
			temp = temp->next;
		}
	}
	return transgender;
}
