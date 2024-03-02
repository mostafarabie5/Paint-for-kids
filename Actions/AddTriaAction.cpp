#include "AddTriaAction.h"
#include "..\Figures\CTriangle.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
AddTriaAction::AddTriaAction(ApplicationManager* pApp) :Action(pApp)
{
}

void AddTriaAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("New triangle: Click at corner one ");//print message on stastue bar
	pIn->GetPointClicked(corner1.x, corner1.y);//Read first point 
	pOut->PrintMessage("New triangle: Click at corner two");//print message on stastue bar
	pIn->GetPointClicked(corner2.x, corner2.y);//Read second point 
	pOut->PrintMessage("New triangle: Click at corner three");//print message on stastue bar
	pIn->GetPointClicked(corner3.x, corner3.y);//Read third point 
	TriaGfxInfo.isFilled = UI.Filled;
	//get drawing, filling colors and pen width from the interface
	TriaGfxInfo.DrawClr = UI.DrawColor;
	TriaGfxInfo.FillClr = UI.FillColor;
	pOut->ClearStatusBar();
}
//Execute the action
void AddTriaAction::Execute(bool x)
{
	PlaySound("voice//Triangle.wav",NULL,SND_ASYNC);
	if (x)
		ReadActionParameters();
	Fig = new CTriangle(corner1, corner2, corner3, TriaGfxInfo);
	pManager->AddFigure(Fig);
	if (x) {
		AddUndoRedo();
	}
	pManager->SetCanStart(0);
	if (pManager->GetRec())
		pManager->SendToPlay(this);
}
void AddTriaAction::undo()
{
	pManager->Delete(Fig);
}
void AddTriaAction::redo()
{
	Execute(0);
}
