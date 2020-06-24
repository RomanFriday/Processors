#include "utilits.h"


// ������� ��������� �� ���� ������. ������������ ������ 0
int Err(int type)
{
	switch(type)
	{
	case RAM_IS_OVER:
		printf("\n RAM is over\n");
		break;
	case DIVIDE_BY_ZERO:
		printf("\n Forbidden to divide by zero.\n");
		break;
	default: break;
	};
	return NULL;
}

// ��������� ����������� ������� �������� n
void null_arr_1d(int *arr, int n)
{
	for(int i=0; i<n; i++)
		arr[i] = 0;
	return;
}

// ����� ���������� ������
int complited(int performed, int total, int scale_lenght)
{
	if(total==0)
		return Err(DIVIDE_BY_ZERO);
	for(int i=0; i<scale_lenght; i++)
		if(i<performed*scale_lenght/total)
			printf("%c",178); // ���������
		else
			printf("%c", 176); // �� ���������
	if(performed>=total)
		return 1;
	return 0;
}

