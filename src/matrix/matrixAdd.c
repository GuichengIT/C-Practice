#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int **matrixINT(int row, int column);
double **matrixDouble(int row, int column);
//////////////////��ά������ӣ�Double���ͣ�/////////////////////
double** matrixAddDou(double **mat1, double **mat2, int row, int column)
{
	double **mat = matrixDouble(row, column);
	for (int i = 0; i < row; i++)
	for (int j = 0; j < column; j++)
	{
		mat[i][j] = mat1[i][j] + mat2[i][j];
	}
	return mat;

}


//////////////////��ά������ӣ�Int���ͣ�/////////////////////
int** matrixAddInt(int **mat1, int **mat2, int row, int column)
{
	int **mat = matrixINT(row, column);
	for (int i = 0; i < row; i++)
	for (int j = 0; j < column; j++)
	{
		mat[i][j] = mat1[i][j] + mat2[i][j];
	}
	return mat;
}