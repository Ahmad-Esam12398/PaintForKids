#pragma once
#include "CFigure.h"
#include "..\ApplicationManager.h"
class CEllipse :public CFigure
{
private:
	Point P1, P2;

public:
	ApplicationManager* pManager = NULL;	//Actions needs AppMngr to do their job

	CEllipse(Point, Point, GfxInfo FigureGfxInfo);
	CEllipse();
	virtual void DrawMe(GUI* pOut) const;
	virtual bool insideFigure(int x, int y);
	void Resize(GUI* pGUI, float size);
	string getShapeType();
	void Save(ofstream& File);
	void Load(ifstream& file);
	void getCenter(int& x, int& y);
	void Move(int x, int y, GUI* pGUI);
};