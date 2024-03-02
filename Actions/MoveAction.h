#pragma once
#include"Action.h"

class MoveAction : public Action
{
protected:
	Point p;
	Point PrevP;
	CFigure* MovedFigure;
public:
	MoveAction(ApplicationManager* pApp);	//constructor

	//Reads parameters required for action to execute (code depends on action type)
	virtual void ReadActionParameters() ;

	//Execute action (code depends on action type)
	virtual void Execute(bool x) ;
	virtual void undo();
	virtual void redo();

};