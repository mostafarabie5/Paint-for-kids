#pragma once
#pragma once
#include"Action.h"

class RecordAction :public Action
{
public:
	RecordAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(bool);

};

