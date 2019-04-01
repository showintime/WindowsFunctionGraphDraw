
/*

WINDOWS MESSAGE SOLVING



*/



#pragma once
#include "windows.h"
#include "Coordinate_2D.h"


LRESULT CALLBACK WndProc(HWND hWnd,
	UINT msg,
	WPARAM wParam,
	LPARAM lParam);

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