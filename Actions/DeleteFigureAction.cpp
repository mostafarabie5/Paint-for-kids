#include "DeleteFigureAction.h"
#include"../ApplicationManager.h"


DeleteFigureAction::DeleteFigureAction(ApplicationManager* pApp):Action(pApp)
{}

void DeleteFigureAction::ReadActionParameters()
{
}

void DeleteFigureAction::Execute(bool x)
{
	
	Fig = pManager->GetSelectedFig();
	if (Fig != NULL)
	{   
		PlaySound("voice//Delete.wav",NULL,SND_ASYNC);
		Fig->SetSelected(false);
		pManager->Delete(Fig);
		pManager->SetSelectedFig(NULL);
		pManager->GetOutput()->ClearStatusBar();
		if (x) {
			AddUndoRedo();
		}
		if (pManager->GetRec())
			pManager->SendToPlay(this);
	}
	else
	{PlaySound("voice//first.wav",NULL,SND_ASYNC);
		Output* pOut = pManager->GetOutput();
		pOut->PrintMessage("Sorry , Please Select a figure first then delete it.");
	}
}

void DeleteFigureAction::undo() {
	CFigure* CurrentSelected = pManager->GetSelectedFig();
	if (CurrentSelected != NULL) {
		CurrentSelected->SetSelected(false);
	}
	x = Fig->GetId();
	pManager->AddFigure(Fig);
	Fig->SetSelected(true);
	pManager->SetSelectedFig(Fig);
	pManager->SetUnId((pManager->GetUnId()) - 1); // To avoid changing the id of the figure
	Fig->setID(x);
}
void DeleteFigureAction::redo() {
	Fig->SetSelected(0);
	pManager->Delete(Fig);
	
}