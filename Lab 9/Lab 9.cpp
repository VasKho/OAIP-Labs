#include <iostream>
#include <math.h>
#include <conio.h>

using namespace std;

double rec_stair (int);
double std_stair (int);

int main()
{
    cout << "Vvedite chislo: ";
    int x;
    cin >> x;
    cout << "Recursivnoe vypolnenie: " << rec_stair (x) << endl;
    cout << "Standartnoe vypolnenie: " << rec_stair (x) << endl;
    getch();
    return 0;
}

double rec_stair (int n)
{
    double y = 1;
    if (n == 2) y /= 2 + pow(1 + 0.5, -1);
    else y = pow(n + rec_stair (n - 1), -1);
    return y;
}

double std_stair (int n)
{
    double y = 1.5;
    for (int m = 2; m <= n; m++)
        y = m + 1/y;
    return y;
}