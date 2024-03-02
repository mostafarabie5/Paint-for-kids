#include "CCircle.h"
#include <fstream>
#include "../ApplicationManager.h"
CCircle::CCircle()
{
	Selected = false;
}

CCircle::CCircle(Point p, Point  r, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	center = p;
	radius = r;
}

void CCircle::Draw(Output* pOut) const
{
	pOut->Drawcircle(center, radius, FigGfxInfo, Selected);
}

void CCircle::Move(Point p, Output* pOut)
{
	double Xradius = center.x - radius.x;
	double Yradius = center.y - radius.y;
	center = p;
	radius.x = center.x + Xradius;
	radius.y = center.y + Yradius;
	Draw(pOut);
}

void CCircle::Save(ofstream& OutFile)
{
	// Print information of the figure on a file 
	OutFile << "CIRC" << "    " << ID << "    " << center.x << "    " << center.y << "    " << radius.x << "    " << radius.y << "    ";
	FigGfxInfo.DrawClr = FigureColor;
	if (FigGfxInfo.DrawClr == RED) // switch to print drawing color 
		OutFile << "RED" << "    ";
	else if (FigGfxInfo.DrawClr == BLUE)
		OutFile << "BLUE" << "    ";
	else if (FigGfxInfo.DrawClr == GREEN)
		OutFile << "GREEN" << "    ";
	else if (FigGfxInfo.DrawClr == YELLOW)
		OutFile << "YELLOW" << "    ";
	else if (FigGfxInfo.DrawClr == BLACK)
		OutFile << "BLACK" << "    ";
	else if (FigGfxInfo.DrawClr == ORANGE)
		OutFile << "ORANGE" << "   ";

	if (FigGfxInfo.isFilled) //switch to print Filling color
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

void CCircle::Load(ifstream& Infile)
{
	// set data of the figure from a file 
	Infile >> ID >> center.x >> center.y >> radius.x >> radius.y;
	string s;
	Infile >> s;
	if (s == "BLACK")   //  switch to set the drawing color 
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
	if (s == "BLACK")  //switch to set the filling color 
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

bool CCircle::ToSelected(int x, int y)
{
	double l = sqrt(pow((x - center.x), 2) + pow((y - center.y), 2));
	double red = sqrt(pow((radius.x - center.x), 2) + pow((radius.y - center.y), 2));
	if (l <= red) //Check whether the legnth is less than or equal to the redius
	{
		return true;
	}
	return false;
}

void CCircle::PrintInfo(Output* pOut) const
{
	double r = sqrt(pow((center.x - radius.x), 2) + pow((center.y - radius.y), 2));
	pOut->ClearStatusBar();
	pOut->PrintMessage("Circle   ID is : " + to_string(ID) + "   center is : " + '(' + to_string(center.x) + ',' + to_string(center.y) + ')' + "   " + "radius is :" + to_string(r));
}

string CCircle::GetType() const
{
	return "Circle";
}

Point CCircle::GetCntr()
{
	return center;
}


