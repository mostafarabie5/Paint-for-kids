#include"Action.h"

Action::Action(ApplicationManager* pApp) :pManager(pApp)
{
}

void Action::undo()
{
}

void Action::redo()
{
}

void Action::AddUndoRedo() // A function that sends every Action to Undo/Redo Array
{
	if (pManager->GetOrder() == 5) {
		pManager->SendBack();
	}
	pManager->SendToAction(this);
}
