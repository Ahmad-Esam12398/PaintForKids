

#include "ActionSave.h"
#include "..\Figures\CFigure.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"
#include <fstream>
#include <direct.h>  // Include this header for _mkdir

ActionSave::ActionSave(ApplicationManager* pApp, int _figcount) : Action(pApp)
{
    count = _figcount;
}

void ActionSave::Execute()
{
    GUI* pGUI = pManager->GetGUI();

    // Get a valid file name
    string fileName;
    while (true)
    {
        pGUI->PrintMessage("Enter a Valid Name For the file then press Enter.. ^_^");
        fileName = pGUI->GetSrting();

        // Check if the file name is empty or contains invalid characters
        if (!fileName.empty() && fileName.find_first_of("\\/:*?\"<>|") == string::npos)
        {
            break;
        }

        pGUI->PrintMessage("Invalid file name. Please enter a valid name without special characters.");
    }

    // Fixed folder for saved shapes
    string folderPath = "savedShapes/";

    // Create the folder if it doesn't exist
    _mkdir(folderPath.c_str());

    // Open the file for writing inside the folder
    ofstream savedFile(folderPath + fileName + ".txt", ios::out);

    // Check if the file is opened successfully
    if (!savedFile)
    {
        pGUI->PrintMessage("Failed to open the file for writing. Please try again.");
        return;
    }

    // Save the drawing information to the file
    savedFile << pManager->colorToString(UI.DrawColor) << "\t";
    savedFile << pManager->colorToString(UI.FillColor) << "\t";
    savedFile << pManager->colorToString(UI.BkGrndColor) << "\t";
    savedFile << "\n" << count << "\n";

    // Call the SaveAllFigures function in ApplicationManager
    pManager->SaveFile(savedFile);

    savedFile.close();
    pGUI->PrintMessage("File saved successfully.");
}

void ActionSave::Undo()
{
	// This action should not be undone
}

void ActionSave::Redo()
{
	// This action should not be redone
}
