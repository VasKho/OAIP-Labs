//---------------------------------------------------------------------------
#include <iostream.h>
#include <conio.h>
#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

struct line
{
    int data;
    line *prev, *cont;
}*top, *end;

void line_add(line**, line**, int, char);
void line_print(line*, line*, char);
void average(line **);

#pragma argsused
int main(int argc, char* argv[])
{
        cout << "Vvedite razmer ocheredi: ";
        int sz, i = 0, zp = 1;
        cin >> sz;
        cout << "Zapis (1 - Nachalo, 2 - Koniec): ";
        cin >> zp;
        char z;
        switch (zp)
        {
            case 1: z = 'b'; break;
            case 2: z = 'e'; break;
        }
        randomize();
        while(i < sz)
        {
            line_add(&top, &end, random(20)-10, z);
            i++;
        }
        cout << "Pokazat (1 - Nachalo, 2 - Koniec): ";
        cin >> zp;
        switch (zp)
        {
            case 1: z = 'b'; break;
            case 2: z = 'e'; break;
        }
        line_print(top, end, z);
        cout << "Vypolnenie zadaniya:" << endl;
        average(&top);
        line_print(top, end, 'b');
        system("pause");
        return 0;
}
//---------------------------------------------------------------------------


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


void line_print(line* top, line* end, char pos)
{
    line *comp = new line;
    if (pos == 'b')
    {
        comp = top;
        while (comp)
        {
            printf("% 5d", comp->data);
            comp = comp->cont;
        }
    }
    else
    {
        comp = end;
        while(comp)
        {
            printf("% 5d", comp->data);
            comp = comp->prev;
        }
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

