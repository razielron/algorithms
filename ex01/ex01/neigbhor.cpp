#include "neighbor.h"

void Neighbor::addHead(int vertex) {
	Vertex* temp = _head;
	_head = new Vertex();
	_head->value = vertex;
	_head->next = temp;
	_head->prev = nullptr;
	temp->prev = _head;
}

void Neighbor::addTail(int vertex) {
	Vertex* temp = new Vertex();
	temp->value = vertex;
	temp->next = nullptr;
	_tail->next = temp;
	temp->prev = _tail;
	_tail = temp;
}

void Neighbor::deleteNeighbor(int vertex) {
	Vertex* temp = find(vertex);

	if(temp) {
		Vertex* prev = temp->prev;
		Vertex* next = temp->next;
		prev->next = next;
		next->prev = prev;
		delete temp;
	}
}

Vertex* Neighbor::find(int vertex) {
	Vertex* temp = _head;

	while(temp) {
		if (temp->value == vertex)
			return temp;
		temp = temp->next;
	}
	return nullptr;
}