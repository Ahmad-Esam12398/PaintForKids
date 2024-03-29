#include "ActionChangeDrawColor.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"

ActionChangeDrawColor::ActionChangeDrawColor(ApplicationManager* pApp) :Action(pApp)
{}

void ActionChangeDrawColor::Execute() {
	//Get a Pointer to the Input / Output Interfaces

	GUI* pGUI = pManager->GetGUI();
	pGUI->PrintMessage("Choose Drawing Color Color");
	UI.InterfaceMode = MODE_COLOR;
	IsSelected = pManager->AnySelected();

	//Reads the input draw color
	if (!pManager->GetColor(DrawClr))
		IsColor = false;
	else
		IsColor = true;

	if (IsColor) {
		if (IsSelected)
		{
			OldDrawClr = DrawClr;
			pManager->changeDrawColor(DrawClr);
		}
		else
		{

			pGUI->setCrntDrawColor(DrawClr);
		}
	}
	pGUI->CreateDrawToolBar();
}

void ActionChangeDrawColor::Undo() {
	GUI* pGUI = pManager->GetGUI();
	if (IsSelected)
	{
		pManager->changeDrawColor(OldDrawClr);
	}
	else
	{
		pGUI->setCrntDrawColor(OldDrawClr);
	}
}

void ActionChangeDrawColor::Redo() {
	GUI* pGUI = pManager->GetGUI();
	if (IsSelected)
	{
		pManager->changeDrawColor(DrawClr);
	}
	else
	{
		pGUI->setCrntDrawColor(DrawClr);
	}
}