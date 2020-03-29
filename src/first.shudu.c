#include<stdio.h> 
int a[10][10];
int flag = 0;
//��ӡ���� 
void output()
{
	for (int i = 0; i < 9; i++, printf("\n"))
	{
		for (int j = 0; j < 9; j++)
		{
			printf("%d ", a[i][j]);
		}
	}
}

int check(int row, int line, int number)
{
	const int prow = row / 3;
	const int pdline = line / 3;
	//�ж����� 
	for (int i = 0; i < 9; i++)
	{
		if (a[row][i] == number || a[i][line] == number)
		{
			return 0;
		}
	}

	//�ж�С�Ź���
    
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (a[prow * 3 + i][pdline * 3 + j] == number)
			{
				return 0;
			}
		}
	}
	return 1;
}

int dfs(int m, int n)
{
	if (m == 8 && n == 9)//����ȫ�������� 
	{
		printf("\n");
		output();
		flag = 1;
	}
	//������β������ 
	if (n == 9)
	{
		m++;
		n = 0;
	}
	//�ж�m��m��Ϊ0����ֵ 
	if (a[m][n] == 0)
	{
		for (int k = 1; k < 10; k++)//�����ж�m��m������1-9�����Ƿ��������� 
		{
			if (check(m, n, k) == 1)
			{
				a[m][n] = k;
				dfs(m, n + 1);

				a[m][n] = 0;//1-9�����������������������Ϊ0��������һ������ 
			}

		}

	}
	else {
		dfs(m, n + 1);
	}
	return 0;
}


int main()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			scanf_s("%d", &a[i][j]);
		}
	}
	dfs(0, 0);
	if (flag == 1)
		printf("Success!\n");
	else
		printf("No solution!\n");
	return 0;
}
