#include "AddCircleAction.h"
#include "..\Figures\CCircle.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
AddCircleAction::AddCircleAction(ApplicationManager* pApp) :Action(pApp)
{
}

void AddCircleAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("New circle : Click at center"); //print message on stastue bar
	pIn->GetPointClicked(center.x, center.y);  //Read center from the user
	pOut->PrintMessage("New circle: Click at circle");//print message on status bar
	pIn->GetPointClicked(redius.x, redius.y);  //Read second point that represents redius
	CircleGfxInfo.isFilled = UI.Filled;
	//get drawing, filling colors and pen width from the interface
	CircleGfxInfo.DrawClr = UI.DrawColor;
	CircleGfxInfo.FillClr = UI.FillColor;
	pOut->ClearStatusBar();
}
//Execute the action
void AddCircleAction::Execute(bool x)
{
	PlaySound("voice//Circle.wav",NULL,SND_ASYNC);
	if (x)
		ReadActionParameters();
	Fig = new CCircle(center, redius, CircleGfxInfo);
	pManager->AddFigure(Fig);

	if (x)
		AddUndoRedo();
	pManager->SetCanStart(0);
	if (pManager->GetRec())
		pManager->SendToPlay(this);
}
void AddCircleAction::undo()
{
	pManager->Delete(Fig);
}
void AddCircleAction::redo()
{
	Execute(0);
}



