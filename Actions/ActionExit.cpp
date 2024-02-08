#include "ActionExit.h"
#include "../GUI/GUI.h"

ActionExit::ActionExit(ApplicationManager* pApp) : Action(pApp)
{

}

void ActionExit::Execute()
{
    GUI* pGUI = pManager->GetGUI();

    Action* pActSave = nullptr;  // Move the declaration outside the switch

    int userWantSave = MessageBox(NULL, "Before leaving us, do you want to save your work?", "Save Your Work", MB_YESNO | MB_ICONSTOP);

    switch (userWantSave)
    {
    case IDYES:
        // User clicked OK, create and execute the SAVE action
        pActSave = pManager->CreateAction(SAVE);
        if (pActSave)
            pManager->ExecuteAction(pActSave, EXIT);
        break;

    case IDNO:   //No Use of it
                // User clicked Cancel, do nothing or handle as needed
        break;
    default:
        // Handle other cases if needed

        break;
    }
}

void ActionExit::Undo()
{

}
void ActionExit::Redo()
{

}
