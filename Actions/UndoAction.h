#pragma once
#include"Action.h"
#include"../ApplicationManager.h"
class UndoAction :public Action {
public:
	UndoAction(ApplicationManager*);
	virtual void ReadActionParameters();
	virtual void Execute(bool);
	virtual void undo();
};