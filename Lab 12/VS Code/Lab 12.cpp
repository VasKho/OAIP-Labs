#include <iostream>
#include <time.h>

using namespace std;


struct line
{
    int data;
    line *prev, *cont;
}*top, *e;

void line_add(line**, line**, int, char);
void line_print(line*, line*);
void average(line **);

#pragma argsused
int main(int argc, char* argv[])
{
        cout << "Введите размер очереди: ";
        int sz, i = 0, zp = 1;
        cin >> sz;
        cout << "Запись (1 - Начало, 2 - Конец): ";
        cin >> zp;
        char z;
        switch (zp)
        {
            case 1: z = 'b'; break;
            case 2: z = 'e'; break;
        }
        srand(time(NULL));
        while(i < sz)
        {
            line_add(&top, &e, (rand())%20-10, z);
            i++;
        }
        line_print(top, e);
        cout << "Выполнение задания:" << endl;
        average(&top);
        line_print(top, e);
        return 0;
}


void line_add(line **top, line **end, int num, char pos)
{
    line *comp = new line;
    if (*top == NULL && *end == NULL)
    {
        comp->cont = comp->prev = NULL;
        *top = *end = comp;
    }
    else
    {
        if (pos == 'b')
        {
            comp->data = num;
            comp->prev = NULL;
            comp->cont = *top;
            (*top)->prev = comp;
            (*top) = comp;
        }
        else
        {
            comp->data = num;
            comp->cont = NULL;
            comp->prev = *end;
            (*end)->cont = comp;
            *end = comp;
        }
    }
}


void line_print(line* top, line* end)
{
    line *comp = new line;
        comp = top;
        while (comp)
        {
            printf("% 5d", comp->data);
            comp = comp->cont;
        }
    cout << endl;
        comp = end;
        while(comp)
        {
            printf("% 5d", comp->data);
            comp = comp->prev;
        }
    cout << endl;
}

void average(line **top)
{
    line *comp = new line;
    int avg = 0;
    int k = 0;
    comp = *top;
    while(comp)
    {
        avg += comp->data;
        k++;
        comp = comp->cont;
    }
    avg /= k;
    (*top)->data = avg;
}