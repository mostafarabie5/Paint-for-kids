#include "SelectAction.h"
#include "..\Figures\CHexagon.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "../Figures/CFigure.h"
SelectAction::SelectAction(ApplicationManager* pApp) :Action(pApp)
{
}

void SelectAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Click in any figure ");//print message on stastue bar
	pIn->GetPointClicked(p.x, p.y);//Read point from the user
	pOut->ClearStatusBar();
}
//Execut the Action 
void SelectAction::Execute(bool x)
{   PlaySound("voice//Select Figure.wav",NULL,SND_ASYNC);
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	CFigure* fig = pManager->GetFigure(p.x, p.y);
	CFigure* lastfig = pManager->GetSelectedFig();
	if (fig)
	{
		if (lastfig == NULL) {
			fig->SetSelected(true);
			fig->PrintInfo(pOut);
			pManager->SetSelectedFig(fig);
		}
		else
		{
			if (lastfig == fig)
			{
				fig->SetSelected(false);
				pManager->SetSelectedFig(NULL);
			}
			else
			{
				lastfig->SetSelected(false);
				fig->SetSelected(true);
				fig->PrintInfo(pOut);
				pManager->SetSelectedFig(fig);
			}
		}
	}
	else
		if (lastfig)
		{
			lastfig->PrintInfo(pOut);
		}
}

