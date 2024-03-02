#pragma once
#include"Action.h"
#include"../ApplicationManager.h"
class RedoAction :public Action
{
public:
	RedoAction(ApplicationManager*);
	virtual void ReadActionParameters();
	virtual void Execute(bool);
};