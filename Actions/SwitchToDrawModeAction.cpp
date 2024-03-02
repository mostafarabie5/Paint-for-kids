#include "SwitchToDrawModeAction.h"
#include"../Figures/CRectangle.h"
#include"../Figures/CCircle.h"
#include"../Figures/CHexagon.h"
#include"../Figures/CSquare.h"
#include"../Figures/CTriangle.h"

SwitchToDrawModeAction::SwitchToDrawModeAction(ApplicationManager* pApp) :Action(pApp), LoadFile(pApp)
{
}

void SwitchToDrawModeAction::ReadActionParameters()
{

}

void SwitchToDrawModeAction::Execute(bool x)
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	pOut->CreateDrawToolBar();
	pOut->ClearStatusBar();
	pManager->ClearAllFig();
	LoadFile.Execute(false);
}
