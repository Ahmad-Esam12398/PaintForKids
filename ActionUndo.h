#pragma once
#include "Actions/Action.h"
class ActionUndo : public Action
{
	public:
	ActionUndo(ApplicationManager* pApp);
	virtual void Execute();
	void Undo();
	void Redo();
};

