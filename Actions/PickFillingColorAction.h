#pragma once
#include"Action.h"
#include"../GUI/Output.h"
#include"LoadAction.h"

class PickFillingColorAction :public Action
{
protected:
	int CorrectCount;
	int InCorrectCount;
	int IndexOfRandomFigure;
	int NumberOfRandomFigures;
	LoadAction LoadFile;
	Output* pOut;
	Input* pIn;
	color FillColor;
	Point p;
public:
	PickFillingColorAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(bool x);
};
