#include "IMWinClass.h"



IMWinClass::IMWinClass(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPWSTR lpCmdLine,
	int nCmdShow)
{
	WNDCLASSEX wcex = { 0 };
	
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.hInstance = hInstance;
	wcex.lpszClassName = L"IMWINDOW_DEFAULT";
	wcex.lpfnWndProc = WndProc;

	this->IMRegister(hInstance, hPrevInstance, lpCmdLine, nCmdShow,wcex);
	

}

IMWinClass::IMWinClass(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPWSTR lpCmdLine,
	int nCmdShow,
	WNDCLASSEX wcex)
{
	this->IMRegister(hInstance, hPrevInstance, lpCmdLine, nCmdShow,wcex);
}

//LRESULT IMWinClass::ProcMsg(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
//{
//	return DefWindowProc(hWnd, msg, wParam, lParam);
//}

IMWinClass::~IMWinClass()
{

}

void IMWinClass::IMRegister(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPWSTR lpCmdLine,
	int nCmdShow,
	WNDCLASSEX wcex)
{
	this->hInstance = hInstance;
	this->hPrevInstance = hPrevInstance;
	this->lpCmdLine = lpCmdLine;
	this->nCmdShow = nCmdShow;

	RegisterClassEx(&wcex);
	
}

void IMWinClass::CreateWndWindow()
{
	this->hWnd = CreateWindow(L"IMWINDOW_DEFAULT",L"IM",0,100,100,800,600,0,0,this->hInstance,0);
	MoveWindow(this->hWnd, 100, 100, 800, 600, true);
	ShowWindow(this->hWnd, this->nCmdShow);
	UpdateWindow(this->hWnd);

}

void IMWinClass::ProcMsg()
{
	MSG msg = { 0 };
	while (GetMessage(&msg, 0, 0, 0) != WM_QUIT)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}
