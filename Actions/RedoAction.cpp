#include"RedoAction.h"
#include"../ApplicationManager.h"

RedoAction::RedoAction(ApplicationManager* pApp) :Action(pApp) {}

void RedoAction::ReadActionParameters() {}

void RedoAction::Execute(bool x) {
	if (pManager->GetOrder() < pManager->GetCnt()) {
		pManager->redo();
	}
	else {
		pManager->GetOutput()->PrintMessage(" No Actions To Redo ");
	}
	if (pManager->GetRec())
		pManager->SendToPlay(this);
}