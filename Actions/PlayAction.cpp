#include "PlayAction.h"


PlayAction::PlayAction(ApplicationManager* pApp) :Action(pApp)
{
}


void PlayAction::ReadActionParameters() {}

void PlayAction::Execute(bool x) {
	Output* pOut = pManager->GetOutput();
	if (pManager->GetCanP()) {
		pManager->ClearAllFig();
		pManager->GetOutput()->ClearDrawArea();
		pManager->PlayRec();
		pManager->CleanPlay();
		pManager->SetCanP(0);
		pManager->SetRecCnt(0);
	}
	else
		pOut->PrintMessage(" No Recording to be Played ");
}
