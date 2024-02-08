#include "ActionDelete.h"
#include "ApplicationManager.h"

ActionDelete::ActionDelete(ApplicationManager* pApp) : Action(pApp) {}

void ActionDelete::Execute() {
	// GET A pointer to GUI 
	GUI* pGUI = pManager->GetGUI();

	//Set Selected Figures
	SelectedFigures = pManager->GetSelectedFigures();
	SelectedCount = pManager->GetSelectedCount();

	if (SelectedFigures[0] == NULL) //Check at least one is selected
	{
		pGUI->PrintMessage("Plz Select A Figure First");
	}
	else {
		int MsgBoxID = MessageBoxW(
			NULL,
			(LPCWSTR)L"Confirm Delete?\n",
			(LPCWSTR)L"Confirm Delete",
			MB_ICONWARNING | MB_YESNOCANCEL | MB_DEFBUTTON2
		);
		switch (MsgBoxID) {  // Doing according to response
		case IDYES: 
			for (int i = 0; i < SelectedCount; i++) {
				DeletedID = pManager->GetSelectedFigureID();
				pManager->RemoveFig(DeletedID);
				delete SelectedFigures[i];
			}
			pManager->ClearSelectedFigures();
			pGUI->ClearDrawArea();
			pGUI->CreateColorBar();
			pGUI->PrintMessage("Completed!");
			break;
		default: // Any Other Case
			pGUI->PrintMessage("Deletion Cancelled!");
			break;
		}


	}
}
void ActionDelete::Undo() {
	// GET A pointer to GUI 
	GUI* pGUI = pManager->GetGUI();
	//Set Selected Figures
	SelectedFigures = pManager->GetSelectedFigures();
	SelectedCount = pManager->GetSelectedCount();
	for (int i = 0; i < SelectedCount; i++) {
		pManager->AddFigure(SelectedFigures[i]);
	}
	pGUI->ClearDrawArea();
	pManager->UpdateInterface();
}

void ActionDelete::Redo() {
	// GET A pointer to GUI 
	GUI* pGUI = pManager->GetGUI();
	//Set Selected Figures
	SelectedFigures = pManager->GetSelectedFigures();
	SelectedCount = pManager->GetSelectedCount();
	for (int i = 0; i < SelectedCount; i++) {
		DeletedID = pManager->GetSelectedFigureID();
		pManager->RemoveFig(DeletedID);
		delete SelectedFigures[i];
	}
	pManager->ClearSelectedFigures();
	pGUI->ClearDrawArea();
	pGUI->CreateColorBar();
	pGUI->PrintMessage("Completed!");
}