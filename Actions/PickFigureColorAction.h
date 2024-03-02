#pragma once
#include"Action.h"
#include"../GUI/Output.h"
#include"LoadAction.h"

class PickFigureColorAction : public Action
{
protected:
	int CorrectCount;
	int InCorrectCount;
	int IndexOfRandomFigure;
	int NumberOfRandomFigures;
	LoadAction LoadFile;
	string Type;
	color FillColor;
	Output* pOut;
	Input* pIn;
	Point p;
public:
	PickFigureColorAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(bool x);
};
#pragma once
