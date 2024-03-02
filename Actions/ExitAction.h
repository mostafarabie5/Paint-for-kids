#pragma once
#include"Action.h"

class ExitAction : public Action
{
protected:

public:
	ExitAction(ApplicationManager* pApp);	//constructor

	//Reads parameters required for action to execute (code depends on action type)
	virtual void ReadActionParameters() ;

	//Execute action (code depends on action type)
	virtual void Execute(bool x) ;

};