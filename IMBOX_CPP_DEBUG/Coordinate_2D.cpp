#include "Coordinate_2D.h"

Coordinate::Coordinate()
{
}

Coordinate::Coordinate(HWND hWnd)
{
	this->CoordinatePosition = { 100,100,700,500 };
	this->CoordinateXLabel = L"thisisX";
	this->CoordinateYLabel = L"thisisY";
	this->hWnd = hWnd;
	this->CoorfinateDc = GetDC(this->hWnd);

	
	
}

Coordinate::~Coordinate()
{
}

void Coordinate::DrawCoordinate()
{


	SetBkMode(this->CoorfinateDc, TRANSPARENT);
	HPEN impen = CreatePen(PS_SOLID, 5, RGB(77, 66, 1));
	SelectObject(this->CoorfinateDc, impen);


	MoveToEx(this->CoorfinateDc, this->CoordinatePosition.left, this->CoordinatePosition.bottom, NULL);
	LineTo(this->CoorfinateDc, this->CoordinatePosition.right, this->CoordinatePosition.bottom);



	MoveToEx(this->CoorfinateDc, this->CoordinatePosition.left, this->CoordinatePosition.bottom, NULL);
	LineTo(this->CoorfinateDc, this->CoordinatePosition.left, this->CoordinatePosition.top);

	RECT xRect = {
		this->CoordinatePosition.right,
		this->CoordinatePosition.bottom,
		this->CoordinatePosition.right+20,
		this->CoordinatePosition.bottom+20
	},
		yRect = {
		this->CoordinatePosition.left-20,
		this->CoordinatePosition.top-20,		
		this->CoordinatePosition.left,
		this->CoordinatePosition.top,

	};
	DrawText(this->CoorfinateDc, this->CoordinateXLabel, sizeof(this->CoordinateXLabel), &xRect, DT_CENTER);
	DrawText(this->CoorfinateDc, this->CoordinateYLabel, sizeof(this->CoordinateYLabel), &yRect, DT_CENTER);


	IMPOINT imp[M];
	for (int i = 0; i < M; i++)
	{
		imp[i].x = i;
		imp[i].y = imp[i].x*imp[i].x;
	}
	double* it = new double[2 * M];

	for (int i = 0; i < M; i++)
	{
		it[i] = imp[i].x;
		it[M + i] = imp[i].y;
	}
	
	Matrix *pM = new Matrix(2, M, it);


	this->xmax = this->xmin = it[0];
	this->ymax = this->ymin = it[M];


	for (int i = 0; i < M; i++)
	{
		if (this->xmax < it[i])
		{
			this->xmax = it[i];
		}
		if (this->xmin > it[i])
		{
			this->xmin = it[i];
		}
		if (this->ymax < it[M+i])
		{
			this->ymax = it[M+i];
		}
		if (this->ymin > it[M+i])
		{
			this->ymin = it[M+i];
		}		
	}

	this->CoorXLength = this->xmax - this->xmin;
	this->CoorYLength = this->ymax - this->ymin;

	this->PixelPerX = (this->CoordinatePosition.right - this->CoordinatePosition.left)*1.0 / this->CoorXLength;
	this->PixelPerY = (this->CoordinatePosition.bottom - this->CoordinatePosition.top)*1.0 / this->CoorYLength;



	POINT simp[M];


	for (int i = 0; i < M; i++)
	{
		simp[i].x = this->CoordinatePosition.left + this->PixelPerX * (it[i] - this->xmin);
		simp[i].y = this->CoordinatePosition.top + this->PixelPerY*(this->ymax - it[M + i]);
	
	
	}

	for (int i = 0; i < M; i++)
	{
		SetPixel(this->CoorfinateDc, simp[i].x, simp[i].y, RGB(rand() % 255, rand() % 255, rand() % 255));
	}










	DeleteObject(impen);
}

