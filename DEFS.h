#ifndef DEFS_H
#define DEFS_H
#include "CMUgraphicsLib\CMUgraphics.h"


//This file contains some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	TO_PLAY,
	DRAW_RECT,		//Draw Rectangle
	DRAW_SQUARE,
	DRAW_TRIANGLE,
	DRAW_HEXAGON,
	DRAW_CIRCLE,
	SELECT,
	CHANGE_COLOR,
	FILL,
	DELETE_ITM,
	MOVE,
	MoveDragging,
	UNDO,
	REDO,
	RESET,
	RECORD,
	STOP,
	PLAY,
	SAVE,
	LOAD,
	EXIT,	//Exit
	TO_DRAW,		//Switch interface to Draw mode
	//Switch interface to Play mode
	PICK_FIGURE,
	PICK_COLOR,
	PICK_COLORED_FIGURE,

	EMPTY,			//A click on empty place in the toolbar
	DRAWING_AREA,	//A click on the drawing area
	STATUS,         // A click on the status bar
	//Color mode
	C_BLACK,
	C_YELLOW,
	C_ORANGE,
	C_RED,
	C_GREEN,
	C_BLUE


	///TODO: Add the other action types of the two modes
};

struct Point	//To be used for figures points
{
	int x, y;
};

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	//color currentDrawClr;
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders
};

#endif