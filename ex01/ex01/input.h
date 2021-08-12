#pragma once
#include <stdio.h>    
#include <stdlib.h> 
#include "dynamicArr.h"
#include "neighbor.h"
#include "graph.h"
using namespace std;

class Input {
private:
	int _numOfVertex;
	int _source;
	int _target;

public:
	int getNumOfVertex() { return _numOfVertex; };
	void inputNumOfVertex();
	int getSource() { return _source; };
	void inputSource();
	int getSource() { return _target; };
	void inputTarget();


};
