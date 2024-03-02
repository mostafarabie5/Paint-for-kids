#pragma once
#include "Action.h"
class AddSquAction :public Action
{
	//////////////////////////..DATA..MEMBER..///////////////////////////////
	Point center;//Square center
	GfxInfo SquGfxInfo;
	CFigure* Fig;
	////////////////////////////////////////////////////////////////////////
public:
	////////////////////////////////..FUNCTION../////////////////////////////
	AddSquAction(ApplicationManager* pApp);//non_Default constructor 

	virtual void ReadActionParameters();//Read parameter from the user

	virtual void Execute(bool);//Execute Action

	virtual void undo(); //

	virtual void redo();//

	/////////////////////////////////////////////////////////////////////////
};

