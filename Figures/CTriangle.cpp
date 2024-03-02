#include "CTriangle.h"
#include <fstream>
#include <string >
CTriangle::CTriangle()
{
	Selected = false;
}

CTriangle::CTriangle(Point p1, Point p2, Point p3, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Selected = false;

	corner1 = p1;
	corner2 = p2;
	corner3 = p3;

}


void CTriangle::Draw(Output* pOut) const
{
	pOut->Drawtria(corner1, corner2, corner3, FigGfxInfo, Selected);
}

void CTriangle::Move(Point p, Output* pOut)
{
	double Xcenter = (corner1.x + corner2.x + corner3.x) / 3;
	double Ycenter = (corner1.y + corner2.y + corner3.y) / 3;
	corner1.x = p.x - (Xcenter - corner1.x);
	corner1.y = p.y - (Ycenter - corner1.y);
	corner2.x = p.x - (Xcenter - corner2.x);
	corner2.y = p.y - (Ycenter - corner2.y);
	corner3.x = p.x - (Xcenter - corner3.x);
	corner3.y = p.y - (Ycenter - corner3.y);
	Draw(pOut);
}


void CTriangle::Save(ofstream& OutFile)
{
	// Print information of the figure on a file 
	OutFile << "TRIANG" << "  " << ID << "    " << corner1.x << "    " << corner1.y << "    " << corner2.x << "    " << corner2.y << "    " << corner3.x << "    " << corner3.y << "    ";
	FigGfxInfo.DrawClr = FigureColor;
	if (FigGfxInfo.DrawClr == RED)//Switch to print Drawing color on the file
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
		OutFile << "ORANGE" << " ";
	if (FigGfxInfo.isFilled)// switch to print the filling color on the file 
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

void CTriangle::Load(ifstream& Infile)
{
	// set data of the figure from a file 
	Infile >> ID >> corner1.x >> corner1.y >> corner2.x >> corner2.y >> corner3.x >> corner3.y;
	string s;
	Infile >> s;

	if (s == "BLACK")//  switch to set the drawing color
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

bool CTriangle::ToSelected(int x, int y)
{
	double Area0, Area1, Area2, Area3; //if the sum of the Areas is equal the Main Area so the point belong to the figure
	Area0 = abs(corner1.x * (corner2.y - corner3.y) + corner2.x * (corner3.y - corner1.y) + corner3.x * (corner1.y - corner2.y)) / 2;
	Area1 = abs(x * (corner2.y - corner3.y) + corner2.x * (corner3.y - y) + corner3.x * (y - corner2.y)) / 2;
	Area2 = abs(corner1.x * (y - corner3.y) + x * (corner3.y - corner1.y) + corner3.x * (corner1.y - y)) / 2;
	Area3 = abs(corner1.x * (corner2.y - y) + corner2.x * (y - corner1.y) + x * (corner1.y - corner2.y)) / 2;
	if ((Area1 + Area2 + Area3) <= Area0)
	{
		return true;
	}
	return false;
}

string CTriangle::GetType() const
{
	return "Triangle";
}
Point CTriangle::GetCntr()
{
	Point c;
	c.x = (corner1.x + corner2.x + corner3.x) / 3;
	c.y = (corner1.y + corner2.y + corner3.y) / 3;
	return c;
}
void CTriangle::PrintInfo(Output* pOut) const
{
	pOut->ClearStatusBar();
	pOut->PrintMessage("Triangle  ID is : " + to_string(ID) + "   point 1 " + '(' + to_string(corner1.x) + ',' + to_string(corner1.y) + ')' + "   point 2 " + '(' + to_string(corner2.x) + ',' + to_string(corner2.y) + ')' + "   point 3 " + '(' + to_string(corner3.x) + ',' + to_string(corner3.y) + ')');
}


