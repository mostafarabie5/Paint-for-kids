#include"Action.h"
#include"../ApplicationManager.h"
#include"PickFigureAction.h"
#include"../Figures/CRectangle.h"
#include"../Figures/CCircle.h"
#include"../Figures/CHexagon.h"
#include"../Figures/CSquare.h"
#include"../Figures/CTriangle.h"
#include<time.h>


PickFigureAction::PickFigureAction(ApplicationManager* pApp) :Action(pApp), LoadFile(pApp)
{
	CorrectCount = 0;
	InCorrectCount = 0;
	pOut = pManager->GetOutput();
	pIn = pManager->GetInput();
}

void PickFigureAction::ReadActionParameters()
{
	pIn->GetPointClicked(p.x, p.y);
}

void PickFigureAction::Execute(bool x)
{
	pOut->ClearStatusBar();
	pOut->PrintMessage("Pick Figures. Choose any Figure");
	pManager->ClearAllFig();

	//==================================================================================//
	//						Load Automatic Save File             						//
	//==================================================================================//
	LoadFile.Execute(false);
	pManager->UpdateInterface();
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	CFigure* Fig;

	srand(time(NULL));
	IndexOfRandomFigure = rand() % pManager->GetFigCount(); // Index of Random Chosen Figure in FigList

	NumberOfRandomFigures = pManager->NumOfRandomFigureAndType(IndexOfRandomFigure, Type); //Number of Random Chosen Figure in FigList

	while (CorrectCount < NumberOfRandomFigures)
	{
		ReadActionParameters();
		Fig = pManager->GetFigure(p.x, p.y);
		if (Fig != NULL)
		{
			if (Type == Fig->GetType()) //Check if The Random Chosen Figure and the Selected Figure The same or not
				CorrectCount++;
			else
				InCorrectCount++;

			Fig->SetSelected(true);
			pManager->DeleteFigure();  // Delete The Selected Figure
			pOut->ClearStatusBar();
			pOut->PrintMessage("Correct Selection = " + to_string(CorrectCount) + "     " + "Incorrect Selection = " + to_string(InCorrectCount));
			pManager->UpdateInterface();
		}
	}
	pOut->PrintMessage("The Number of Correct Picks = " + to_string(CorrectCount) + "     " + "The Number of InCorrect Picks = " + to_string(InCorrectCount) );
	Sleep(1000);
	pOut->PrintMessage("Game Over.");
	Sleep(1000);



}
