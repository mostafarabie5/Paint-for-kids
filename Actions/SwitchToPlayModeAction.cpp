#include "SwitchToPlayModeAction.h"
#include"../ApplicationManager.h"

SwitchToPlayModeAction::SwitchToPlayModeAction(ApplicationManager* pApp) :Action(pApp), SaveFile(pApp)
{
}

void SwitchToPlayModeAction::ReadActionParameters()
{

}

void SwitchToPlayModeAction::Execute(bool x)
{
	if (pManager->GetFigCount() != 0)
	{
		ReadActionParameters();
		Output* pOut = pManager->GetOutput();
		pOut->CreatePlayToolBar();
		pOut->ClearStatusBar();
		SaveFile.Execute(false);
	}
	else
	{
		Output* pOut = pManager->GetOutput();
		pOut->PrintMessage("Sorry, This option is available since There isn't any Figures to play on.");
	}
}
