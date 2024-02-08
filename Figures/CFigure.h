#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\defs.h"
#include "..\GUI\GUI.h"

static int newID = 0;

//Base class for all figures
class CFigure
{
protected:
	int ID;		//Each figure has an ID
	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info
	
	/// Add more parameters if needed.

public:
	CFigure();
	CFigure(GfxInfo FigureGfxInfo);
	void SetSelected(bool );	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected
	virtual bool insideFigure(int x, int y) = 0;  //Check if the point in the figure.

	virtual void DrawMe(GUI*) const  = 0 ;		//Draw the figure
	
	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color
	virtual void SetID(int _id);	// ID Setter
	virtual int GetID() const;		//ID Getter

	//Save / Load Pure Virtal Functions
	virtual void Save(ofstream& OutFile) = 0;	//Save the figure parameters to the file
	virtual void Load(ifstream& Infile) = 0;	//Load the figure parameters to the file

	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	


	//virtual void Rotate() = 0;	//Rotate the figure
	virtual void Resize(GUI* pGUI, float size) = 0;	//Resize the figure
	virtual void Move(int x, int y, GUI* pGUI) = 0;		//Move the figure
	virtual void getCenter(int& x, int& y) = 0; //Get the center of the figure
	string ColorToString(color c);
	color StringToColor(string s);

	//virtual void PrintInfo(Output* pOut) = 0;	//print all figure info on the status bar
};

#endif