#include "ChangeFillAction.h"

ChangeFillAction::ChangeFillAction(ApplicationManager* pApp) :Action(pApp)
{
	pOut = pManager->GetOutput();
	pIn = pManager->GetInput();
}

void ChangeFillAction::ReadActionParameters()
{
	pOut->CreateColorBar();
	pOut->PrintMessage("Change Filling Color. Please Choose a color\n");
	do {
		Color = pIn->GetUserAction();
	} while (Color == EMPTY || Color == STATUS || Color == DRAWING_AREA);
}

void ChangeFillAction::Execute(bool x)
{   
	
	CFigure* Selected = pManager->GetSelectedFig();
	if (Selected != NULL)
	{
		PlaySound("voice//Fill Color.wav",NULL,SND_ASYNC);
		if (x) {
			AddUndoRedo();
			ReadActionParameters();
			pOut->CreateDrawToolBar();
			pOut->ClearStatusBar();
		}
		if (Color !=EXIT)
		{ 
			Fig = pManager->GetSelectedFig();
			prevcolor = pOut->getCrntFillColor();
			lastfill = pOut->IsFilled();
			fillstate = true;
			pManager->ChooseFillingcolor(Color);
			choosencolor = pOut->getCrntFillColor();
			Fig->ChngFillClr(choosencolor, fillstate);
			if (pManager->GetRec())
				pManager->SendToPlay(this);
		}
	}
	else
	{PlaySound("voice//first.wav",NULL,SND_ASYNC);
		pOut->PrintMessage("Sorry, Please Select a figure first then change the color.");
	}
}
void ChangeFillAction::undo() {
	swap(fillstate, lastfill);
	swap(choosencolor, prevcolor);
	Fig->ChngFillClr(choosencolor, fillstate);
}
void ChangeFillAction::redo() {
	swap(fillstate, lastfill);
	swap(choosencolor, prevcolor);
	Fig->ChngFillClr(choosencolor, fillstate);
}
