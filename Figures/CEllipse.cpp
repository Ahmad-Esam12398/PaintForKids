#include "CEllipse.h"
#include "CFigure.h"
#include <fstream>
#include <iostream>

CEllipse::CEllipse(Point _P1, Point _P2, GfxInfo FigureGfxInfo) : CFigure(FigureGfxInfo)
{
	P1 = _P1;
	P2 = _P2;
	ID = newID++;
}
CEllipse::CEllipse() {}

void CEllipse::DrawMe(GUI* pGUI) const
{
	//Call Output::DrawCircle to draw a Circle on the screen	
	pGUI->DrawEllipse(P1, P2, FigGfxInfo, Selected);

}

void CEllipse::Resize(GUI* pGUI, float factor){
	pGUI->ClearStatusBar();
	Point center;
	center.x = 0.5 * (P2.x + P1.x);
	center.y = 0.5 * (P2.y + P1.y);
	float a = abs(P2.x - P1.x) / 2;
	float b = abs(P2.y - P1.y) / 2;
	a *= factor;
	b *= factor;
	float bigger = max(a, b);
	float smaller = min(a, b);
	if (center.x + bigger >= UI.width || center.x - bigger <= 0 || center.y + bigger > (UI.height - UI.StatusBarHeight) || center.y <= UI.ToolBarHeight) {
		pGUI->PrintMessage("Can't resize, it will be out of borders");
		return;
	}
	else if (smaller < 5) {
		pGUI->PrintMessage("Can't resize, it will be too small");
		return;
	}
	else {
		P1.x = center.x - a;
		P1.y = center.y - b;
		P2.x = center.x + a;
		P2.y = center.y + b;
	}
}

bool CEllipse::insideFigure(int x, int y)
{
	Point center;
	center.x = 0.5 * (P2.x + P1.x);
	center.y = 0.5 * (P2.y + P1.y);
	float a = abs(P2.x - P1.x) / 2;
	float b = abs(P2.y - P1.y) / 2;
	float check = (pow(x - center.x, 2) / pow(a, 2)) + (pow(y - center.y, 2) / pow(b, 2));
	if (check <= 1)
		return true;

	return false;

	return false;

};
string CEllipse::getShapeType() {
	return "Ellipse";
}

void CEllipse::Save(ofstream& File)
{
	File << "Elipse \t"
		<< this->GetID() << "\t"
		<< P1.x << "\t"
		<< P1.y << "\t"
		<< P2.x << "\t"
		<< P2.y << "\t"
		<< ColorToString(FigGfxInfo.DrawClr) << "\t";
	if (this->FigGfxInfo.isFilled)
		File << this->ColorToString(this->FigGfxInfo.FillClr) << "\n";
	else
		File << "No-Fill-color\n";
}


void CEllipse::Load(ifstream& file)
{
	string temp;
	file >> this->ID >>
		this->P1.x >>
		this->P1.y >>
		this->P2.x >>
		this->P2.y;
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

void CEllipse::getCenter(int& x, int& y)
{
	x = 0.5 * (P2.x + P1.x);
	y = 0.5 * (P2.y + P1.y);
}

void CEllipse::Move(int x, int y, GUI* pGUI)
{
	float lowerX = min(P1.x, P2.x);
	float biggerX = max(P1.x, P2.x);
	float lowerY = min(P1.y, P2.y);
	float biggerY = max(P1.y, P2.y);
	if( lowerX + x <= 0 || biggerX + x >= UI.width || biggerY + y >= (UI.height - UI.StatusBarHeight) || lowerY + y <= UI.ToolBarHeight)
		pGUI->PrintMessage("Can't move, it will be out of borders");
	else
	{
		P1.x += x;
		P1.y += y;
		P2.x += x;
		P2.y += y;
	}
}