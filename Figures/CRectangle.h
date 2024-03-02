#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
	////////////////////////////..DATA..MEMBER..//////////////////////////////////
	Point Corner1;
	Point Corner2;
	//////////////////////////////////////////////////////////////////////////////
public:
	/////////////////////////////..FUNCTIONS..///////////////////////////////////
	CRectangle(); //Default constructor 

	CRectangle(Point, Point, GfxInfo FigureGfxInfo); //non_Default constructor to set parameter of the figure 

	virtual void Draw(Output* pOut) const;  //Draw the figure

	virtual void Move(Point p, Output* pOut);// move the figure to new center

	bool ToSelected(int x, int y);  // Check whether the point belongs to the figure

	virtual void Save(ofstream& OutFile);	//Save the figure parameters to the file

	virtual void Load(ifstream& Infile);    // Load the figure parameeters from a file 

	virtual void PrintInfo(Output* pOut)const;  //Print All information of the figure on status bar 

	virtual string GetType() const;  // Return type of the figure 

	virtual Point GetCntr();  //Return the center of the figuer 
	////////////////////////////////////////////////////////////////////////////
};

#endif