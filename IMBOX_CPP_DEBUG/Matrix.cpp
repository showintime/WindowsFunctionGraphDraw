#include "Matrix.h"

Matrix::Matrix()
{
	matrix_rows = 0;
	matrix_columns = 0;
	element = NULL;
}

Matrix::Matrix(Matrix& B)
{
	this->matrix_rows = B.matrix_rows;
	this->matrix_columns = B.matrix_columns;
	element = new double[this->matrix_rows*this->matrix_columns];
	for (int i = 0; i < this->matrix_rows*this->matrix_columns; i++)
	{
		this->element[i] = B.element[i];
	}

}

Matrix::Matrix(int inrows, int incolumns, double* inelement)
{
	
	this->setelements(inrows, incolumns, inelement);


}



Matrix::~Matrix()
{
	delete this->element;
}


Matrix Matrix::operator=(Matrix B)
{
	if (this->matrix_rows == B.matrix_rows&&this->matrix_columns == B.matrix_columns)
	{

	}
	this->setelements(B.matrix_rows, B.matrix_columns, B.element);
	
	return *this;
}
Matrix Matrix::operator+(Matrix B)
{
	if (this->matrix_rows == B.matrix_rows&&this->matrix_columns == B.matrix_columns)
	{

	}
	Matrix *pM = new Matrix(this->matrix_rows, this->matrix_columns, this->element);
	for (int i = 0; i < pM->matrix_rows; i++)
	{
		for (int j = 0; j < pM->matrix_columns; j++)
		{
			pM->element[i*pM->matrix_columns + j] += B.element[i*pM->matrix_columns + j];
		}


	}


	return *pM;
}


Matrix Matrix::operator-(Matrix B)
{
	if (this->matrix_rows == B.matrix_rows&&this->matrix_columns == B.matrix_columns)
	{

	}
	Matrix *pM = new Matrix(this->matrix_rows, this->matrix_columns, this->element);
	for (int i = 0; i < pM->matrix_rows; i++)
	{
		for (int j = 0; j < pM->matrix_columns; j++)
		{
			pM->element[i*pM->matrix_columns + j] -= B.element[i*pM->matrix_columns + j];
		}


	}


	return *pM;
}





Matrix Matrix::operator-=(Matrix B)
{
	if (this->matrix_rows == B.matrix_rows&&this->matrix_columns == B.matrix_columns)
	{

	}

	for (int i = 0; i < this->matrix_rows; i++)
	{
		for (int j = 0; j < this->matrix_columns; j++)
		{
			this->element[i*this->matrix_columns + j] -= B.element[i*this->matrix_columns + j];
		}


	}

	return *this;
}

Matrix Matrix::operator+=(Matrix B)
{
	if (this->matrix_rows == B.matrix_rows&&this->matrix_columns == B.matrix_columns)
	{

	}

	for (int i = 0; i < this->matrix_rows; i++)
	{
		for (int j = 0; j < this->matrix_columns; j++)
		{
			this->element[i*this->matrix_columns + j] += B.element[i*this->matrix_columns + j];
		}


	}

	return *this;
}


void Matrix::setelements(int inrows, int incolumns, double* inelement)
{

	
	if (inrows > 0 && incolumns > 0)
	{
		/*    *******************     */
	}

	this->matrix_rows = inrows;
	this->matrix_columns = incolumns;



	element = new double[this->matrix_rows*this->matrix_columns];
	for (int i = 0; i < this->matrix_rows*this->matrix_columns; i++)
	{
		this->element[i] = inelement[i];
	}
}






