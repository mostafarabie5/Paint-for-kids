#pragma once
#include"Action.h";
#include"../ApplicationManager.h"

class ChangeFillAction : public Action
{
protected:
	ActionType Color;
	Output* pOut;
	Input* pIn;
	color choosencolor;
	color prevcolor;
	bool fillstate;
	bool lastfill;
	CFigure* Fig;
public:
	ChangeFillAction(ApplicationManager* pApp);	//constructor

	//Reads parameters required for action to execute (code depends on action type)
	virtual void ReadActionParameters() ;

	//Execute action (code depends on action type)
	virtual void Execute(bool x);
	virtual void undo();
	virtual void redo();
};
