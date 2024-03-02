#include "SaveAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"


SaveAction::SaveAction(ApplicationManager* pApp) :Action(pApp)
{}

void SaveAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Enter name of File ");//print message on stastue bar
	name = pIn->GetSrting(pOut);
	pOut->ClearStatusBar();
	pOut->PrintMessage("You Entered " + name);//print name on stastue bar
	pOut->ClearStatusBar();
}
//Execute the action
void SaveAction::Execute(bool x)
{
	PlaySound("voice//Save.wav",NULL,SND_ASYNC);
	if (x)
		ReadActionParameters();
	else
		name = "To Play Save";
	OutFile.open(name + ".txt", ios::out);
	Output* pOut = pManager->GetOutput();

	if (pOut->getCrntDrawColor() == BLUE)
		OutFile << "BLUE" << "   ";
	else if (pOut->getCrntDrawColor() == RED)
		OutFile << "RED" << "   ";
	else if (pOut->getCrntDrawColor() == GREEN)
		OutFile << "GREEN" << "   ";
	else if (pOut->getCrntDrawColor() == BLACK)
		OutFile << "BLACK" << "   ";
	else if (pOut->getCrntDrawColor() == ORANGE)
		OutFile << "ORANGE" << "   ";
	else
		OutFile << "YELLOW" << "   ";

	if (pOut->getCrntFillColor() == BLUE)
		OutFile << "BLUE" << endl;
	else if (pOut->getCrntFillColor() == RED)
		OutFile << "RED" << endl;
	else if (pOut->getCrntFillColor() == GREEN)
		OutFile << "GREEN" << endl;
	else if (pOut->getCrntFillColor() == BLACK)
		OutFile << "BLACK" << endl;
	else if (pOut->getCrntFillColor() == ORANGE)
		OutFile << "ORANGE" << endl;
	else
		OutFile << "YELLOW" << endl;

	OutFile << pManager->GetFigCount() << endl;
	pManager->SaveAll(OutFile);
	OutFile.close();
}
