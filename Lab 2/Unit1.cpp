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
        Memo1->Lines->Add("Лабораторная работа №2");
        RadioGroup1->ItemIndex = 0;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
        double a,b,z,f,y,x,ch,zn;
        a=Edit1->Text.ToDouble();
        b=Edit2->Text.ToDouble();
        z=Edit3->Text.ToDouble();
        if (z>0)
        {
        x=1./(z*z+2*z);
        Memo1->Lines->Add("z>0");
        }
          else
          {
          x=1-pow(z,3);
          Memo1->Lines->Add("z<0 || z=0");
          };
        switch(RadioGroup1->ItemIndex)
        {
                case 0: {f=2*x; Memo1->Lines->Add("Функция: 2x"); break;}
                case 1: {f=x*x; Memo1->Lines->Add("Функция: x^2"); break;}
                case 2: {f=x/3.; Memo1->Lines->Add("Функция: x/3"); break;}
        }
        ch=2.5*a*exp(-3*x)-4*b*x*x;
        zn=log(fabs(x))+f;
        y=ch/zn;
        Memo1->Lines->Add("y="+FloatToStr(y));
}
//---------------------------------------------------------------------------
