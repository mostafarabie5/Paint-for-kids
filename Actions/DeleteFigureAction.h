#pragma once
#include "Action.h"
#include"SelectAction.h"
#include"../DEFS.h"

class DeleteFigureAction :public Action
{
private:
	CFigure* Fig;
	int x;

public:
	DeleteFigureAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(bool x);
	virtual void undo();
	virtual void redo();
};

