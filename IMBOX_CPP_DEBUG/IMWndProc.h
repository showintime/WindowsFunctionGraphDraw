#pragma once
#include "windows.h"

class IMWndProc
{
private:
	HWND hWnd;
	UINT msg;
	WPARAM wParam;
	LPARAM lParam;

public:

	IMWndProc(HWND, UINT, WPARAM, LPARAM);
	
	~IMWndProc();

	LRESULT CALLBACK IMWProc();

};