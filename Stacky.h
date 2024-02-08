#pragma once
#include "Actions/Action.h"
class Stacky
{
private:
	int top;
	Action* items[100]; //Max no. of elements in stack
public:
	Stacky();
	bool isEmpty();
	bool isFull();
	void push(Action* p);
	Action* pop();
};

