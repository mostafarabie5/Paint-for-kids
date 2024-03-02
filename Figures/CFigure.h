#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\defs.h"
#include "..\GUI\Output.h"
#include "../CMUgraphicsLib/CMUgraphics.h"


//Base class for all figures
class CFigure
{
protected:
	//////////////////////////..DATA ..MEMBER..////////////////////////////
	int ID;		//Each figure has an ID

	bool Selected;	//true if the figure is selected.

	GfxInfo FigGfxInfo;	//Figure graphis info

	color FigureColor;// Save the drawing   

	string AutoSaveLoadFileName;  ///// .............NOTE Neeed ........ 
	//////////////////////////////////////////////////////////////////////
public:

	/////////////////////////...FUNCTIONS...//////////////////////////////
	CFigure();  //Default constructor 

	CFigure(GfxInfo FigureGfxInfo);//non_default costructor 

	void SetSelected(bool s);	//select/unselect the figure

	virtual bool ToSelected(int x, int y) = 0;	//check whether point belongs to figure

	virtual bool IsSelected(); //return true if the figure is selected

	virtual void Draw(Output* pOut) const = 0; //Draw the figure

	void setID(int id);//Setter for ID

	void ChngDrawClr(color Dclr);	//changes the figure's drawing color

	void ChngFillClr(color Fclr, bool Fill);	//changes the figure's filling color

	virtual void Move(Point p, Output* pOut) = 0;   // Moves the figure to a new center  

	virtual Point GetCntr() = 0; //get center of the figure 

	int GetId(); //Getter for ID

	virtual void PrintInfo(Output* pOut)const = 0;	//print all figure information on the status bar

	virtual string GetType() const = 0; // Return the type of the figure 

	virtual color GetFillingColor()const; //Return the filling color if the figure is filled 

	virtual bool IsFilled()const; //return true if the fig is filled 

	virtual void Save(ofstream& OutFile) = 0;	//Save the figure parameters to the file

	virtual void Load(ifstream& Infile) = 0;	   //Load the figure parameters from the file

	/////////////////////////////////////////////////////////////////////
};

#endif