
/*

Coordinate_2D && Axis

*/

#pragma once
#include "windows.h"
#include "Matrix.h"

#define M 1000

void imbox();

typedef struct tagIMPOINT
{
	double x;
	double y;
}IMPOINT;

class Coordinate
{
private:
	const wchar_t* CoordinateXLabel;
	const wchar_t* CoordinateYLabel;

	HWND hWnd;

	HDC CoorfinateDc;
	RECT CoordinatePosition;

	
	double xmax;
	double xmin;
	double ymax;
	double ymin;


	double CoorXLength;
	double CoorYLength;

	double PixelPerX;
	double PixelPerY;

public:

	Coordinate();
	Coordinate(HWND);
	~Coordinate();

	void DrawCoordinate();

};
