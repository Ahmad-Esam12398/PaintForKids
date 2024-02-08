#pragma once
#include "Actions/Action.h"
#include "ApplicationManager.h"
#include "Figures/CFigure.h"
class ActionMove : public Action
{
public:
	ActionMove(ApplicationManager* pMan);
	int SelectedCount;
	CFigure** SelectedFigures;
	virtual void Execute();
	void Undo();
	void Redo();
};

