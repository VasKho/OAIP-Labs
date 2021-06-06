//---------------------------------------------------------------------------

#include <vcl.h>
#include <math.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
        Memo1->Clear();
        Memo1->Lines->Add("Лабораторная работа №4");
        RadioGroup1->ItemIndex=0;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
double* s(double, double, double, int);
double* y(double, double, double);
double* d(double*, double*,TMemo*);
void out(double*, TMemo*);
int fact(int);
        double a,b,h,n;
        a=Edit1->Text.ToDouble();
        b=Edit2->Text.ToDouble();
        h=Edit3->Text.ToDouble();
        n=Edit4->Text.ToDouble();
       switch (RadioGroup1->ItemIndex)
        {
        case 0: out(s(a,b,h,n),Memo1); break;
        case 1: out(y(a,b,h),Memo1); break;
        case 2: d(y(a,b,h),s(a,b,h,n),Memo1); break;
        };
}
//---------------------------------------------------------------------------
        int fact(int num)
        {
         int f=1;
         for (int q=1; q<=num; q++)
         {f*=q;}
         return f;
        }

        double* s(double x, double y, double h, int k)
        {
         double s1,sum;
         int p,i=1;
         p=(y-x)/h;
         s1=sum=0;
         double *func=new double[p+3];
         func[0]=p+2;
            for (x; x<=y; x+=h)
             {
                   for (int n=0; n<=k; n++)
                    {
                     s1=pow((x/2.),n)/(fact(n)+0.0)*(n*n+1);
                     sum+=s1;
                    }
                 func[i++]=sum;
                 sum=0;
              }
         return func;
         delete []func;
        }                                                   

        double* y(double x, double y, double h)
        {
         double a=0;
         int i=1,p;
         p=(y-x)/h;
         double *func=new double[p+3];
         func[0]=p+2;
         for (x; x<=y; x+=h)
            {
             a=((x*x/4.)+(x/2.)+1)*exp(x/2);
             func[i++]=a;
            };
         return func;
         delete []func; 
        }

        double* d(double arr1[], double arr2[],TMemo* mem)
        {
         double *dif=new double[arr1[0]+1];
         for (int i=1; i<=arr1[0]; i++)
            {
             dif[i-1]=0;
             dif[i-1]=fabs(arr1[i]-arr2[i]);
             mem->Lines->Add(FloatToStrF(dif[i-1],ffFixed,8,7));
            }
         return dif;
         delete []dif;
        }

        void out(double arr[], TMemo* mem)
        {
         for (int i=1; i<=arr[0]; i++)
            {
             mem->Lines->Add(FloatToStrF(fabs(arr[i]),ffFixed,8,7));
            }
        }
void __fastcall TForm1::Button2Click(TObject *Sender)
{
        Memo1->Clear();
        Memo1->Lines->Add("Лабораторная работа №4");
}
//---------------------------------------------------------------------------

