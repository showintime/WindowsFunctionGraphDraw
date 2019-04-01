

/*


WINDOWS STYLE

*/



#pragma once
#include "windows.h"
#include "Coordinate_2D.h"

LRESULT CALLBACK WndProc(HWND hWnd,
	UINT msg,
	WPARAM wParam,
	LPARAM lParam);


class IMWinClass
{

public:
	
	IMWinClass(HINSTANCE, HINSTANCE, LPWSTR, int);
	IMWinClass(HINSTANCE, HINSTANCE, LPWSTR, int, WNDCLASSEX);
	
	~IMWinClass();
	void IMRegister(HINSTANCE, HINSTANCE, LPWSTR, int, WNDCLASSEX);

	void CreateWndWindow();

	void ProcMsg();



private:
	
	HINSTANCE hInstance;
	HINSTANCE hPrevInstance;
	LPWSTR lpCmdLine;
	int nCmdShow;

	HWND hWnd;
	

};