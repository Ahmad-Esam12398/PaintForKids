#include "ActionMove.h"
#include "Actions/Action.h"
#include "ApplicationManager.h"


ActionMove::ActionMove(ApplicationManager* pMan) : Action(pMan) {};

void ActionMove::Execute()
{
	GUI* pGUI = pManager->GetGUI();
	SelectedFigures = pManager->GetSelectedFigures();	//get selected figures Array
	SelectedCount = pManager->GetSelectedCount();	//Get selected figures count
	if (SelectedCount != 1)	
	{
		pGUI->PrintMessage("PLZ select one figure");
	}
	else {

		pGUI->PrintMessage("Click on the new position");
		pManager->moveFigure();
		pManager->ClearSelectedFigures();
		pGUI->PrintMessage("Completed!");
	}
}

void ActionMove::Undo() {}
void ActionMove::Redo() {}
