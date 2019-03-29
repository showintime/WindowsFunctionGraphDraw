#include "IMWinClass.h"

IMWinClass::IMWinClass()
{
	
}

IMWinClass::IMWinClass(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPWSTR lpCmdLine,
	int nCmdShow)
{
	WNDCLASSEX wcex = { 0 };
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.hInstance = hInstance;
	wcex.lpszClassName = L"IMWINDOW_DEFAULT";

}

IMWinClass::IMWinClass(HINSTANCE, HINSTANCE, LPWSTR, int, WNDCLASSEX)
{
	this->hInstance = hInstance;
	this->hPrevInstance = hPrevInstance;
	this->lpCmdLine = lpCmdLine;
	this->nCmdShow = nCmdShow;
}

IMWinClass::~IMWinClass()
{

}

bool IMWinClass::IMRegister()
{

	return false;
}
