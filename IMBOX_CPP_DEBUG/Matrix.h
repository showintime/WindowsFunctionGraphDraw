#pragma once
#include<windows.h>




class Matrix
{


public:

	Matrix();
	Matrix(Matrix&);
	Matrix(int, int, double*);
	~Matrix();
	


	
	
	Matrix operator=(Matrix);
	Matrix operator+(Matrix);
	Matrix operator-(Matrix);
	Matrix operator+=(Matrix);
	Matrix operator-=(Matrix);

	
	void setelements(int, int, double*);
	


private:
	int matrix_rows;
	int matrix_columns;

	double* element;



};