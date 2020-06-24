#include "processors.h"

// ������� ������� ���������� ����� 0 ��� �������� ������
int processor_1(Q *Queue, int *timer, int *iteration, int time_to_complete /*��������� ��� �������*/)
{
	printf("\n");
	if(!Queue->quantity)
	{
		*timer = clock();
		complited(1, 1, 50);
		printf(" Proc1 is free");
		return 1;
	}
	if( !complited(clock()-*timer, time_to_complete, 50) )
	{
		//�����-�� ��������� ������
		//switch(iteration++)
		//{
		//
		//case 0:
		//	func1_1();
		//	return 1;
		//case 1:
		//	if( !func1_2() )
		//		return 0;
		//	return 1;
		//default: break;// ��� ������� ���������
		//}
		return 1;
	}
	printf(" complited");
	iteration = 0;
	Q_pop(Queue);
	*timer = clock();
	return 1;
}

// ������� ������� ���������� ����� 0 ��� �������� ������
int processor_2(Q *Queue, int *timer, int *iteration, int time_to_complete /*��������� ��� �������*/)
{
	printf("\n");
	if(!Queue->quantity)
	{
		*timer = clock();
		complited(1, 1, 50);
		printf(" Proc2 is free");
		return 1;
	}
	if( !complited(clock()-*timer, time_to_complete, 50) )
	{
		//�����-�� ��������� ������
		//switch(iteration++)
		//{
		//
		//case 0:
		//	func2_1();
		//	return 1;
		//case 1:
		//	func2_2();
		//	return 1;
		//default: break;// ��� ������� ���������
		//}
		return 1;
	}
	printf(" complited");
	iteration = 0;
	Q_pop(Queue);
	*timer = clock();
	return 1;
}

// ������� ������� ���������� ����� 0 ��� �������� ������
int processor_3(Q *Queue, int *timer, int *iteration, int time_to_complete /*��������� ��� �������*/)
{
	printf("\n");
	if(!Queue->quantity)
	{
		*timer = clock();
		complited(1, 1, 50);
		printf(" Proc3 is free");
		return 1;
	}
	if( !complited(clock()-*timer, time_to_complete, 50) )
	{
		//�����-�� ��������� ������
		//switch(iteration++)
		//{
		//
		//case 0:
		//	func3_1();
		//	return 1;
		//case 1:
		//	func3_2();
		//	return 1;
		//default: break;// ��� ������� ���������
		//}
		return 1;
	}
	printf(" complited");
	iteration = 0;
	Q_pop(Queue);
	*timer = clock();
	return 1;
}

// �������������� ����� (����� 0 � ������ ������ �� ���������(��� ������� ESC))
int distributer(Q Queue[], char c)
{
	if(c==ESC)// ���������� ���������
		return 0;
	// ���������� � ������� ������ ������� ����������
	// ������ ��������� ������������ �����
	if(c>='0'&&c<='9')
		if( !Q_push(Queue+0, create_element(c)) )
			return 0;
		else
			return 1;
	// ���������� � ������� ������ ������� ����������
	// ������ ��������� ������������ ��������� �����
	if(c>='A'&&c<='Z' || c>='a'&&c<='z')
		if( !Q_push(Queue+1, create_element(c)) )
			return 0;
		else
			return 1;
	// ���������� � ������� ������ �������� ����������
	// ������ ��������� ������������ ��������� �������
	if( !Q_push(Queue+2, create_element(c)) )
		return 0;
	return 1;
}

// ���������� ��� �����������
int preparation(Q Queue[], int timer[], int iteration[])
{
	for(int i=0; i<CNT_PROC; i++)
		Queue[i].quantity = 0;
	for(int i=0; i<CNT_PROC; i++)
		Queue[i].head = Queue[i].tail = NULL;
	int now_t = clock();
	for(int i=0; i<CNT_PROC; i++)
		timer[i] = now_t;
	null_arr_1d(iteration, CNT_PROC);
	return 1;
}

// ���������� ������ - ������� ������
void the_end(Q Queue[])
{
	for(int i=0; i<CNT_PROC; i++)
		Q_clear(Queue+i);
}

// ������� ������
int process()
{
	char c = 0;
	Q Queue[CNT_PROC];// ������ �������� ��� ������� �� �����������
	int timer[CNT_PROC],// ������ �������� ��� ����������� (�� �������������)
		iteration[CNT_PROC],// ����� �� ����� ������� ����������� � ������ �����������
		now_time = clock(); // �������� ��� ����������
	preparation(Queue, timer, iteration);
	while(1)
	{
		if(_kbhit())
			if(!distributer(Queue, c = _getch()))
				break;
		if(clock()-now_time > 200)// ���������� ������ 200 ��������
		{
			now_time = clock();
			system("cls");
			printf(" Input characters-command to processors:\n\n");
			for(int i=0;i<CNT_PROC; i++)
			{
				for(q_elem *cur=Queue[i].head; cur; cur=cur->next )
					printf("%c", cur->c);
				printf("\n");
			}
			// ���� ������� �����������
			// ------------------------------------------------------------
			// ������� ��-����� ����� ���� � ��� ������, ���� ��� ���������
			// ������� ����������� ����������� ����
			// ------------------------------------------------------------
			if( !processor_1(Queue+0, timer+0, iteration+0, LEAD_TIME[0]) /*��������� ��� ������� 1 ����*/)
				return 0;
			if( !processor_2(Queue+1, timer+1, iteration+1, LEAD_TIME[1]) /*��������� ��� ������� 2 ����*/)
				return 0;
			if( !processor_3(Queue+2, timer+2, iteration+2, LEAD_TIME[2]) /*��������� ��� ������� 3 ����*/)
				return 0;
		}
	}
	the_end(Queue);
	return 1;
}