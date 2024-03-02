#include "ApplicationManager.h"
#include"Actions/Action.h"
#include"Actions/AddCircleAction.h"
#include"Actions/AddHexaAction.h"
#include"Actions/AddRectAction.h"
#include"Actions/AddSquAction.h"
#include"Actions/AddTriaAction.h"
#include"Actions/ChangeDrawingAction.h"
#include"Actions/ChangeFillAction.h"
#include"Actions/DeleteFigureAction.h"
#include"Actions/ExitAction.h"
#include"Actions/LoadAction.h"
#include"Actions/MoveAction.h"
#include"Actions/MoveByDraggingAction.h"
#include"Actions/PickFigureAction.h"
#include"Actions/PickFigureColorAction.h"
#include"Actions/PickFillingColorAction.h"
#include"Actions/PlayAction.h"
#include"Actions/RecordAction.h"
#include"Actions/RedoAction.h"
#include"Actions/ResetAction.h"
#include"Actions/SaveAction.h"
#include"Actions/SelectAction.h"
#include"Actions/StopAction.h"
#include"Actions/SwitchToDrawModeAction.h"
#include"Actions/SwitchToPlayModeAction.h"
#include"Actions/UndoAction.h"
#include <Windows.h>


//Constructor
ApplicationManager::ApplicationManager():rec(false), CanStart(true), CanPlay(false)
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	SelectedFig = NULL;
	UniqueID = 0;
	FigCount = 0;
	UndoRedocnt = 0;
	RecCnt = 0;
	order = 0;
	//Create an array of figure pointers and set them to NULL		
	for (int i = 0; i < MaxFigCount; i++)
		FigList[i] = NULL;

	for (int i = 0; i < 5; i++)
		UndoRedo[i] = NULL;
	
	for (int i = 0; i < 20; i++)
		ToPlay[i] = NULL;
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = NULL;

	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
	case TO_PLAY:
		pAct = new SwitchToPlayModeAction(this);
		break;
	case DRAW_RECT:
		pAct = new AddRectAction(this);
		break;
	case DRAW_SQUARE:
		pAct = new AddSquAction(this);
		break;
	case DRAW_TRIANGLE:
		pAct = new AddTriaAction(this);
		break;

	case DRAW_HEXAGON:
		pAct = new AddHexaAction(this);
		break;

	case DRAW_CIRCLE:
		pAct = new AddCircleAction(this);
		break;

	case SELECT:
		pAct = new SelectAction(this);
		break;

	case CHANGE_COLOR:
		pAct = new ChangeDrawingAction(this);
		break;

	case FILL:
		pAct = new ChangeFillAction(this);
		break;

	case DELETE_ITM:
		pAct = new DeleteFigureAction(this);
		break;

	case MOVE:
		pAct = new MoveAction(this);
		break;

	case MoveDragging:
		pAct = new MoveByDraggingAction(this);
		break;

	case UNDO:
		pAct = new UndoAction(this);
		break;

	case REDO:
		pAct = new RedoAction(this);
		break;

	case RESET:
		pAct = new ResetAction(this);
		break;

	case RECORD:
		pAct = new RecordAction(this);
		break;

	case STOP:
		pAct = new StopAction(this);
		break;

	case PLAY:
		pAct = new PlayAction(this);
		break;

	case SAVE:
		pAct = new SaveAction(this);
		break;

	case  LOAD:
		pAct = new LoadAction(this);

		break;

	case TO_DRAW:
		pAct = new SwitchToDrawModeAction(this);
		break;

	case PICK_FIGURE:
		pAct = new PickFigureAction(this);
		break;

	case PICK_COLOR:
		pAct = new PickFillingColorAction(this);
		break;


	case PICK_COLORED_FIGURE:
		pAct = new PickFigureColorAction(this);
		break;

	case EMPTY:
		break;

	case DRAWING_AREA:
		break;


	case EXIT:
		pAct = new ExitAction(this);
		break;

	case STATUS:	//a click on the status bar ==> no action
		return;
	}

	//Execute the created action
	if (pAct != NULL)
	{
		pAct->Execute(true);//Execute
		pAct = NULL;
	}
}

// Choose Color Action
void ApplicationManager::ChooseDrawingcolor(ActionType ActType)
{
	switch (ActType)
	{
	case C_BLACK:
		UI.DrawColor = BLACK;
		break;
	case C_YELLOW:
		UI.DrawColor = YELLOW;
		break;
	case C_ORANGE:
		UI.DrawColor = ORANGE;
		break;
	case C_RED:
		UI.DrawColor = RED;
		break;
	case C_GREEN:
		UI.DrawColor = GREEN;
		break;
	case C_BLUE:
		UI.DrawColor = BLUE;
		break;
	}

}

void ApplicationManager::ChooseFillingcolor(ActionType ActType)
{
	switch (ActType)
	{
	case C_BLACK:
		UI.FillColor = BLACK;
		break;
	case C_YELLOW:
		UI.FillColor = YELLOW;
		break;
	case C_ORANGE:
		UI.FillColor = ORANGE;
		break;
	case C_RED:
		UI.FillColor = RED;
		break;
	case C_GREEN:
		UI.FillColor = GREEN;
		break;
	case C_BLUE:
		UI.FillColor = BLUE;
		break;
	}
}
////////////////////////////////////////////////////////////////////////

//setter for selected figure 
void ApplicationManager::SetSelectedFig(CFigure* fig)
{
	SelectedFig = fig;
}

//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if (FigCount < MaxFigCount)
	{
		FigList[FigCount] = pFig;
		FigList[FigCount]->setID(UniqueID++);
		FigCount++;
	}
}
////////////////////////////////////////////////////////////////////////////////////
CFigure* ApplicationManager::GetFigure(int x, int y) const// when get click in drawing area 
{
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->ToSelected(x, y))
			return FigList[i];
	}
	return NULL;

	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL
}

//==================================================================================//
//						Delete selected figure             							//
//==================================================================================//

void ApplicationManager::DeleteFigure()
{
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->IsSelected())
		{
			delete FigList[i];
			FigList[i] = FigList[FigCount - 1];
			FigList[FigCount-- - 1] = NULL;
			SelectedFig = NULL;
			return;
		}
	}
}
	

int ApplicationManager::GetFigCount() const
{
	return FigCount;//Return number of the figure
}

CFigure* ApplicationManager::GetSelectedFig()
{
	return SelectedFig; //return selected figure 
}
 //deallocate all the figure to load a file 
void ApplicationManager::ClearAllFig()
{
	for (int i = 0; i < FigCount; i++)
	{
		delete FigList[i];
		FigList[i] = NULL;
	}
	UniqueID=0;
	FigCount = 0;
	SelectedFig = NULL;
}

//==================================================================================//
//						Number of Random Figures             						//
//==================================================================================//
int ApplicationManager::NumOfRandomFigureAndType(const int& index, string& Type)
{
	int NumOfRandomFigure = 0;
	Type = FigList[index]->GetType();
	for (int i = 0; i < FigCount; i++)
	{
		if (Type == FigList[i]->GetType())
			NumOfRandomFigure++;
	}
	return NumOfRandomFigure;
}


int ApplicationManager::NumOfRandomColor(const int& index, color& FillColor)
{
	int NumOfRandomFigure = 0;
	FillColor = FigList[index]->GetFillingColor();
	for (int i = 0; i < FigCount; i++)
	{
		if (FillColor == FigList[i]->GetFillingColor())
			NumOfRandomFigure++;
	}
	return NumOfRandomFigure;
}


int ApplicationManager::NumOfRandomFigureColor(const int& index, string& Type, color& FillColor)
{
	int NumOfRandomFigure = 0;
	Type = FigList[index]->GetType();
	FillColor = FigList[index]->GetFillingColor();
	for (int i = 0; i < FigCount; i++)
	{
		if (FillColor == FigList[i]->GetFillingColor() && Type == FigList[i]->GetType())
			NumOfRandomFigure++;
	}
	return NumOfRandomFigure;
}

//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{
	pOut->ClearDrawArea();
	for (int i = 0; i < FigCount; i++)
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
	//pOut->ClearStatusBar();
	if (SelectedFig != NULL)
		SelectedFig->PrintInfo(pOut);
}

void ApplicationManager::Reset()
{
	ClearAllFig();
	for (int i = 0; i < 5; i++)
		UndoRedo[i] = NULL;
	for (int i = 0; i < 20; i++)
		ToPlay[i] = NULL;
	UniqueID = 0;
	UndoRedocnt = 0;
	RecCnt = 0;
	order = 0;
	rec = false;
	CanStart = true;
	CanPlay = false;
	delete pOut;
	pOut = new Output;
	delete pIn;
	pIn = pOut->CreateInput();

}

////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input* ApplicationManager::GetInput() const
{
	return pIn;
}
//Return /a pointer to the output
Output* ApplicationManager::GetOutput() const
{
	return pOut;
}
////////////////////////////////////////////////////////////////////////////////////


void ApplicationManager::SaveAll(ofstream& OutFile)
{
	for (int i = 0; i < FigCount; i++)///loop and call to save each figure 
	{
		FigList[i]->Save(OutFile);
	}
}


CFigure* ApplicationManager::LastFigure()
{
	return FigList[FigCount-1];
}
//Destructor
ApplicationManager::~ApplicationManager()
{
	for (int i = 0; i < FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;

}


void ApplicationManager::SetCanStart(bool x) {
	CanStart = x;
}
void ApplicationManager::SetRec(bool x) {
	rec = x;
}
void ApplicationManager::SetCanP(bool x) {
	CanPlay = x;
}
void ApplicationManager::SetRecCnt(int x) {
	RecCnt = 0;
}
bool ApplicationManager::GetCanP() { return CanPlay; }
bool ApplicationManager::GetRec() { return rec; }
bool ApplicationManager::GetCanStart() { return CanStart; }
void ApplicationManager::SendToPlay(Action* x) {
	ToPlay[RecCnt++] = x;
}
void ApplicationManager::PlayRec() {
	for (int i = 0; i < RecCnt; i++)
	{
		Sleep(1000);
		ToPlay[i]->Execute(0);
		UpdateInterface();
	}
}
int ApplicationManager::GetOrder() {
	return order;
}
int ApplicationManager::GetCnt() {
	return UndoRedocnt;
}

void ApplicationManager::Delete(CFigure* x) {
	for(int i =0;i<FigCount;i++){
		if(FigList[i]==x){
			if(x->IsSelected()){
				SetSelectedFig(NULL);
			}
			FigList[i]=FigList[--FigCount];
			FigList[FigCount]=NULL;
		}
    }
}
void ApplicationManager::SendToAction(Action* x) {
	for (int i = order; i < UndoRedocnt; i++)
	{
		UndoRedo[i] = NULL;
	}
	UndoRedo[order++] = x;
	UndoRedocnt = order;
}

void ApplicationManager::SendBack() {
	UndoRedo[0] = NULL;
	for (int i = 0; i < 4; i++)
	{
		UndoRedo[i] = UndoRedo[i + 1];
	}
	order = 4;
	UndoRedo[4] = NULL;
}
void ApplicationManager::undo() {
	UndoRedo[--order]->undo();
}
void ApplicationManager::redo() {
	UndoRedo[order++]->redo();
}
void ApplicationManager::SetUnId(int x) {
	UniqueID = x;
}
int ApplicationManager::GetUnId() {
	return UniqueID;
}
void ApplicationManager::CleanPlay(){
	for (int i = 0; i < RecCnt; i++)
	{
		ToPlay[i]=NULL;
	}
}