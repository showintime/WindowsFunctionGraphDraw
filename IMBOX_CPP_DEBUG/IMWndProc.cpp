#include "IMWndProc.h"


IMWndProc::~IMWndProc()
{

}

LRESULT IMWndProc::IMWProc()
{
	return DefWindowProc(this->hWnd,this->msg,this->wParam,this->lParam);
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

