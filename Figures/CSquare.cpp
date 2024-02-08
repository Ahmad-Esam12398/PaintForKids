#include "CSquare.h"
#include <iostream>
#include<fstream>

CSquare::CSquare()//default constructor, We need it to Load
{}

CSquare::CSquare(Point P1, int len, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	TopLeftCorner = P1;
	length = len;
}
	

void CSquare::DrawMe(GUI* pGUI) const
{
	//Call Output::DrawRect to draw a Square on the screen	
	pGUI->DrawSquare(TopLeftCorner, length, FigGfxInfo, Selected);
}

void CSquare::Resize(GUI* pGUI, float factor) {
	Point topLeft = TopLeftCorner;
	pGUI->ClearStatusBar();
	if (topLeft.x + length * factor >= UI.width || topLeft.y + length * factor >= (UI.height - UI.StatusBarHeight)) {
		pGUI->PrintMessage("Can't resize, it will be out of borders");
		return;
	}
	else if(length* factor < 5) {
			pGUI->PrintMessage("Can't resize, it will be too small");
			return;
	}
	else {
		length *= factor;
	}

}

bool CSquare::insideFigure(int x, int y)
{
	if (x >= TopLeftCorner.x && x <= (TopLeftCorner.x + length) && y >= TopLeftCorner.y && y <= (TopLeftCorner.y + length))
	{
		return true;
	}
	return false;
}

string CSquare::getShapeType()
{
	return "Square";
}
// I want to add functionality to move the figure
void CSquare::Move(int x, int y, GUI* pGUI)
{
	if (TopLeftCorner.x + x + length >= UI.width || TopLeftCorner.x + x <= 0 || TopLeftCorner.y + y + length >= (UI.height - UI.StatusBarHeight) || TopLeftCorner.y + y <= UI.ToolBarHeight) {
		pGUI->PrintMessage("Can't move, it will be out of borders");
		return;
	}
	else {
		TopLeftCorner.x += x;
		TopLeftCorner.y += y;
	}

}

void CSquare::getCenter(int& x, int& y)
{
	x = TopLeftCorner.x + length / 2;
	y = TopLeftCorner.y + length / 2;
}
//save & load 
void CSquare::Save(ofstream& File)
{
	File << "Square\t"
		<< this->GetID() << "\t"
		<< TopLeftCorner.x << "\t"
		<< TopLeftCorner.y << "\t"
		<< length << "\t"
		<< ColorToString(FigGfxInfo.DrawClr) << "\t";
	if (this->FigGfxInfo.isFilled)
		File << this->ColorToString(this->FigGfxInfo.FillClr) << "\n";
	else
		File << "No-Fill-color\n";
}
void CSquare::Load(ifstream& file)
{
	string temp;
	file >> this->ID >>
		this->TopLeftCorner.x >>
		this->TopLeftCorner.y >>
		this->length;
	file >> temp;
	this->FigGfxInfo.DrawClr = StringToColor(temp);
	file >> temp;
	if (temp == "No-Fill-color") {
		this->FigGfxInfo.isFilled = false;
	}
	else
	{
		this->FigGfxInfo.FillClr = StringToColor(temp);
		this->FigGfxInfo.isFilled = true;
		cout << "fail";
	}
	this->Selected = false;
	this->FigGfxInfo.BorderWdth = 3;
}