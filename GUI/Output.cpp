#include "Output.h"

Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;

	UI.width = 1540;
	UI.height = 650;
	UI.height = 650;
	UI.wx = 5;
	UI.wy = 5;


	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 70;

	UI.DrawColor = BLUE;	//Drawing color
	UI.FillColor = GREEN;	//Filling color
	UI.MsgColor = RED;		//Messages color
	UI.BkGrndColor = LIGHTGOLDENRODYELLOW;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = TURQUOISE;
	UI.PenWidth = 3;	//width of the figures frames
	UI.Filled = false;


	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");

	CreateDrawToolBar();
	CreateStatusBar();
}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearToolBar() const
{
	// Clear Toolbar when switching to play mode or choose the color 
	pWind->SetPen(WHITE, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() const
{
	UI.InterfaceMode = MODE_DRAW;

	ClearToolBar();  // clear toolbar for safety before creating icons

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem

	//TODO: Prepare images for each menu item and add it to the list

	string MenuItemImages[DRAW_ITM_COUNT];
	MenuItemImages[ITM_RECT] = "images\\MenuItems\\Rectangle.jpg";
	MenuItemImages[ITM_SQUARE] = "images\\MenuItems\\Square.jpg";
	MenuItemImages[ITM_TRIANGLE] = "images\\MenuItems\\Triangle.jpg";
	MenuItemImages[ITM_HEXAGON] = "images\\MenuItems\\Hexagon.jpg";
	MenuItemImages[ITM_CIRCLE] = "images\\MenuItems\\Circle.jpg";
	MenuItemImages[ITM_SELECTED] = "images\\MenuItems\\Menu_Selected.jpg";
	MenuItemImages[ITM_DRAWING] = "images\\MenuItems\\Drawing.jpg";
	MenuItemImages[ITM_FILLING] = "images\\MenuItems\\Fill.jpg";
	MenuItemImages[ITM_DELETED] = "images\\MenuItems\\Delete.jpg";
	MenuItemImages[ITM_MOVE] = "images\\MenuItems\\Move.jpg";
	MenuItemImages[ITM_MOVEDRAGGING] = "images\\MenuItems\\MoveByDragging.jpg";
	MenuItemImages[ITM_UNDO] = "images\\MenuItems\\Undo.jpg";
	MenuItemImages[ITM_REDO] = "images\\MenuItems\\Redo.jpg";
	MenuItemImages[ITM_RESET] = "images\\MenuItems\\Reset.jpg";
	MenuItemImages[ITM_RECORD] = "images\\MenuItems\\Record.jpg";
	MenuItemImages[ITM_STOP] = "images\\MenuItems\\Stop.jpg";
	MenuItemImages[ITM_PLAY] = "images\\MenuItems\\Play.jpg";
	MenuItemImages[ITM_SAVE] = "images\\MenuItems\\Save.jpg";
	MenuItemImages[ITM_LOAD] = "images\\MenuItems\\Load.jpg";
	MenuItemImages[ITM_PLAYMODE] = "images\\MenuItems\\switch to play mode.jpg";

	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\Menu_Exit.jpg";



	//Draw menu item one image at a time
	for (int i = 0; i < DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateColorBar() const
{

	ClearToolBar();      // clear toolbar for safety before creating icons

	UI.InterfaceMode = MODE_COLOR;
	string ColorItem[COLOR_COUNT];

	ColorItem[COLOR_BLACK] = "images\\MenuItems\\Black.jpg";
	ColorItem[COLOR_YELLOW] = "images\\MenuItems\\Yellow.jpg";
	ColorItem[COLOR_ORANGE] = "images\\MenuItems\\Orange.jpg";
	ColorItem[COLOR_RED] = "images\\MenuItems\\Red.jpg";
	ColorItem[COLOR_GREEN] = "images\\MenuItems\\Green.jpg";
	ColorItem[COLOR_BLUE] = "images\\MenuItems\\Blue.jpg";
	ColorItem[COLOR_EXIT] = "images\\MenuItems\\Menu_Exit.jpg";

	for (int i = 0; i < COLOR_COUNT; i++)
		pWind->DrawImage(ColorItem[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreatePlayToolBar() const
{
	ClearToolBar();        // clear toolbar for safety before creating icons

	UI.InterfaceMode = MODE_PLAY;
	///TODO: write code to create Play mode menu
	string PlayItemImages[PLAY_ITM_COUNT];
	PlayItemImages[PLAY_DRAWMODE] = "images\\MenuItems\\switch to drawing mode.jpg";
	PlayItemImages[PLAY_FIGURE] = "images\\MenuItems\\Pick_Figure.jpg";
	PlayItemImages[PLAY_COLOR] = "images\\MenuItems\\Pick_Color.jpg";
	PlayItemImages[PLAY_FIGURE_COLOR] = "images\\MenuItems\\Pick_Figure_Color.jpg";


	PlayItemImages[PLAY_EXIT] = "images\\MenuItems\\Menu_Exit.jpg";

	//Draw menu item one image at a time
	for (int i = 0; i < PLAY_ITM_COUNT; i++)
		pWind->DrawImage(PlayItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar

	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight / 1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntDrawColor() const	//get current drawing color
{
	return UI.DrawColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() const	//get current filling color
{
	return UI.FillColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

int Output::getCrntPenWidth() const		//get current pen width
{
	return UI.PenWidth;
}

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);

}


void Output::Drawsq(Point P1, GfxInfo sqtGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor;
	else
		DrawingClr = sqtGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);

	drawstyle style;

	if (sqtGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(sqtGfxInfo.FillClr);
	}
	else
		style = FRAME;
	int x1, x2, y1, y2;
	int l = 50;
	x1 = P1.x - l;
	x2 = P1.x + l;
	y1 = P1.y - l;
	y2 = P1.y + l;
	pWind->DrawRectangle(x1, y1, x2, y2, style);
}
void Output::Drawtria(Point P1, Point P2, Point P3, GfxInfo sqtGfxInfo, bool selected)const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor;
	else
		DrawingClr = sqtGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (sqtGfxInfo.isFilled) {
		style = FILLED;
		pWind->SetBrush(sqtGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);
}

void Output::Drawhex(Point P1, GfxInfo sqtGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor;
	else
		DrawingClr = sqtGfxInfo.DrawClr;
	pWind->SetPen(DrawingClr, 1);

	drawstyle style;
	if (sqtGfxInfo.isFilled) {
		style = FILLED;
		pWind->SetBrush(sqtGfxInfo.FillClr);
	}
	else
		style = FRAME;
	int px[6], py[6];
	int l = 100;
	px[0] = P1.x - l;
	py[0] = P1.y;
	px[1] = P1.x - l / 2;
	py[1] = P1.y - (l / 2) * sqrt(3);
	px[2] = P1.x + l / 2;
	py[2] = P1.y - (l / 2) * sqrt(3);
	px[3] = P1.x + l;
	py[3] = P1.y;
	px[4] = P1.x + l / 2;
	py[4] = P1.y + (l / 2) * sqrt(3);
	px[5] = P1.x - l / 2;
	py[5] = P1.y + (l / 2) * sqrt(3);


	pWind->DrawPolygon(px, py, 6, style);
}

void Output::Drawcircle(Point P1, Point P2, GfxInfo sqtGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor;
	else
		DrawingClr = sqtGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (sqtGfxInfo.isFilled) {
		style = FILLED;
		pWind->SetBrush(sqtGfxInfo.FillClr);
	}
	else
		style = FRAME;
	double r = sqrt(pow((P1.x - P2.x), 2) + pow((P1.y - P2.y), 2));
	pWind->DrawCircle(P1.x, P1.y, r, style);
}

bool Output::IsFilled() {
	return UI.Filled;
}


//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}

