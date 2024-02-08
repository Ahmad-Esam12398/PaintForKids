#pragma once
#ifndef ACTION_BRING_FRONT_H
#define ACTION_BRING_FRONT_H

#include "Action.h"

//Add Ellipse Action class
class ActionSendToFront : public Action
{
public:
	ActionSendToFront(ApplicationManager* pApp);

	virtual void Execute();
	void Undo();
	void Redo();
};

#endif