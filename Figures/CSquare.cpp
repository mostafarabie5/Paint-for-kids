#include "CSquare.h"
#include <fstream>
CSquare::CSquare()
{
	Selected = false;
}

CSquare::CSquare(Point p1, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Selected = false;
	center = p1;
}

void CSquare::Draw(Output* pOut) const
{
	pOut->Drawsq(center, FigGfxInfo, Selected);
}

bool CSquare::ToSelected(int x, int y)
{
	bool bx = false, by = false;
	if (x >= (center.x - 50) && x <= (center.x + 50))
	{
		bx = true;
	}
	if (y >= (center.y - 50) && y <= (center.y + 50))
	{
		by = true;
	}
	if (by == true && bx == true)
	{
		return true;
	}
	return false;
}
void CSquare::Move(Point p, Output* pOut)
{
	center = p;
	Draw(pOut);
}
void CSquare::PrintInfo(Output* pOut) const
{
	pOut->ClearStatusBar();
	pOut->PrintMessage("Square   Id is :" + to_string(ID) + "  center is : " + '(' + to_string(center.x) + ',' + to_string(center.y) + ')' + "   " + "length is : " + to_string(50));
}

string CSquare::GetType() const
{
	return "Square";
}

Point CSquare::GetCntr()
{
	return center;
}

void CSquare::Save(ofstream& OutFile)
{
	// Print information of the figure on a file 
	OutFile << "SQUA" << "    " << ID << "    " << center.x << "    " << center.y << "    ";
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

void CSquare::Load(ifstream& Infile)
{
	// set data of the figure from a file 
	Infile >> ID >> center.x >> center.y;

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