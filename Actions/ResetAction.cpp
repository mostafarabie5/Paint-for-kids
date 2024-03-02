#include"ResetAction.h"

ResetAction::ResetAction(ApplicationManager* pApp):Action(pApp)
{
}

void ResetAction::ReadActionParameters()
{
}

void ResetAction::Execute(bool x)
{
	ReadActionParameters();
	pManager->Reset();

}
