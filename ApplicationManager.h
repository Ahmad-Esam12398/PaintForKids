#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include"HistoryManager.h"
class Action;	//Forward Declaration


//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures
	int FigCount;		//Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)

	int SelectedCount;					//Selected Figures Count
	CFigure* SelectedFigures[MaxFigCount];  // All selected Figures
	CFigure* SelectedFigure;
	//Pointers to Input and Output classes
	GUI* pGUI;
	HistoryManager History;
	

public:	
	ApplicationManager(); 
	~ApplicationManager();

	void Run();		//to run the application
	
	// -- Action-Related Functions
	Action* CreateAction(ActionType);
	void ExecuteAction(Action*&, ActionType) ; //Execute an action
	void Undo(); //Undo the last action
	void Redo(); //Redo the last action
	void removeLastFigure(); //Remove the last figure from the list
	
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig); //Adds a new figure to the FigList
	CFigure *GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
		
	// -- Interface Management Functions	
	GUI *GetGUI() const; //Return pointer to the interface
	void UpdateInterface() const;	//Redraws all the drawing window	

	// -- Selection Functions Section
	int GetSelectedCount();  //selected count Getter
	CFigure** GetSelectedFigures();	// return pointer to array of pointers to figures selected
	void AddSelectedFigure(CFigure* selected); //Add figure to selected Array
	void RemoveSelectedFigure(CFigure* selected); //Remove figure from selected Array
	void deleteALLFig();		//Empty Figures Array at all.
	void SetSelectedFigure(CFigure* selected); // Set the current selected to selected.
	CFigure* GetSelectedFigure(); //Getter of currently Selected One
	int GetSelectedFigureID(); //Get ID of Selected Figure
	bool AnySelected();

	// -- Deletion Functions Section
	void RemoveFig(int ID);
	void ClearSelectedFigures();
	

	// -- Move Functions Section
	void moveFigure();
	void SendToBack(int index);		//Send to back
	void SendToFront(int index);		//send to front
	void SaveFile(ofstream& outputfile); //save Action
	string colorToString(color c);
	//color Functions
	bool GetColor(color& inputColor);	
	void changeDrawColor(color drawClr);
	void changeFillColor(color FillClr);




};

#endif