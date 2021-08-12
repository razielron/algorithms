#pragma once
#include <stdio.h>    
#include <stdlib.h> 

using namespace std;

typedef struct
{
	int vertex;
	Node* next;
	Node* prev;
}Node;

class Queue {
	private:
		Node* _head = nullptr;
		Node* _tail = nullptr; 

	public:
		~Queue();
		void makeEmpty();
		void enqueue(int vertex);
		int dequeue();
		int front() { return _head->vertex; };
		bool isEmpty() { return !!_head; };

};