#pragma once
#include"Action.h"
class ResetAction :public Action
{
protected:

public:
	ResetAction(ApplicationManager* pApp);	//constructor

	//Reads parameters required for action to execute (code depends on action type)
	virtual void ReadActionParameters();

	//Execute action (code depends on action type)
	virtual void Execute(bool x = true);
};
