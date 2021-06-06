#include <stdio.h>
#include <math.h>
#include "./Graph/Graph.h"
#define eps 0.00000001
#define SIZE 8


double function (double x) 
{
    double res = pow(x, 3) + 6*x*x - 0.02*exp(x) - 14;
    return res;
}

double d_function (double x)
{
    double res = 3*x*x + 12*x - 0.02*exp(x); 
    return res;
}

double solve (double x0)
{
    double x1  = x0 - function(x0) / d_function(x0);
    while (fabs(x1-x0)>eps)
    {
        x0 = x1;
        x1 = x0 - function(x0) / d_function(x0);
    }
    return x1;
}

int find_same(double* array, double sol)
{
    if (isnan(sol)*(-1) || isnan(sol)) return 1;
    for (int i = 0; *(array + i) != '\0'; i++)
    if (fabs(*(array + i) - sol) < eps) return 1;
    return 0;
}

int main(int argc, char** argv)
{
    double solutions[SIZE] = {};
    int counter = 0;
    for (int i = -6; i <= 2; i++)
    {
        double sol = solve(i);
        if (!find_same(solutions, sol))
        {
            printf("%10.8f\n", sol);
            solutions[counter++] = sol;
            printf("f(%10.8f) = %10.8f\n", sol, function(sol));
        }
    }
    float* x = new float[80];
    double* y = new double[80];
    int pos = 0;
    for (float i = -6; i <= 2; i += 0.1)
    {
        *(x + pos) = i;
        *(y + pos) = function(i);
        pos++;
    }
    Draw_Graph(&argc, argv, x, y, 80);
    return 0;
}
