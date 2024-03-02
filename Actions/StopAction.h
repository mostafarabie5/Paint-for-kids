#pragma once
#include"Action.h"

class StopAction :public Action
{
public:
	StopAction(ApplicationManager*);
	virtual void ReadActionParameters();
	virtual void Execute(bool);

};


