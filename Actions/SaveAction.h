#pragma once
#include "Action.h"
#include <fstream>
#include <string.h>



class SaveAction :public Action
{
	//////////////////////////..DATA..MEMBER..//////////////////////////
	ofstream OutFile; 
	string name;
	///////////////////////////////////////////////////////////////////
public:
	///////////////////////////..FUNCTION..///////////////////////////

	SaveAction(ApplicationManager* pApp);// non_default constructor 

	virtual void ReadActionParameters();//Read parameter from the user

	virtual void Execute(bool x);// Execute the Action 
	//////////////////////////////////////////////////////////////////
};

