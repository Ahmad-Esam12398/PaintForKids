#include "ActionResize.h"
#include "ApplicationManager.h"
#include "GUI/GUI.h"



ActionResize::ActionResize(ApplicationManager* pApp) : Action(pApp)
{}

void ActionResize::Execute()
{
	GUI* pGui = pManager->GetGUI();
	UI.InterfaceMode = MODE_SIZE;
	
	if (pManager->GetSelectedCount() == 1)
	{
		pGui->ClearToolBarArea();
		pGui->ClearDrawArea();
		pManager->UpdateInterface();
		pGui->CreateResizeToolBar();
		ActionType pAct = pGui->MapInputToActionType();
		selected = pManager->GetSelectedFigure();
		if (pAct == HALF)
		{
			selected->Resize(pGui, 0.5);
		}
		else if (pAct == QUARTER)
		{
			selected->Resize(pGui, 0.25);
		}
		else if (pAct == DOUBLE1)
		{
			selected->Resize(pGui, 2.0);
		}
		else if (pAct == QUADRUPLE)
		{
			selected->Resize(pGui, 4.0);
		}
		else if (pAct == GO_BACK)
		{
			Action* act = pManager->CreateAction(GO_BACK);
			act->Execute();
			return;
		}

		pGui->ClearDrawArea(); //Clear The area to update
		pManager->UpdateInterface();
		Execute();   //to call it Again (Recursive)
	}
	else{
		pGui->PrintMessage("Plz Select One Figure to Proceed!");
		UI.InterfaceMode = MODE_DRAW;
	}
}

void ActionResize::Undo()
{
}

void ActionResize::Redo()
{
}