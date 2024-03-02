#pragma once
#include "Action.h"
#include <fstream>
#include <string.h>
class LoadAction :public Action
{
	/////////////////////////////..DATA..MEMBER..////////////////////////
	ifstream InFile;
	string name;
	///////////////////////////////////////////////////////////////////
public:
	/////////////////////////////...FUNCTIONS..////////////////////////

	LoadAction(ApplicationManager* pApp);// non_default constructor 

	virtual void ReadActionParameters();//Read parameter from the user

	virtual void Execute(bool x);// Execute the Action 
	//////////////////////////////////////////////////////////////////
};

