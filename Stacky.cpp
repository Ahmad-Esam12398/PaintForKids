#include "Stacky.h"

Stacky::Stacky()
{
	top = -1;
	for(int i=0;i<100;i++)
		items[i]=NULL;
}

bool Stacky::isEmpty()
{
	return(top == -1);
}

bool Stacky::isFull()
{
	return(top == 99);
}

void Stacky::push(Action* p)
{
	if(isFull())
		return;
	top++;
	items[top] = p;
}

Action* Stacky::pop()
{
	if(isEmpty())
		return NULL;
	Action* p = items[top];
	items[top] = NULL;
	top--;
	return p;
}
