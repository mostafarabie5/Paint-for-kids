#include "ChangeDrawingAction.h"
#include"../GUI/Output.h"
#include"../GUI/Input.h"
#include"../ApplicationManager.h"

ChangeDrawingAction::ChangeDrawingAction(ApplicationManager* pApp):Action(pApp)
{
	pOut = pManager->GetOutput();
	pIn = pManager->GetInput();
}

void ChangeDrawingAction::ReadActionParameters()
{
	pOut->CreateColorBar();
	pOut->PrintMessage("Change Drawing Color. Please Choose a Color\n");
	// Choose The Color 
	do {
		Color = pIn->GetUserAction();
	} while (Color == EMPTY || Color == STATUS || Color == DRAWING_AREA);
}

void ChangeDrawingAction::Execute(bool x)
{
	
	CFigure* Selected = pManager->GetSelectedFig();
	if (Selected != NULL )
	{PlaySound("voice//Draw Color.wav",NULL,SND_ASYNC);
		if (x)
		{  
			AddUndoRedo();
			ReadActionParameters();
			pOut->CreateDrawToolBar();
			pOut->ClearStatusBar();
		}

		if (Color != EXIT)
		{ 
			Fig = pManager->GetSelectedFig();
			LastC = pOut->getCrntDrawColor();

			pManager->ChooseDrawingcolor(Color);

			Selected->ChngDrawClr(UI.DrawColor);
			New = pOut->getCrntDrawColor();
			if (pManager->GetRec())
				pManager->SendToPlay(this);
		}
	}
	else
	{PlaySound("voice//first.wav",NULL,SND_ASYNC);
		pOut->PrintMessage("Sorry, Please Select a figure first then change the color.");
	}
		
}

void ChangeDrawingAction::undo() 
{
	Output* out = pManager->GetOutput();
	swap(New, LastC);
	//Execute(0);
	Fig->ChngDrawClr(New);
	
}

void ChangeDrawingAction::redo()
{
	Output* out = pManager->GetOutput();
	swap(New, LastC);
	//Execute(0);
	Fig->ChngDrawClr(New);
}

