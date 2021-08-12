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

DynamicArr<int>* Graph::BFS(int vertex) {
	DynamicArr<int>* d = new DynamicArr<int>();
	DynamicArr<Neighbor> L;
	for (int i = 0; i <= _vertexArr.size(); i++) {
		d->push_back(-1);
	}
	L[0].addTail(vertex);
	d->insertAt(0, vertex);
	int i = 0;
	while (L[i].isEmpty()) {
		Vertex* vertexL= L[i].getHead();
		while (vertexL) {
			Vertex* vertexLAdj = _vertexArr.at(vertexL->value).getHead();
			while (vertexLAdj) {
				vertexLAdj->color = true;
				if ((*d)[vertexLAdj->value] == -1) {
					d->insertAt(i+1, vertexLAdj->value);
					if (L.size() <= i + 1) {
						L.resize();
					}
					L.at(i + 1).addTail(vertexLAdj->value);
				}
			}
		}
		i = i + 1;
	}
	return d;
}

void Graph::deleteLongPath(DynamicArr<int>* d) {
	for (int i = 0;i < _vertexArr.size(); i++) {
		Vertex* adjTemp = _vertexArr[i].getHead();
		while (adjTemp) {
			if ((*d)[adjTemp->value] != ((*d)[i] + 1))
				_vertexArr[i].deleteNeighbor(adjTemp);
		}
	}
}

void Graph::deleteUnaccessibleEdges() {
	for (int i = 0;i < _vertexArr.size(); i++) {
		Vertex* adjTemp = _vertexArr[i].getHead();
		while (adjTemp) {
			if (adjTemp->color)
				_vertexArr[i].deleteNeighbor(adjTemp);
		}
	}
}


Graph* Graph::algorithm(int s, int t) {
	Graph* transgender;
	Graph* H;
	DynamicArr<int>* d = this->BFS(s);
	this->deleteLongPath(d);
	transgender = this->transpose();
	transgender->BFS(t);
	transgender->deleteUnaccessibleEdges();
	H = transgender->transpose();
}
