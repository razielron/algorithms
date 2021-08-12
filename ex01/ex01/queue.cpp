#include "queue.h"

Queue::~Queue() {
	makeEmpty();
}

void Queue::makeEmpty() {
	Node* temp = _head->next;
	while (temp != nullptr) {
		delete _head;
		_head = temp;
		temp = _head->next;
	}
	_head = nullptr;
	_tail = nullptr;
}

void Queue::enqueue(int vertex) {
	Node* newNode = new Node();
	newNode->vertex = vertex;
	newNode->next = nullptr;
	newNode->prev = _tail;
	_tail = newNode;
	if (!_head)
		_head = newNode;
}

int Queue::dequeue() {
	Node* temp = _head->next;
	int front = _head->vertex;
	delete _head;
	_head = temp;
	_head->prev = nullptr;
	return front;
}
