#pragma once
#include "Actions/Action.h"
class ActionRedo : public Action
{
public:
	ActionRedo(ApplicationManager* pApp);
	virtual void Execute();
	void Undo();
	void Redo();
};

