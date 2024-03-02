#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

enum GUI_MODE	//Graphical user interface mode
{
	MODE_DRAW,	//Drawing mode (startup mode)
	MODE_PLAY,	//Playing mode
	MODE_COLOR
};

enum DrawMenuItem //The items of the Draw menu (you should add more items)
{
	//Note: Items are **(ordered)** here as they appear in menu
	//If you want to change the menu items order, change the order here
	ITM_PLAYMODE,
	ITM_RECT,		//Recangle item in menu
	ITM_SQUARE,     //square item in menu
	ITM_TRIANGLE,   //triangle item in menu
	ITM_HEXAGON,    //hexagon item in menu
	ITM_CIRCLE,     //Circle item in menu
	ITM_SELECTED,   //Selected item in menu
	ITM_DRAWING,
	ITM_FILLING,
	ITM_DELETED,
	ITM_MOVE,
	ITM_MOVEDRAGGING,
	ITM_UNDO,
	ITM_REDO,
	ITM_RESET,
	ITM_RECORD,
	ITM_STOP,
	ITM_PLAY,
	ITM_SAVE,
	ITM_LOAD,
	//TODO: Add more items names here

	ITM_EXIT,		//Exit item

	DRAW_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum

};

enum ColorItem
{
	COLOR_BLACK,
	COLOR_YELLOW,
	COLOR_ORANGE,
	COLOR_RED,
	COLOR_GREEN,
	COLOR_BLUE,
	COLOR_EXIT,

	COLOR_COUNT
};

enum PlayMenuItem //The items of the Play menu (you should add more items)
{
	//Note: Items are **(ordered)** here as they appear in menu
	//If you want to change the menu items order, change the order here

	//TODO: Add more items names here
	PLAY_DRAWMODE,
	PLAY_FIGURE,
	PLAY_COLOR,
	PLAY_FIGURE_COLOR,
	PLAY_EXIT,


	PLAY_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum

};





__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	GUI_MODE InterfaceMode;

	int	width, height,	    //Window width and height
		wx, wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuItemWidth;		//Width of each item in toolbar menu


	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	int PenWidth;			//width of the pen that draws shapes
	bool Filled;            //Figure is Filled or not
	/// Add more members if needed

}UI;	//create a global object UI

#endif