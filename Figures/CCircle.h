#pragma once
#include "CFigure.h"
class CCircle : public CFigure
{
	//////////////////////////////..DATD..MEMBER../////////////////////////////////
	Point center, radius; //point for center and another one for reduis

   ///////////////////////////////////////////////////////////////////////////////
public:

	////////////////////////////////...FUNCTIONS...///////////////////////////////
	CCircle(); //Default constructor 

	CCircle(Point p, Point r, GfxInfo FigureGfxInfo); //non_default constructor to set parameters of the figure 

	void Draw(Output* pOut) const;  // Draw the fig 

	virtual void Move(Point p, Output* pOut); //move the figure to new center

	virtual void Save(ofstream& OutFile);	//Save the figure parameters to the file

	virtual void Load(ifstream& Infile);   //Load the figure parameters from the file 

	bool ToSelected(int x, int y);// check whether the point belongs to the figure

	virtual void PrintInfo(Output* pOut)const; //print the all information of the fiure on status bar 

	virtual string GetType() const; // returns the figure type

	virtual Point GetCntr();  //return center of the figuer 
	//////////////////////////////////////////////////////////////////////////////
};

