#pragma once


#include "IMWinclass.h"


LRESULT CALLBACK WndProc(HWND hWnd,
	UINT msg,
	WPARAM wParam,
	LPARAM lParam)
{

	/*IMWndProc *pIMWndProc = new IMWndProc(hWnd, msg, wParam, lParam);

	return pIMWndProc->IMWProc();
*/
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

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{

	IMWinClass *pIMWinClass = new IMWinClass(hInstance, hPrevInstance, lpCmdLine, nCmdShow);

	pIMWinClass->CreateWndWindow();

	pIMWinClass->ProcMsg();

}