#include"MoveByDraggingAction.h"

MoveByDraggingAction::MoveByDraggingAction(ApplicationManager* pApp) :Action(pApp)
{
	Selected = pManager->GetSelectedFig();
	pIn = pManager->GetInput();
	pOut = pManager->GetOutput();
}

void MoveByDraggingAction::ReadActionParameters()
{
	pOut->PrintMessage("you Select move by dragging. Select a Point.");
	pIn->GetPointClicked(p.x, p.y);
	while (pIn->GetPointDragged(p.x, p.y) == BUTTON_UP)
	{
		if (Selected->ToSelected(p.x, p.y))
		{
			while (pIn->GetPointDragged(p.x, p.y) == BUTTON_DOWN)
			{
				Selected->Move(p, pOut);
				Sleep(5);
				pManager->UpdateInterface();
			}
		}
	}
}

void MoveByDraggingAction::Execute(bool x)
{
	if (Selected != NULL)
		ReadActionParameters();
	else
		pOut->PrintMessage("Sorry, Please Select a figure first then move the figure.");
}
