#include "ActionSwitchToDrawMode.h"
#include "Actions/Action.h"
#include "ApplicationManager.h"


ActionSwitchToDrawMode::ActionSwitchToDrawMode(ApplicationManager* pApp) : Action(pApp)
{}

void ActionSwitchToDrawMode::Execute() {
	// Use pMAnager that's inherited to get to Interface 
	GUI* pGUI = pManager->GetGUI();
	//update tool bar by deletion then redrawing..
	pGUI->ClearToolBarArea();
	pGUI->CreateDrawToolBar();
	pGUI->CreateColorBar();
	pGUI->PrintMessage("Back to Draw Mode!");
	UI.InterfaceMode = MODE_DRAW;
}

void ActionSwitchToDrawMode::Undo() {
	// Use pMAnager that's inherited to get to Interface 
	GUI* pGUI = pManager->GetGUI();
	//update tool bar by deletion then redrawing..
	pGUI->ClearToolBarArea();
	pGUI->CreatePlayToolBar();
	pGUI->PrintMessage("Back to Play Mode!");
	UI.InterfaceMode = MODE_PLAY;
}

void ActionSwitchToDrawMode::Redo() {
	// Use pMAnager that's inherited to get to Interface 
	GUI* pGUI = pManager->GetGUI();
	//update tool bar by deletion then redrawing..
	pGUI->ClearToolBarArea();
	pGUI->CreateDrawToolBar();
	pGUI->CreateColorBar();
	pGUI->PrintMessage("Back to Draw Mode!");
	UI.InterfaceMode = MODE_DRAW;
}