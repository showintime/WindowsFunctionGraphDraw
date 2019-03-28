#define ConsoleVersion

#ifdef ConsoleVersion

#include "iostream"
using namespace std;



#include "windows.h"

#endif


#include "IMWin.h"
#include "Coordinate.h"
#include "Matrix.h"



int main()
{
	double a[2][2] = { 1,2,3,4 };
	double b[4] = { 5,6,7,8 };
	Matrix* pA=new Matrix(2, 2, &a[0][0]);

	Matrix* pB = new Matrix();
	
	*(pB) = *(pA);


	system("color f0");
	pA->printM();
	pB->printM();

	Matrix *pApB = &(*pA += *pB);
	

	






	return 0;                                                                                                          	return 0;
}