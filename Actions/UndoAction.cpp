#include"UndoAction.h"
UndoAction::UndoAction(ApplicationManager* pApp) :Action(pApp) {}

void UndoAction::ReadActionParameters() {}
void UndoAction::Execute(bool x) {
	if (pManager->GetOrder()) {
		pManager->undo();
	}
	else {
		pManager->GetOutput()->PrintMessage(" Error , No Actions to be undone ");
		if (pManager->GetRec())
			pManager->SendToPlay(this);
	}
}
void UndoAction::undo() {}