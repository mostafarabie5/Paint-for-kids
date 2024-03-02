#include "Input.h"
#include "Output.h"


Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int& x, int& y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

buttonstate Input::GetPointDragged(int& x, int& y) const
{
	return pWind->GetButtonState(LEFT_BUTTON, x, y);
}

string Input::GetSrting(Output* pO) const
{
	string Label;
	char Key;
	while (1)
	{
		pWind->WaitKeyPress(Key);
		if (Key == 27)	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
			return Label;
		if ((Key == 8) && (Label.size() >= 1))	//BackSpace is pressed
			Label.resize(Label.size() - 1);
		else
			Label += Key;
		if (pO)
			pO->PrintMessage(Label);
	}
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{
	int x, y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if (UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_PLAYMODE:return TO_PLAY;
			case ITM_RECT: return DRAW_RECT;
			case ITM_SQUARE:return DRAW_SQUARE;
			case ITM_TRIANGLE:return DRAW_TRIANGLE;
			case ITM_HEXAGON:return DRAW_HEXAGON;
			case ITM_CIRCLE:return DRAW_CIRCLE;
			case ITM_SELECTED:return SELECT;
			case ITM_DRAWING:return CHANGE_COLOR;
			case ITM_FILLING:return FILL;
			case ITM_DELETED:return DELETE_ITM;
			case ITM_MOVE:return MOVE;
			case ITM_MOVEDRAGGING:return MoveDragging;
			case ITM_UNDO:return UNDO;
			case ITM_REDO:return REDO;
			case ITM_RESET:return RESET;
			case ITM_RECORD:return RECORD;
			case ITM_STOP:return STOP;
			case ITM_PLAY:return PLAY;
			case ITM_SAVE:return SAVE;
			case ITM_LOAD:return LOAD;
			case ITM_EXIT: return EXIT;

			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;
	}
	else if (UI.InterfaceMode == MODE_PLAY)	//GUI is in PLAY mode
	{
		if (y >= 0 && y < UI.ToolBarHeight) {
			int u = (x / UI.MenuItemWidth);
			switch (u) {
			case PLAY_DRAWMODE:return TO_DRAW;
			case PLAY_FIGURE:return PICK_FIGURE;
			case PLAY_COLOR: return PICK_COLOR;
			case PLAY_FIGURE_COLOR: return PICK_COLORED_FIGURE;
			case PLAY_EXIT: return EXIT;
			default: return EMPTY;
			}
		}
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}
		return STATUS;
		///TODO:
		//perform checks similar to Draw mode checks above
		//and return the correspoding action
		return TO_PLAY;	//just for now. This should be updated
	}
	else
	{
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			int u = (x / UI.MenuItemWidth);
			switch (u) {
			case COLOR_BLACK: return C_BLACK;
			case COLOR_YELLOW:return C_YELLOW;
			case COLOR_ORANGE:return C_ORANGE;
			case COLOR_RED: return C_RED;
			case COLOR_GREEN: return C_GREEN;
			case COLOR_BLUE: return C_BLUE;
			case COLOR_EXIT:return EXIT;
			default: return EMPTY;
			}

		}
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}
		return STATUS;
	}

}
void Input::setDrawcolor(color c)
{

	UI.DrawColor = c;
}
void Input::setFillcolor(color c)
{
	UI.FillColor = c;

}
/////////////////////////////////

Input::~Input()
{
}
