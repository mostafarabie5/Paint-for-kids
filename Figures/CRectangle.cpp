#include "CRectangle.h"
#include <iostream>
#include <fstream>
#include "CFigure.h"
using namespace std;
CRectangle::CRectangle()
{
	Selected = false;
}

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Selected = false;
	Corner1 = P1;
	Corner2 = P2;
}


void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}

void CRectangle::Move(Point p, Output* pOut)
{
	double Xcoordinate = abs(Corner1.x - Corner2.x) / 2;
	double Ycoordinate = abs(Corner1.y - Corner2.y) / 2;
	Corner1.x = p.x + Xcoordinate;
	Corner1.y = p.y + Ycoordinate;
	Corner2.x = p.x - Xcoordinate;
	Corner2.y = p.y - Ycoordinate;
	Draw(pOut);
}

bool CRectangle::ToSelected(int x, int y)
{
	bool bx = false, by = false;
	if (Corner1.x > Corner2.x)
	{
		if (x <= Corner1.x && x >= Corner2.x)
			bx = true;
	}
	else
	{
		if (x >= Corner1.x && x <= Corner2.x)
			bx = true;
	}
	if (Corner1.y > Corner2.y)
	{
		if (y >= Corner2.y && y <= Corner1.y)
			by = true;
	}
	else
	{
		if (y <= Corner2.y && y >= Corner1.y)
			by = true;
	}
	if (bx == true && by == true)
	{
		return true;
	}
	return false;
}

void CRectangle::PrintInfo(Output* pOut) const
{
	pOut->ClearStatusBar();
	pOut->PrintMessage("Rectangle   Id is : " + to_string(ID) + "   corner 1 " + '(' + to_string(Corner1.x) + ',' + to_string(Corner1.y) + ')' + "   corner 2 " + '(' + to_string(Corner2.x) + ',' + to_string(Corner2.y) + ')' + "   " + "length is : " + to_string(abs(Corner1.x - Corner2.x)) + "   " + "width is : " + to_string(abs(Corner1.y - Corner2.y)));
}

string CRectangle::GetType() const
{
	return "Rectangle";
}

Point CRectangle::GetCntr()
{
	Point c;
	c.x = (Corner1.x + Corner2.x) / 2;
	c.y = (Corner1.y + Corner2.y) / 2;
	return c;
}

void CRectangle::Save(ofstream& OutFile)
{
	// Print information of the figure on a file 
	OutFile << "RECT" << "    " << ID << "    " << Corner1.x << "    " << Corner1.y << "    " << Corner2.x << "    " << Corner2.y << "    ";
	FigGfxInfo.DrawClr = FigureColor;
	if (FigGfxInfo.DrawClr == RED) //Switch to print Drawing color on the file 
		OutFile << "RED" << "    ";
	else if (FigGfxInfo.DrawClr == BLUE)
		OutFile << "BLUE" << "    ";
	else if (FigGfxInfo.DrawClr == GREEN)
		OutFile << "GREEN" << "    ";
	else if (FigGfxInfo.DrawClr == YELLOW)
		OutFile << "YELLOW" << "    ";
	else if (FigGfxInfo.DrawClr == BLACK)
		OutFile << "BLACK" << "    ";
	else
		OutFile << "ORANGE" << "    ";
	if (FigGfxInfo.isFilled) // switch to print the filling color on the file 
	{
		if (FigGfxInfo.FillClr == RED)
			OutFile << "RED" << endl;
		else if (FigGfxInfo.FillClr == BLUE)
			OutFile << "BLUE" << endl;
		else if (FigGfxInfo.FillClr == GREEN)
			OutFile << "GREEN" << endl;
		else if (FigGfxInfo.FillClr == YELLOW)
			OutFile << "YELLOW" << endl;
		else if (FigGfxInfo.FillClr == BLACK)
			OutFile << "BLACK" << endl;
		else
			OutFile << "ORANGE" << endl;
	}
	else
		OutFile << "NO_FILL" << endl;
}

void CRectangle::Load(ifstream& Infile)
{
	// set data of the figure from a file 
	Infile >> ID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y;
	string s;
	Infile >> s;

	if (s == "BLACK")  //  switch to set the drawing color 
		FigGfxInfo.DrawClr = BLACK;
	else if (s == "BLUE")
		FigGfxInfo.DrawClr = BLUE;
	else if (s == "RED")
		FigGfxInfo.DrawClr = RED;
	else if (s == "ORANGE")
		FigGfxInfo.DrawClr = ORANGE;
	else if (s == "GREEN")
		FigGfxInfo.DrawClr = GREEN;
	else
		FigGfxInfo.DrawClr = YELLOW;

	FigureColor = FigGfxInfo.DrawClr;

	Infile >> s;
	if (s == "BLACK")//switch to set the filling color 
	{
		FigGfxInfo.isFilled = true;
		FigGfxInfo.FillClr = BLACK;
	}
	else if (s == "BLUE")
	{
		FigGfxInfo.isFilled = true;
		FigGfxInfo.FillClr = BLUE;
	}
	else if (s == "RED")
	{
		FigGfxInfo.isFilled = true;
		FigGfxInfo.FillClr = RED;
	}
	else if (s == "ORANGE")
	{
		FigGfxInfo.isFilled = true;
		FigGfxInfo.FillClr = ORANGE;
	}
	else if (s == "GREEN")
	{
		FigGfxInfo.isFilled = true;
		FigGfxInfo.FillClr = GREEN;
	}
	else if (s == "YELLOW")
	{
		FigGfxInfo.isFilled = true;
		FigGfxInfo.FillClr = YELLOW;
	}
	else
		FigGfxInfo.isFilled = false;
}
