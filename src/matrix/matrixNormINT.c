#include<stdlib.h>
#include<stdio.h>
#include<math.h>
int matrixNormINT(int **mat,int row,int column)
{
	int s = 0;
	for (int i = 0; i < row;i++)
	    for (int j = 0;  j < column;  j++)
	{
			s = s + mat[i][j]*mat[i][j];	
	}
		return (sqrt(s));
}