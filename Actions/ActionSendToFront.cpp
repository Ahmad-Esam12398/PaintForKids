#include "ActionSendToFront.h"

#include "..\ApplicationManager.h"

#include "..\GUI\GUI.h"
#include <iostream>

ActionSendToFront::ActionSendToFront(ApplicationManager* pApp) : Action(pApp)
{}

//Execute the action
void ActionSendToFront::Execute()
{
	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();

	int selectedIndexFigure = pManager->GetSelectedFigureID();
	if (selectedIndexFigure > -1 && pManager->GetSelectedCount() == 1)
	{
		pManager->SendToFront(selectedIndexFigure);
		pGUI->PrintMessage("The shape was brought to Front");
	}
	else {
		pGUI->PrintMessage("You Must Select A Shape First and Only One Shape...");
	}
}

void ActionSendToFront::Undo()
{}

void ActionSendToFront::Redo()
{}
