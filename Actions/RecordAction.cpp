#include "RecordAction.h"
#include"../ApplicationManager.h"
#include "..\GUI\Output.h"

RecordAction::RecordAction(ApplicationManager* pApp) :Action(pApp)
{
}

void RecordAction::ReadActionParameters() {}

void RecordAction::Execute(bool x) {
	PlaySound("voice//Start recording.wav",NULL,SND_ASYNC);
	Output* pOut = pManager->GetOutput();
	pOut->ClearStatusBar();
	if (pManager->GetCanStart()) {
	   
		pManager->SetRec(1);
		pOut->PrintMessage(" Started Recording ");
	}
	else{
		PlaySound("voice//cant.wav",NULL,SND_ASYNC);
		pOut->PrintMessage(" Error , Can't Start RecordActioning ");
       }
}