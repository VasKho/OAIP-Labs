//---------------------------------------------------------------------------

#include <vcl.h>
#include <iostream.h>
#include <conio.h>
#include <math.h>
#pragma hdrstop

//---------------------------------------------------------------------------
int fact (int num)
{
   int f=1;
   for (num; num>0; num--)
   {
     f*=num;
   };
   return f;
};

#pragma argsused
int main(int argc, char* argv[])
{
        double a,b,h,x,s,y,s1;
        int n,k;
        a=0.1;
        b=1.0;
        h=0.1;
        n=3;
//        cout <<"Vvedite a,b,h,n:\n";
//        cin >> a >> b >> h >> n;
        s=0;
        for (x=a; x<=b; x+=h)
           {
             y=((x*x/4.)+(x/2.)+1)*exp(x/2.);
                for (k=0; k<=n; k++)
                {
                s1=(k*k+1)/(fact(k)+0.0)*pow(x/2.,k);
                s+=s1;
                };
                cout <<"x= "<<x<<" y= "<<y<<" s= "<<s<<" |y-s|= "<<fabs(y-s)<<"\n";
                    s=0;
           };
           getch();
        return 0;
}
//---------------------------------------------------------------------------
 