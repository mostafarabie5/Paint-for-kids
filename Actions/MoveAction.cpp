#include "MoveAction.h"
#include "..\ApplicationManager.h"
#include"../Figures/CFigure.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

MoveAction::MoveAction(ApplicationManager* pApp):Action(pApp)
{
}

void MoveAction::ReadActionParameters()
{
	Output* out = pManager->GetOutput();
	Input* in = pManager->GetInput();
	out->PrintMessage("Move a Figure. Please Chosse a point to new destination.");
	in->GetPointClicked(p.x, p.y);

}

void MoveAction::Execute(bool x)
{
	
	CFigure* Selected = pManager->GetSelectedFig();
	if (Selected != NULL)
	{   
		PlaySound("voice//Move.wav",NULL,SND_ASYNC);
		ReadActionParameters();
		MovedFigure = pManager->GetSelectedFig();
		PrevP = MovedFigure->GetCntr();

		MovedFigure->Move(p, pManager->GetOutput());
		MovedFigure->PrintInfo(pManager->GetOutput());

		AddUndoRedo();
		if (pManager->GetRec())
			pManager->SendToPlay(this);
	}
	else
	{PlaySound("voice//first.wav",NULL,SND_ASYNC);
		Output* pOut = pManager->GetOutput(); 
		pOut->PrintMessage("Sorry, Please Select a figure first then move the figure.");
	}

}
void MoveAction::undo() {
	swap(p, PrevP);
	MovedFigure->Move(p, pManager->GetOutput());

}
void MoveAction::redo() {
	swap(p, PrevP);
	MovedFigure->Move(p, pManager->GetOutput());
}
