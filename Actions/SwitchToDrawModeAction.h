#pragma once
#include"Action.h"
#include<fstream>
#include"../ApplicationManager.h"
#include"LoadAction.h"

class SwitchToDrawModeAction : public Action
{
protected:
	LoadAction LoadFile;
	ifstream InFile;
public:
	SwitchToDrawModeAction(ApplicationManager* pApp);	//constructor

	//Reads parameters required for action to execute (code depends on action type)
	virtual void ReadActionParameters();

	//Execute action (code depends on action type)
	virtual void Execute(bool x);

};
