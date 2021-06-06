//---------------------------------------------------------------------------

#include <vcl.h>
#include <iostream.h>
#include <math.h>
#include <conio.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
int main(int argc, char* argv[])
{
        double a,b,z,f,y,x,ch,zn;
        int fi;
        cout << "Vvedite a, b, z:\n";
        cin >> a >> b >> z;
        if (z>0)
        {
        x=1./(z*z+2*z);
        cout <<"z>0";
        }
          else
          {
          x=1-pow(z,3);
          cout << "z<0 || z=0";
          };
        cout << "\nVyberite funkcyu\n 1) 2x\n 2) x^2\n 3) x/3\n";
        cin >> fi;
        switch(fi)
        {
                case 1: {f=2*x; cout << "Funkcya: 2x\n"; break;}
                case 2: {f=x*x; cout << "Funkcya: x^2\n"; break;}
                case 3: {f=x/3.; cout << "Funkcya: x/3\n"; break;}
        }
        ch=2.5*a*exp(-3*x)-4*b*x*x;
        zn=log(fabs(x))+f;
        y=ch/zn;
        cout << "y=" << y;
        getch();
        return 0;
}
//---------------------------------------------------------------------------
 