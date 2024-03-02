#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"
#include <xkeycheck.h>
#include"CMUgraphicsLib/colors.h"


class Action;

//Main class that manages everything in the application.
class ApplicationManager
{

	enum { MaxFigCount = 200 };	//Max no of figures

private:
	///////////////////////////////////////////////////////////////////////////////////////////
	int FigCount; //Actual number of figures
	int UniqueID; // Unique Id for each Figure
	int order; // Order used to determing the action to undo/redo
	int UndoRedocnt; // Number of Actions in Undo/Redo Array
	int RecCnt; // Number of Actions To Play
	bool rec; // Boolean states wether the program is recording or not
	bool CanStart; // Boolean states wether the program can start recording or not
	bool CanPlay; // Boolean states wether the program can start playing a recored (the record isn't empty)
	Action* UndoRedo[5]; // list of actions to undo or redo
	Action* ToPlay[20]; // list of Recorded Actions
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)
	CFigure* SelectedFig; //Pointer to the selected figure
	//Pointers to Input and Output classes
	Input* pIn;
	Output* pOut;
	///////////////////////////////////////////////////////////////////////////////////////

public:
	//////////////////////////////////////////////////////////////////////////////////////
	ApplicationManager();//Default constructor 

	~ApplicationManager();//Destructor 

	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const; // Get which Action is done 

	void ExecuteAction(ActionType); //Creates an action and executes it

	void SetSelectedFig(CFigure* fig); // set the sellected fig

	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList

	CFigure* GetFigure(int x, int y)const; //Search for a figure given a point inside the figure

	void DeleteFigure();  //Delete figure from the figlist  

	void ChooseDrawingcolor(ActionType); // set the choosen drawing color 

	void ChooseFillingcolor(ActionType); //set the choosen filling color

	void ClearAllFig();  //Delete all figure 

	CFigure* GetSelectedFig(); //Return selected figure 

	int GetFigCount()const; //return number of figure 

	int GetOrder();// Function to get order value
	void SendToAction(Action*);// Function to send Actions to undo/redo array
	void SendBack();// Function to relay the actions to receive a new action
	void undo();// Function That calls the undo function for every action
	void redo();// Function That calls the redo function for every action
	void Delete(CFigure*);// Function that deletes the passed figure
	void SendToPlay(Action*);// Function that send actions to recording array of actions
	void SetRec(bool);// Function that sets a value for the boolean "rec"
	bool GetRec();// Function that returns a value for the boolean "rec"
	void SetCanStart(bool);// Function that sets a value for the boolean "CanStart"
	bool GetCanStart();// Function that returns a value for the boolean "CanStart"
	void SetCanP(bool);// Function that sets a value for the boolean "CanPlay"
	bool GetCanP();// Function that gets a value for the boolean "CanPlay"
	int GetCnt();// Function the returns a value for "UndoRedoCnt"
	void SetRecCnt(int x);// Function the sets a value for "Rec cnt"
	void PlayRec();// Function that Execute Actions in recording array
	void SetUnId(int);// Function that sets the Uniqueid for a value
	int GetUnId();// Function that gets a value for the Uniqueid
	void CleanPlay();// Function that sets all actions in recording array to NULL after playing
	// Functions Related to Play mode
	int NumOfRandomFigureAndType(const int& index, string& Type);//
	int NumOfRandomColor(const int& index, color& Type);//
	int NumOfRandomFigureColor(const int&, string&, color&);//


	// -- Interface Management Functions
	Input* GetInput() const; //Return pointer to the input
	Output* GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window	
	void Reset();//

	void SaveAll(ofstream& Output);//Save all figure in the figlist
	CFigure* LastFigure();//
};

#endif