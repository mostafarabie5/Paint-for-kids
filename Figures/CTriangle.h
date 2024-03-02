#pragma once
#include "CFigure.h"
class CTriangle : public CFigure
{
	//////////////////////////////////..DATA..MEMBER..////////////////////////////
	Point corner1, corner2, corner3;
	/////////////////////////////////////////////////////////////////////////////

public:
	/////////////////////////////////..FUNCTIONS..///////////////////////////////
	CTriangle();  ////Default constructor 

	CTriangle(Point p1, Point p2, Point p3, GfxInfo FigureGfxInfo);//non_Default constructor to set paramer of the figure

	void PrintInfo(Output* pOut)const;  //Print All information of the figure on status bar

	void Draw(Output* pOut) const; //Draw the figure 

	virtual void Move(Point p, Output* pOut);  //Move the figure to new center

	virtual void Save(ofstream& OutFile);	//Save the figure parameters to the file

	virtual void Load(ifstream& Infile); //Load the figure parameters from the file

	bool ToSelected(int x, int y); //Check whether the point belong to the figure 

	virtual string GetType() const;  //Return type of the figure 

	virtual Point GetCntr();//Return the center of the figure 
	//////////////////////////////////////////////////////////////////////////////
};

