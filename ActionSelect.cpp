#include "ActionSelect.h"
#include "Actions/Action.h"
#include "GUI/GUI.h"
#include "./ApplicationManager.h"


ActionSelect::ActionSelect(ApplicationManager* AppMgr):Action(AppMgr) {
                
}
void ActionSelect::Execute() {
    GUI* g = pManager->GetGUI();
    Point P;
    g->GetPointClicked(P.x,P.y);
    
    CFigure* fg = pManager->GetFigure(P.x, P.y);

    if (fg == NULL) {
        g->PrintMessage("there is no shape in clicked points");
    }
    else {
        g->PrintMessage(""+fg->IsSelected());

        if (!fg->IsSelected()) {
            fg->SetSelected(true);
            fg->ChngDrawClr(BISQUE);
            pManager->AddSelectedFigure(fg);
        }
        else if(fg->IsSelected() ){
            fg->SetSelected(false);
            fg->ChngDrawClr(UI.DrawColor);
            pManager->RemoveSelectedFigure(fg);
        }
    }
        
}
void ActionSelect::Undo() {
	
}

void ActionSelect::Redo() {
	
}



