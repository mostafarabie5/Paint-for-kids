#pragma once
#include "Action.h"
class AddTriaAction :public Action
{
	//////////////////////////////..DATA..MEMBER..////////////////////////
	Point corner1, corner2, corner3; //Triangle corners
	GfxInfo TriaGfxInfo;
	CFigure* Fig;
	/////////////////////////////////////////////////////////////////////
public:
	/////////////////////////////..FUNCTIONS..///////////////////////////
	AddTriaAction(ApplicationManager* pApp);//non_Default constructor 

	virtual void ReadActionParameters();//Read parameter from the user

	virtual void Execute(bool);//Execute Action

	virtual void undo();//

	virtual void redo();//
	///////////////////////////////////////////////////////////////////////
};

