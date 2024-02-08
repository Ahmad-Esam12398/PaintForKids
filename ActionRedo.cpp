#include "ActionRedo.h"
#include "ApplicationManager.h"


ActionRedo::ActionRedo(ApplicationManager* pApp) :Action(pApp)
{}
void ActionRedo::Execute()
{
	GUI* pGUI = pManager->GetGUI();
	pManager->Redo();
	pGUI->ClearDrawArea();
	pGUI->CreateColorBar();
}
void ActionRedo::Undo()
{}

void ActionRedo::Redo()
{}
