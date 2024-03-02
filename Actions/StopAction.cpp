#include "StopAction.h"
#include"../ApplicationManager.h"

StopAction::StopAction(ApplicationManager* pApp) :Action(pApp)
{
}


void StopAction::ReadActionParameters() {}

void StopAction::Execute(bool x) {
	PlaySound("voice//Stop recording.wav",NULL,SND_ASYNC);
	Output* pOut = pManager->GetOutput();
	if (pManager->GetRec()) {
		pManager->SetRec(0);
		pOut->PrintMessage(" Stopped Recording ");
		pManager->SetCanP(1);
	}
	else
	{	PlaySound("voice//You are not recordin.wav",NULL,SND_ASYNC);
		pOut->PrintMessage(" Error , No Recording is happening ");
	    }
	}

