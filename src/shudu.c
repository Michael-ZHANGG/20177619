#include<stdio.h> 
int a[9][9];
int flag = 0;
//打印函数 
void output()
{
	int i, j;
	FILE* fp2;
	fp2 = fopen("output.txt", "w");
	if (fp2 == NULL)
	{
		printf("file2 is error.");
	}
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			fprintf(fp2, "%d ", a[i][j]);
		}
		fprintf(fp2, "\n");
	}
	fclose(fp2);
}

int check(int row, int line, int number)
{
	//判断行列 
	for (int i = 0; i < 9; i++)
	{
		if (a[row][i] == number || a[i][line] == number)
		{
			return 0;
		}
	}

	//判断小九宫格
	int pdrow = row / 3, pdline = line / 3;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (a[pdrow * 3 + i][pdline * 3 + j] == number)
			{
				return 0;
			}
		}
	}
	return 1;
}

int dfs(int m, int n)
{
	if (m == 8 && n == 9)//遍历全数组后，输出 
	{
		printf("\n");
		output();
		flag = 1;
	}
	//到达列尾，换行 
	if (n == 9)
	{
		m++;
		n = 0;
	}
	//判断m行m列为0，赋值 
	if (a[m][n] == 0)
	{
		for (int k = 1; k < 10; k++)//依次判断m行m列填入1-9，看是否满足条件 
		{
			if (check(m, n, k) == 1)
			{
				a[m][n] = k;
				dfs(m, n + 1);

				a[m][n] = 0;//1-9都不满足条件，将这个点标记为0，返回上一个坐标 
			}

		}

	}
	else {
		dfs(m, n + 1);
	}
	return 0;
}


/* int main()
 {
	int i,j;
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			scanf("%d",&a[i][j]);
		 }
	 }
	 dfs(0,0);
	if (flag == 1)
	printf("Success!\n");
	else
	printf("No solution!\n");
	return 0;
 }*/
int main()
{
	FILE* fp1;
	int j, i;
	fp1 = fopen("input.txt", "r");
	if (fp1 == NULL)//打开失败
	{
		printf("file1 is error.");
		return 1;
	}
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			fscanf(fp1, "%d", &a[i][j]);
		}
	}
	fclose(fp1);
	dfs(0, 0);
	if (flag == 1)
		printf("Success!\n");
	else
		printf("No solution!\n");
	return 0;
}