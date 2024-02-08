#ifndef CSQUARE_H
#define CSQUARE_H

#include "CFigure.h"

class CSquare : public CFigure
{
private:
	Point TopLeftCorner;	
	int length;
public:
	CSquare();
	CSquare(Point , int, GfxInfo FigureGfxInfo );
	virtual void DrawMe(GUI* pOut) const;
	void Resize(GUI* pGUI, float size);
	virtual bool insideFigure(int x, int y); //Check if the click inside the Figure...
	virtual void CSquare::Move(int x, int y, GUI* pGUI);
	void getCenter(int& x, int& y);
	void Save(ofstream& File);
	void Load(ifstream& file);
	string getShapeType();

};

#endif