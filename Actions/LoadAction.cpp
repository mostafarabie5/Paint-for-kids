#include "LoadAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include"../Figures/CRectangle.h"
#include"../Figures/CCircle.h"
#include"../Figures/CHexagon.h"
#include"../Figures/CSquare.h"
#include"../Figures/CTriangle.h"

LoadAction::LoadAction(ApplicationManager* pApp) :Action(pApp)
{}

void LoadAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->ClearDrawArea();
	pManager->ClearAllFig();
	pOut->PrintMessage("Enter name of File ");//print message on stastue bar
	name = pIn->GetSrting(pOut);
	pOut->ClearStatusBar();
	pOut->PrintMessage("You Entered " + name);//print name on stastue bar
	pOut->ClearStatusBar();
}
//Execute the action
void LoadAction::Execute(bool x)
{
	PlaySound("voice//Load.wav",NULL,SND_ASYNC);
	if (x == true)
		ReadActionParameters();
	else
		name = "To Play Save";
	Input* pIn = pManager->GetInput();
	InFile.open(name + ".txt", ios::in);
	string s;
	InFile >> s;
	if (s == "BLUE")
		pIn->setDrawcolor(BLUE);
	else if (s == "RED")
		pIn->setDrawcolor(RED);
	else if (s == "GREEN")
		pIn->setDrawcolor(GREEN);
	else if (s == "BLACK")
		pIn->setDrawcolor(BLACK);
	else if (s == "ORANGE")
		pIn->setDrawcolor(ORANGE);
	else
		pIn->setDrawcolor(YELLOW);
	InFile >> s;
	if (s == "BLUE")
		pIn->setFillcolor(BLUE);
	else if (s == "RED")
		pIn->setFillcolor(RED);
	else if (s == "GREEN")
		pIn->setFillcolor(GREEN);
	else if (s == "BLACK")
		pIn->setFillcolor(BLACK);
	else if (s == "ORANGE")
		pIn->setFillcolor(ORANGE);

	else
		pIn->setFillcolor(YELLOW);
	int n;
	InFile >> n;
	CFigure* F = NULL;
	for (int i = 0; i < n; i++)
	{
		InFile >> s;
		if (s == "RECT")
			F = new CRectangle;
		else if (s == "SQUA")
			F = new CSquare;
		else if (s == "CIRC")
			F = new CCircle;
		else if (s == "HEXA")
			F = new CHexagon;
		else
			F = new CTriangle;

		F->Load(InFile);
		pManager->AddFigure(F);
	}
	InFile.close();
}
