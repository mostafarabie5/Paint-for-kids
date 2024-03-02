#pragma once
#include"Action.h"
#include"LoadAction.h"

class PickFigureAction : public Action
{
protected:
	int CorrectCount;
	int InCorrectCount;
	int IndexOfRandomFigure;
	int NumberOfRandomFigures;
	LoadAction LoadFile;
	string Type;
	Output* pOut;
	Input* pIn;
	Point p;

public:
	PickFigureAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(bool x);
};
