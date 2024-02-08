#include "ActionLoad.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"

#include "../Figures/CEllipse.h"
#include "../Figures/CHexagon.h"
#include "../Figures/CSquare.h"

#include "..\Figures\CFigure.h"

#include<fstream>
#include <iostream>

ActionLoad::ActionLoad(ApplicationManager* pApp) :Action(pApp)
{
}

void ActionLoad::Execute()
{
    int r, g, b;
    ifstream File;
    string figName;
    int figcount;
    CFigure* fig;
    GUI* pGUI = pManager->GetGUI();

    // Get a valid file name
    string fileName;
    while (true)
    {
        pGUI->PrintMessage("Please enter the file name: ");
        fileName = pGUI->GetSrting();

        // Check if the file name is empty
        if (!fileName.empty())
        {
            break;
        }
      
       // MessageBox(NULL,"Invalid file name. Please enter a valid name.","Try Again", MB_OKCANCEL | MB_ICONSTOP);
      
        pGUI->PrintMessage("Invalid file name. Please enter a valid name.");
    }

    File.open("savedShapes/" + fileName + ".txt");

    if (File.fail())
    {
        pGUI->PrintMessage("Invalid file name or file does not exist.");
        return;
    }

    pGUI->ClearDrawArea();
    pManager->deleteALLFig();

    File >> r >> g >> b;
    color drawClr(r, g, b);
    File >> r >> g >> b;
    color FillClr(r, g, b);
    File >> r >> g >> b;
    color bkgclr(r, g, b);

    pGUI->setCrntDrawColor(drawClr);
    pGUI->setCrntFillColor(FillClr);
    pGUI->setCrntBKGrandColor(bkgclr);
    File >> figcount;

    while (figcount)
    {
        File >> figName;
        if (figName == "Elipse")
        {
            fig = new CEllipse();
        }
        else if (figName == "Square")
        {
            fig = new CSquare();
        }
        else if (figName == "Hexagon")
        {
            fig = new CHexagon();
        }

        fig->Load(File);
        pManager->AddFigure(fig);

        figcount--;
    }

    pManager->UpdateInterface();
    pGUI->CreateColorBar();
    pGUI->PrintMessage("File Loaded successfully.");
    pGUI->ClearStatusBar();
}

void ActionLoad::Undo()
{
}
void ActionLoad::Redo()
{
}
