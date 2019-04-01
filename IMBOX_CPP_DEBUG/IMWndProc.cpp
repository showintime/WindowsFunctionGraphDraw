#include "IMWndProc.h"
LRESULT CALLBACK WndProc(HWND hWnd,
	UINT msg,
	WPARAM wParam,
	LPARAM lParam)
{

	IMWndProc *pIMWndProc = new IMWndProc(hWnd, msg, wParam, lParam);

	return pIMWndProc->IMWProc();

	/*switch (msg)
	{
	case WM_PAINT:

		break;
	case WM_QUIT:
		PostQuitMessage(0);
		break;
	default:
		break;
	}*/

	return DefWindowProc(hWnd, msg, wParam, lParam);
}

IMWndProc::~IMWndProc()
{

}

LRESULT IMWndProc::IMWProc()
{
	Coordinate *pCoordinate=new Coordinate(this->hWnd);
	
	switch (this->msg)
	{
	case WM_PAINT:
		pCoordinate->DrawCoordinate();
		break;
	case WM_KEYDOWN:
		if (this->wParam == VK_ESCAPE)
		{
			DestroyWindow(this->hWnd);
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(this->hWnd, this->msg, this->wParam, this->lParam);
	}
	return 0;
}



IMWndProc::IMWndProc(HWND hWnd,
	UINT msg,
	WPARAM wParam,
	LPARAM lParam)
{
	this->hWnd = hWnd;
	this->msg = msg;
	this->wParam = wParam;
	this->lParam = lParam;

}

