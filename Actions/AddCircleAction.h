#pragma once
#include "Action.h"
class AddCircleAction : public Action
{
	///////////////////////////..DATA..MEMBER..//////////////////////////////
	Point center, redius;  //Circle center and redius
	GfxInfo CircleGfxInfo;
	CFigure* Fig;
	/////////////////////////////////////////////////////////////////////////
public:
	///////////////////////////////..FUNCTIONS../////////////////////////////
	AddCircleAction(ApplicationManager* pApp);//non_Default constructor 

	virtual void ReadActionParameters(); //Read parameter from the user

	virtual void Execute(bool); // Execute the Action 

	virtual void undo();//

	virtual void redo(); //
	/////////////////////////////////////////////////////////////////////////
};

