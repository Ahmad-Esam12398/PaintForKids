#include "HistoryManager.h"


HistoryManager::HistoryManager() {}
HistoryManager::~HistoryManager() {
	while (!undoStack.empty()) {
		delete undoStack.top();
		undoStack.pop();
	}
	while (!redoStack.empty()) {
		delete redoStack.top();
		redoStack.pop();
	}
}

bool HistoryManager::addAction(Action* given)
{
	if (!given) {
		return false;
	}
	else
	{
		undoStack.push(given);
		return true;
	}
	return false;
}

bool HistoryManager::Undo()
{
	if (undoStack.empty()) {
		return false;
	}
	else
	{
		Action* temp = undoStack.top();
		temp->Undo();
		redoStack.push(temp);
		undoStack.pop();
		return true;
	}
	return false;
}

bool HistoryManager::Redo()
{
	if (redoStack.empty()) {
		return false;
	}
	else
	{
		Action* temp = redoStack.top();
		temp->Redo();
		redoStack.pop();
		return true;
	}
	return false;
}