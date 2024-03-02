#pragma once
#include"Action.h"
class MoveByDraggingAction : public Action
{
protected:
	Output* pOut;
	Input* pIn;
	Point p;
	CFigure* Selected;
public:
	MoveByDraggingAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(bool x);
};
