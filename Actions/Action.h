#ifndef ACTION_H
#define ACTION_H

#include "..\DefS.h"
#include"../ApplicationManager.h"

class ApplicationManager; //forward class declaration


//Base class for all possible actions
class Action
{
protected:
	//////////////////////////// DATA....MEMBER ///////////////////////////////

	ApplicationManager* pManager;	//Actions needs AppMngr to do their job  

 ///////////////////////////////////////////////////////////////////////////
public:
	///////////////////////////  MEMBER .. FUNCTIONS ///////////////////////////
	Action(ApplicationManager* pApp);	//constructor

	//Reads parameters required for action to execute 
	virtual void ReadActionParameters() = 0;

	//Execute action 
	virtual void Execute(bool x = true) = 0;

	virtual void undo();  //

	virtual void redo();  //

	void AddUndoRedo();  //
	/////////////////////////////////////////////////////////////////////////////
};

#endif