#pragma once
#include "Actions/Action.h"
#include <iostream>
#include <stack>

using namespace std;
class HistoryManager
{
	public:
	HistoryManager();
	~HistoryManager();
	//those will turn true when success 
	bool HistoryManager::addAction(Action* item);
	bool Undo();
	bool Redo();

	private:
		stack<Action*> undoStack;
		stack<Action*> redoStack;
};

