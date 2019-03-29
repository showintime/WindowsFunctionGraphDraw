#pragma once
#include "windows.h"

class IMWinClass
{

public:
	IMWinClass();
	IMWinClass(HINSTANCE, HINSTANCE, LPWSTR, int);
	IMWinClass(HINSTANCE, HINSTANCE, LPWSTR, int, WNDCLASSEX);
	LRESULT CALLBACK IMWndProc(HWND, UINT, WPARAM, LPARAM);
	~IMWinClass();
	bool IMRegister();






private:
	
	HINSTANCE hInstance;
	HINSTANCE hPrevInstance;
	LPWSTR lpCmdLine;
	int nCmdShow;

};