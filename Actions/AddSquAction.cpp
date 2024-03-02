#include "AddSquAction.h"
#include "..\Figures\CSquare.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
AddSquAction::AddSquAction(ApplicationManager* pApp) :Action(pApp)
{
}

void AddSquAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("New Square: Click at center");
	pIn->GetPointClicked(center.x, center.y);
	SquGfxInfo.isFilled = UI.Filled;
	//get drawing, filling colors and pen width from the interface
	SquGfxInfo.DrawClr = UI.DrawColor;
	SquGfxInfo.FillClr = UI.FillColor;
	pOut->ClearStatusBar();
}
//Execute the action
void AddSquAction::Execute(bool x)
{
	PlaySound("voice//Square.wav",NULL,SND_ASYNC);
	if (x)
		ReadActionParameters();
	Fig = new CSquare(center, SquGfxInfo);
	pManager->AddFigure(Fig);
	if (x)
		AddUndoRedo();

	pManager->SetCanStart(0);
	if (pManager->GetRec())
		pManager->SendToPlay(this);
}

void AddSquAction::undo()
{
	pManager->Delete(Fig);
	pManager->UpdateInterface();
}

void AddSquAction::redo()
{
	Execute(0);
}
