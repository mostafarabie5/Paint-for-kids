#pragma once
#include "Action.h"
class AddHexaAction :public Action
{
	/////////////////////////////..DATA..MEMBER../////////////////////////////
	Point center;//Hexagon center
	GfxInfo HexaGfxInfo;
	CFigure* Fig;
	/////////////////////////////////////////////////////////////////////////
public:
	//////////////////////////////..FUNCTION..///////////////////////////////
	AddHexaAction(ApplicationManager* pApp);//non_Default constructor 

	virtual void ReadActionParameters();//Read parameter from the user

	virtual void Execute(bool);// Execute the Action

	virtual void undo();

	virtual void redo();
	//////////////////////////////////////////////////////////////////////////
};

