#ifndef _PROCESSORS_H
#define _PROCESSORS_H

#include "utilits.h"
#include "queue.h"
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <time.h>

#define CNT_PROC 3
const int LEAD_TIME[CNT_PROC]={
	3500, // ����� ���������� ������ ������� ���������� � ��������
	6000, // ����� ���������� ������ ������� ���������� � ��������
	2500 // ����� ���������� ������ �������� ���������� � ��������
};
// ������� ������� ���������� ����� 0 ��� �������� ������
int processor_1(Q *Queue, int *timer, int *iteration, int time_to_complete /*��������� ��� �������*/);

// ������� ������� ���������� ����� 0 ��� �������� ������
int processor_2(Q *Queue, int *timer, int *iteration, int time_to_complete/*��������� ��� �������*/);

// ������� ������� ���������� ����� 0 ��� �������� ������
int processor_3(Q *Queue, int *timer, int *iteration, int time_to_complete /*��������� ��� �������*/);

// �������������� ����� (����� 0 � ������ ������ �� ���������(��� ������� ESC))
int distributer(Q Queue[], char c);

// ���������� ��� �����������
int preparation(Q Queue[], int timer[], int iteration[]);

// ���������� ������ - ������� ������
void the_end(Q Queue[]);

// ������� ������
int process();

#endif // _PROCESSORS_H
