#pragma once
#include "CFigure.h"
class CHexagon :public CFigure
{
	/////////////////////////...DATA..MEMBER ..//////////////////////////
	Point center;
	/////////////////////////////////////////////////////////////////////
public:
	//////////////////////////..FUNCTIONS../////////////////////////////
	CHexagon(); //Default constructor

	CHexagon(Point p1, GfxInfo FigureGfxInfo); //non_default constructor to set parameters

	void Draw(Output* pOut) const; //Draw the Figure

	virtual void Move(Point p, Output* pOut); //Move the Figure to a new center

	virtual void Save(ofstream& OutFile);	//Save the figure parameters to the file

	virtual void Load(ifstream& Infile);	//Load the figure parameters to the file

	bool ToSelected(int x, int y);  //Check whetther the point belongs to the figure or not 

	virtual void PrintInfo(Output* pOut)const; //print all information of the figure 

	virtual string GetType() const;  // Return the type of the figure

	virtual Point GetCntr();  //get Center of the figure 
	////////////////////////////////////////////////////////////////////
};

