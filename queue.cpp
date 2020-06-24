#include "queue.h"

// �������� �������� �������
q_elem* create_element(char c)
{
	q_elem *New;
	if( !(New = (q_elem*)malloc(sizeof(q_elem))) )
		return (q_elem*)Err(RAM_IS_OVER);
	New->c = c;
	New->next = NULL;
	return New;
}

// ���������� � �������
int Q_push(Q *Queue, q_elem *element)
{
	if(!Queue || !element)
		return 0;
	if(Queue->quantity++==0)
		Queue->head = Queue->tail = element;
	else
	{
		element->next = Queue->head;
		Queue->head = element;
	}
	return 1;
}

// �������� �� ������� (� ������������� ������)
q_elem Q_pop(Q *Queue)
{
	q_elem element={0,0}, *pointer = NULL;
	if(!Queue)
		return element;
	if(!Queue->head || !Queue->quantity)
		return element;
	element = *(Queue->tail);
	pointer = Queue->tail;
	if(--Queue->quantity==0)// ������� �����
	{
		free(pointer);
		Queue->head = Queue->tail = NULL;
	}
	else// ���� ���� �� 1 �������
	{
		// ���������� ��������� �� �������������
		for(pointer = Queue->head; pointer->next && pointer->next!=Queue->tail;)
			pointer = pointer->next;
		Queue->tail = pointer;// ��������� �����
		element = *pointer;// ��������� ������������ ��������
		free(pointer->next);
		Queue->tail->next = NULL;
	}
	return element;
}

// �������� ���� ��������� �� �������
void Q_clear(Q *Queue)
{
	if(!Queue->head)
		return;
	q_elem *cur = Queue->head;// ���������� �������
	Queue->head = Queue->head->next;// �������� ������
	Q_clear(Queue); // ������� ��������� ��������
	free(cur);
	Queue->head = Queue->tail = NULL;// ��������� ������ ����
	Queue->quantity = 0;
}
