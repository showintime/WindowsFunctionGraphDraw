#pragma once


#include "IMWinclass.h"


LRESULT CALLBACK WndProc(HWND hWnd,
	UINT msg,
	WPARAM wParam,
	LPARAM lParam);


int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{

	IMWinClass *pIMWinClass = new IMWinClass(hInstance, hPrevInstance, lpCmdLine, nCmdShow);

	pIMWinClass->CreateWndWindow();

	pIMWinClass->ProcMsg();

}