#include "CHexagon.h"
#include<fstream>
CHexagon::CHexagon()
{
	Selected = false;
}

CHexagon::CHexagon(Point p1, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	center = p1;
}

void CHexagon::Draw(Output* pOut) const
{
	pOut->Drawhex(center, FigGfxInfo, Selected);
}

void CHexagon::Move(Point p, Output* pOut)
{
	center = p;
	Draw(pOut);
}

void CHexagon::Save(ofstream& OutFile)
{// Print information of the figure on a file 
	OutFile << "HEXA" << "    " << ID << "    " << center.x << "    " << center.y << "    ";
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

void CHexagon::Load(ifstream& Infile)
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

bool CHexagon::ToSelected(int x, int y)
{
	double Area01, Area02, Area1, Area2, Area3, Area4, Area5, Area6;
	double px[6], py[6];
	double l = 100;
	px[0] = center.x - l;
	py[0] = center.y;
	px[1] = center.x - l / 2;
	py[1] = center.y - (l / 2) * sqrt(3);
	px[2] = center.x + l / 2;
	py[2] = center.y - (l / 2) * sqrt(3);
	px[3] = center.x + l;
	py[3] = center.y;
	px[4] = center.x + l / 2;
	py[4] = center.y + (l / 2) * sqrt(3);
	px[5] = center.x - l / 2;
	py[5] = center.y + (l / 2) * sqrt(3);

	Area01 = abs(px[2] * (py[3] - py[4]) + px[3] * (py[4] - py[2]) + px[4] * (py[2] - py[3])) / 2;

	Area1 = abs(x * (py[3] - py[4]) + px[3] * (py[4] - y) + px[4] * (y - py[3])) / 2;
	Area2 = abs(px[2] * (y - py[4]) + x * (py[4] - py[2]) + px[4] * (py[2] - y)) / 2;
	Area3 = abs(px[2] * (py[3] - y) + px[3] * (y - py[2]) + x * (py[2] - py[3])) / 2;

	Area02 = abs(px[1] * (py[0] - py[4]) + px[0] * (py[5] - py[1]) + px[5] * (py[1] - py[0])) / 2;

	Area4 = abs(x * (py[0] - py[5]) + px[0] * (py[5] - y) + px[5] * (y - py[0])) / 2;
	Area5 = abs(px[1] * (y - py[5]) + x * (py[5] - py[1]) + px[5] * (py[1] - y)) / 2;
	Area6 = abs(px[1] * (py[0] - y) + px[0] * (y - py[1]) + x * (py[1] - py[0])) / 2;

	if (x >= center.x - 50 && x <= center.x + 50 && y >= center.y - 100 && y <= center.y + 100)
	{
		return true;
	}
	if ((int)(Area1 + Area2 + Area3) == (int)Area01)
	{
		return true;
	}
	if ((int)(Area4 + Area5 + Area6) == (int)Area02)
	{
		return true;
	}
	return false;
}
void CHexagon::PrintInfo(Output* pOut) const
{
	pOut->ClearStatusBar();
	pOut->PrintMessage("Hexagon   ID is : " + to_string(ID) + "   center is :" + '(' + to_string(center.x) + ',' + to_string(center.y) + ')' + "   " + "length is :" + to_string(100));
}

string CHexagon::GetType() const
{
	return "Hexagon";
}

Point CHexagon::GetCntr()
{
	return center;
}
