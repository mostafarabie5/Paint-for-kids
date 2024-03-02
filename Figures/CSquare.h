#ifndef CSQUARE_H
#define CSQUARE_H
#include "CFigure.h"
class CSquare : public CFigure
{
	/////////////////////////////..DATA..MEMBER..////////////////////////////////////
	Point center;
	////////////////////////////////////////////////////////////////////////////////
public:
	///////////////////////////////..FUNCTIONS..//////////////////////////////////////
	CSquare(); //Default constructor 

	CSquare(Point p1, GfxInfo FigureGfxInfo); //non_Default constructor to set paramer of the figure 

	void Draw(Output* pOut) const; //Draw the figure 

	bool ToSelected(int x, int y); //Check whether the point belong to the figure 

	virtual void Move(Point p, Output* pOut);//Move the figure to new center

	virtual void Save(ofstream& OutFile);	//Save the figure parameters to the file

	virtual void Load(ifstream& Infile);	//Load the figure parameters from the file

	virtual void PrintInfo(Output* pOut)const; //Print All information of the figure on status bar 

	virtual string GetType() const;//Return type of the figure 

	virtual Point GetCntr();//Return the center of the figure 
	///////////////////////////////////////////////////////////////////////////////////
};

#endif 