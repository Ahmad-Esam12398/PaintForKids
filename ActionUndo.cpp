#include "ActionUndo.h"
#include "ApplicationManager.h"

ActionUndo::ActionUndo(ApplicationManager* pApp) :Action(pApp)
{}
void ActionUndo::Execute()
{
	GUI* pGUI = pManager->GetGUI();
	pManager->Undo();
	pGUI->ClearDrawArea();
	pGUI->CreateColorBar();
}
void ActionUndo::Undo()
{}

void ActionUndo::Redo()
{}

