#pragma once
#include"Action.h"
#include"fstream"
#include"../ApplicationManager.h"
#include"SaveAction.h"

class SwitchToPlayModeAction : public Action
{
protected:
	SaveAction SaveFile;
	ofstream OutFile;
public:
	SwitchToPlayModeAction(ApplicationManager* pApp);	//constructor

	//Reads parameters required for action to execute (code depends on action type)
	virtual void ReadActionParameters();

	//Execute action (code depends on action type)
	virtual void Execute(bool x);


};
