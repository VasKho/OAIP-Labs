#include <iostream>
#include <time.h>

using namespace std;

struct Stack
{
    int dat;
    Stack *cont;
};

Stack* stack_push(Stack*, int);
void stack_print(Stack*);
float average(Stack*);
Stack* stack_sort_p(Stack*);
Stack* stack_del(Stack*);
Stack* stack_sort_val(Stack*);

int main()
{
    Stack *top = NULL;
    int sch;
    cout << "Kolichestvo chisel: ";
    int num;
    cin >> num;
    srand(time(NULL));
    while(num)
    {
        top = stack_push(top, (rand()%20)-10);
        num--;
    }
    while(true)
    {
        cout << "1 - Pokazat\n" << "2 - Srednee znachenie\n" << "3 - Sort po ukazat\n" << "4 - Sort po znach\n" << "5 - Vyhod" << endl;
        cin >> sch;
        switch (sch)
        {
            case 1: stack_print(top); cout << endl;
            break;
            case 2: cout << average(top) << endl;
            break;
            case 3: top = stack_push(top, 0); stack_sort_p(top); top = stack_del(top);
            break;
            case 4: top = stack_sort_val(top);
            break;
            case 5: return 0;
        }
    }
}

Stack* stack_push(Stack *top, int data)
{
    Stack *comp = new Stack;
    comp->dat = data;
    comp->cont = top;
    return comp;
}

void stack_print (Stack *top)
{
    Stack *comp = top;
    while (comp)
    {
        printf("%- 5d ", comp->dat);
        comp = comp->cont;
    }
}

float average(Stack *top)
{
    int k = 0;
    float avg = 0;
    Stack *comp = top;
    while(comp)
    {
        avg += comp->dat;
        comp = comp->cont;
        k++;
    }
    avg /= k;
    comp = top;
    comp->dat = avg;
    comp = comp->cont;
    return avg;
}

Stack* stack_sort_p(Stack *top)
{
    Stack *exit = NULL, *temp, *cur_top;
    if (top->cont->cont == NULL) return top;
    do
    {
        for (cur_top = top; cur_top->cont->cont != exit; cur_top = cur_top->cont)
        {
            if (cur_top->cont->dat > cur_top->cont->cont->dat)
            {
                temp = cur_top->cont->cont;
                cur_top->cont->cont = temp->cont;
                temp->cont = cur_top->cont;
                cur_top->cont = temp;
            }
        }
        exit = cur_top->cont;
    }while(top->cont->cont != exit);
    return top;
}

Stack* stack_del(Stack* top)
{
    Stack* comp;
    comp = new Stack;
    comp = top;
    top = comp->cont;
    comp->dat = '\0';
    return top;
}

Stack* stack_sort_val(Stack* top)
{
    Stack *exit = NULL, *cur_top;
    int temp;
    do
    {
        for(cur_top = top; cur_top->cont != exit; cur_top = cur_top->cont)
            if(cur_top->dat > cur_top->cont->dat)
            {
                temp = cur_top->dat;
                cur_top->dat = cur_top->cont->dat;
                cur_top->cont->dat = temp;
            }
        exit = cur_top;
    }while(top->cont != exit);
    return top;
}