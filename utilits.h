#ifndef _UTILITS_H
#define _UTILITS_H

#include <stdio.h>
#include <Windows.h>

// ���� ������
#define RAM_IS_OVER 0
#define DIVIDE_BY_ZERO 1

// ���� ASCII
#define ESC 27

// ������� ��������� �� ���� ������. ������������ ������ 0
int Err(int type);

// ��������� ����������� ������� �������� n
void null_arr_1d(int *arr, int n);

// ����� ���������� ������ (�� �������)
int complited(int performed, int total, int scale_lenght);

#endif // _UTILITS_H