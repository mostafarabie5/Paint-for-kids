#ifndef INPUT_H
#define INPUT_H

#include "..\DEFS.h"
#include "UI_Info.h" 
#include "..\CMUgraphicsLib\CMUgraphics.h"

class Output;   // forward declaration

class Input		//The application manager should have a pointer to this class
{
private:
	window* pWind;	//Pointer to the Graphics Window
public:
	Input(window* pW);		//Consturctor
	void GetPointClicked(int& x, int& y) const;//Get coordinate where user clicks
	buttonstate GetPointDragged(int& x, int& y)const;
	string GetSrting(Output* pO) const;	 //Returns a string entered by the user

	ActionType GetUserAction() const; //Read the user click and map to an action
	void setDrawcolor(color c);
	void setFillcolor(color c);
	~Input();
};

#endif