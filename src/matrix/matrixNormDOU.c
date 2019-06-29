#include <stdio.h>
#include<stdlib.h>
#include<math.h>
double matrixNormDOU(double **mat, int row, int column)
{
	double s = 0.0;
	for ( int i = 0; i < row;  i++)
	{
		for (int j = 0; j < column; j++)
		{
			s = s+mat[i][j]*mat[i][j];
		}
	}
	return (sqrt(s));

}