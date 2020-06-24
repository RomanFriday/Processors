#ifndef _UTILITS_H
#define _UTILITS_H

#include <stdio.h>
#include <Windows.h>

// коды ошибок
#define RAM_IS_OVER 0
#define DIVIDE_BY_ZERO 1

// коды ASCII
#define ESC 27

// ¬ывести сообщение по коду ошибки. ¬озвращаетс€ всегда 0
int Err(int type);

// обнуление одномерного массива размером n
void null_arr_1d(int *arr, int n);

// шкала выполнени€ задачи (по времени)
int complited(int performed, int total, int scale_lenght);

#endif // _UTILITS_H