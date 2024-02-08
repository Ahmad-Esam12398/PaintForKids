#pragma once
#include "Action.h"

//Add Circle Action class
class ActionAddEllipse : public Action
{
public:
	ActionAddEllipse(ApplicationManager* pApp);

	//Add Circle to the ApplicationManager
	virtual void Execute();
	virtual void Undo(); //Undo this action
	void Redo(); //Redo this action

};
