#pragma once
#include "CFigure.h"
#include "..\ApplicationManager.h"

class CHexagon : public CFigure
{
private:
	Point TopLeftCorner;
	Point BottomRightCorner;
	int VerticalLen;
	int HorizentalLen;
public:
	ApplicationManager* pManager = NULL;	//Actions needs AppMngr to do their job
	int Area;
	CHexagon(Point, Point, GfxInfo FigureGfxInfo);
	CHexagon();
	virtual void DrawMe(GUI* pOut) const;
	virtual bool insideFigure(int x, int y);
	void Resize(GUI* pGUI, float size);
	string getShapeType();
	void Save(ofstream& File);
	void Load(ifstream& file);
	void getCenter(int& x, int& y);
	void Move(int x, int y, GUI* pGUI);

};