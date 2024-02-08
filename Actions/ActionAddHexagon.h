#pragma once

#include "Action.h"

//Add Hexagon Action class
class ActionAddHexagon : public Action
{
public:
	ActionAddHexagon(ApplicationManager* pApp);

	//Add ellipse to the ApplicationManager
	virtual void Execute();
	void Undo();
	void Redo();

};