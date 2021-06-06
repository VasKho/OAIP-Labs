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
        Memo1->Lines->Add("Лабораторная работа №1");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
        double a,b,h,x,s,y,s1;
        int n,k;
        a=Edit1->Text.ToDouble();
        b=Edit2->Text.ToDouble();
        h=Edit3->Text.ToDouble();
        n=Edit4->Text.ToDouble();
        s=0;
        for (x=a; x<=b; x+=h)
           {
             y=((x*x/4.)+(x/2.)+1)*exp(x/2.);
                for (k=0; k<=n; k++)
                {
                s1=(k*k+1)/(fact(k)+0.0)*pow(x/2.,k);
                s+=s1;
                };
             Memo1->Lines->Add("При x= "+FloatToStrF(x,ffFixed,4,2)+" y= "+
                FloatToStrF(y,ffFixed,6,4)+" s= "+FloatToStrF(s,ffFixed,6,4)+
                    " |y-x|= "+FloatToStrF(fabs(y-s),ffFixed,6,4)+"\n");
                    s=0;
           };
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
          Memo1->Clear();
          Memo1->Lines->Add("Лабораторная работа №1");
}
//---------------------------------------------------------------------------

