#include<stdio.h>
#define N 10
int getA(int arcs[N][N], int n)//����һ��չ������|A|
{
	if (n == 1)
	{
		return arcs[0][0];
	}
	int ans = 0;
	int temp[N][N];
	int i, j, k;
	for (i = 0; i<n; i++)
	{
		for (j = 0; j<n - 1; j++)
		{
			for (k = 0; k<n - 1; k++)
			{
				temp[j][k] = arcs[j + 1][(k >= i) ? k + 1 : k];

			}
		}
		int t = getA(temp, n - 1);
		if (i % 2 == 0)
		{
			ans += arcs[0][i] * t;
		}
		else
		{
			ans -= arcs[0][i] * t;
		}
	}
	return ans;
}
void getAStart(int arcs[N][N], int n, int ans[N][N])//����ÿһ��ÿһ�е�ÿ��Ԫ������Ӧ������ʽ�����A*
{
	if (n == 1)
	{
		ans[0][0] = 1;
		return;
	}
	int i, j, k, t;
	int temp[N][N];
	for (i = 0; i<n; i++)
	{
		for (j = 0; j<n; j++)
		{
			for (k = 0; k<n - 1; k++)
			{
				for (t = 0; t<n - 1; t++)
				{
					temp[k][t] = arcs[k >= i ? k + 1 : k][t >= j ? t + 1 : t];
				}
			}


			ans[j][i] = getA(temp, n - 1);
			if ((i + j) % 2 == 1)
			{
				ans[j][i] = -ans[j][i];
			}
		}
	}
}

//int main()
//{
//	int arcs[N][N];
//	int astar[N][N];
//	int i, j;
//	int n;
//	while (scanf_s("%d", &n) != EOF && n)
//	{
//		for (i = 0; i<n; i++)
//		{
//			for (j = 0; j<n; j++)
//			{
//				scanf_s("%d", &arcs[i][j]);
//			}
//		}
//
//		int a = getA(arcs, n);
//		if (a == 0)
//		{
//			printf("can not transform!\n");
//		}
//		else
//		{
//			getAStart(arcs, n, astar);
//			for (i = 0; i<n; i++)
//			{
//				for (j = 0; j<n; j++)
//				{
//					printf("%.3lf ", (double)astar[i][j] / a);
//				}
//				printf("\n");
//			}
//		}
//		printf("\n");
//
//	}
//
//
//	return 0;
//}