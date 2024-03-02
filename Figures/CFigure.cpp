#include "CFigure.h"
#include <string>
CFigure::CFigure()
{
	Selected = false; //Default is not selected  
}

CFigure::CFigure(GfxInfo FigureGfxInfo)
{
	FigGfxInfo = FigureGfxInfo;	    //Default status is non-filled.
	Selected = false;              //Default is not selected  
	FigGfxInfo.isFilled = UI.Filled;
	FigureColor = UI.DrawColor;
}

void CFigure::SetSelected(bool s)
{
	Selected = s;
	if (Selected)
	{
		FigGfxInfo.DrawClr = UI.HighlightColor;
	}
	else
		FigGfxInfo.DrawClr = FigureColor;
}

bool CFigure::IsSelected()
{
	return Selected;
}

void CFigure::setID(int id)
{
	ID = id;
}

void CFigure::ChngDrawClr(color Dclr)
{
	FigGfxInfo.DrawClr = Dclr;
	FigureColor = Dclr;
	UI.DrawColor = Dclr;
}

void CFigure::ChngFillClr(color Fclr, bool Fill)
{
	UI.Filled = Fill;
	FigGfxInfo.isFilled = UI.Filled;
	FigGfxInfo.FillClr = Fclr;
}

int CFigure::GetId()
{
	return ID;
}

color CFigure::GetFillingColor() const
{
	if (FigGfxInfo.isFilled)
		return FigGfxInfo.FillClr;
	else
		return WHITE;
}

bool CFigure::IsFilled() const
{
	return FigGfxInfo.isFilled;
}







