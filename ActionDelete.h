#pragma once
#include "Actions/Action.h"
#include "Figures/CFigure.h"
class ActionDelete : public Action
{
	int DeletedID; // The ID of the Deleted Element
	int SelectedCount;
	CFigure** SelectedFigures;
public:
	ActionDelete(ApplicationManager* pApp);

	virtual void Execute();
	void Undo();
	void Redo();
};

