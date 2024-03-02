#include "AddHexaAction.h"
#include "..\Figures\CHexagon.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
AddHexaAction::AddHexaAction(ApplicationManager* pApp) :Action(pApp)
{
}
void AddHexaAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("New Hexagon  : Click at center"); //print message on stastue bar 
	pIn->GetPointClicked(center.x, center.y); //Read center from the user
	HexaGfxInfo.isFilled = UI.Filled;
	HexaGfxInfo.isFilled = UI.Filled;
	//get drawing, filling colors and pen width from the interface
	HexaGfxInfo.DrawClr = UI.DrawColor;
	HexaGfxInfo.FillClr = UI.FillColor;
	pOut->ClearStatusBar();
}
//Execute the action
void AddHexaAction::Execute(bool x)
{
	PlaySound("voice//Hexagon.wav",NULL,SND_ASYNC);
	if (x)
		ReadActionParameters();

	Fig = new CHexagon(center, HexaGfxInfo);
	pManager->AddFigure(Fig);

	if (x) {
		AddUndoRedo();
	}
	pManager->SetCanStart(0);
	if (pManager->GetRec())
		pManager->SendToPlay(this);
}

void AddHexaAction::undo()
{
	pManager->Delete(Fig);
}

void AddHexaAction::redo()
{
	Execute(0);
}
