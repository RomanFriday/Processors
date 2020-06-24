#ifndef _FUNCTIONS_WITH_QUEUE_H
#define _FUNCTIONS_WITH_QUEUE_H

#include "utilits.h"
#include <stdlib.h>

typedef struct my_struct1
{
	char c;
	struct my_struct1 *next;
} q_elem;
typedef struct my_struct2
{
	int quantity;
	q_elem *head, *tail;
} Q;

// �������� �������� �������
q_elem* create_element(char c);

// ���������� � �������
int Q_push(Q *Queue, q_elem *element);

// �������� �� ������� (� ������������� ������)
q_elem Q_pop(Q *Queue);

// �������� ���� ��������� �� �������
void Q_clear(Q *Queue);

#endif //_FUNCTIONS_WITH_QUEUE_H