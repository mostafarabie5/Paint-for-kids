#pragma once
#include"Action.h"
class ChangeDrawingAction :public Action
{
protected:
	ActionType Color;
	Output* pOut;
	Input* pIn;
	//Data members for undo and redo
	color LastC;
	color New;
	CFigure* Fig;
public:
	ChangeDrawingAction(ApplicationManager* pApp);
	virtual void ReadActionParameters() ;
	virtual void Execute(bool);
	virtual void undo();
	virtual void redo();

};