#ifndef ADD_RECT_ACTION_H
#define ADD_RECT_ACTION_H

#include "Action.h"

//Add Rectangle Action class
class AddRectAction : public Action
{
private:
	////////////////////////////..DATA..MEMBER..///////////////////////////////
	Point P1, P2; //Rectangle Corners
	GfxInfo RectGfxInfo;
	CFigure* Fig;
	///////////////////////////////////////////////////////////////////////////
public:
	/////////////////////////////////..FUNCTIONES../////////////////////////////
	AddRectAction(ApplicationManager* pApp);//non_Default constructor 

	virtual void ReadActionParameters();//Read parameter from the user

	virtual void Execute(bool);//Execute Action 

	virtual void undo();//

	virtual void redo();//
	/////////////////////////////////////////////////////////////////////////////
};

#endif