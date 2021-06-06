//---------------------------------------------------------------------------

#include <vcl.h>
#include <string.h>
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
        Memo1->Lines->Add("Лабораторная работа №7");
        Memo1->Lines->Add("Введите текст...");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)  //Хранение в строке
{
        int q=0,r=0;
        String a,b;
        a=Memo1->Lines->Strings[2]+(char)(32);
        char *c;
        c=new char[a.Length()];
        for (int i=1; i<=a.Length(); i++)
        {
            if (a[i]!=(char)(32)) b+=a[i];
                else
                {
                    ListBox1->Items->Add(b);
                    c[q]=b[1];
                    b.Delete(1,b.Length());
                    q++;
                }
        }
        int min=(int)(c[0]);
        do
        {
            for (int k=0; k<=q-1; k++)
            {
                if (min>(int)(c[k]) && c[k]!='~')
                {
                    min=(int)(c[k]);
                }
            }
            for (int k=0; k<=q-1; k++)
            {
                if (min==(int)(c[k]) && c[k]!='~')
                {
                    c[k]='~';
                    min=(int)(c[k]);
                    Memo1->Lines->Add(ListBox1->Items->Strings[k]);
                }
            }
            r++;
        }
        while (r<=q-1);
        delete []c;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)  //Хранение в массиве
{
        int q=0,r=0;
        String a,d;
        a=Memo1->Lines->Strings[2]+(char)(32);
        char *b;
        b=new char[a.Length()];
        char *c;
        c=new char[a.Length()];
        for (int n=1; n<=a.Length(); n++)
        {
            b[n-1]=a[n];
        }
        for (int i=0; i<=a.Length(); i++)
        {
            if (b[i]!=(char)(32)) d+=b[i];
                else
                {
                    ListBox1->Items->Add(d);
                    c[q]=d[1];
                    d.Delete(1,d.Length());
                    q++;
                }
        }
        int min=(int)(c[0]);
        do
        {
            for (int k=0; k<=q-1; k++)
            {
                if (min>(int)(c[k]) && c[k]!='~')
                {
                    min=(int)(c[k]);
                }
            }
            for (int k=0; k<=q-1; k++)
            {
                if (min==(int)(c[k]) && c[k]!='~')
                {
                    c[k]='~';
                    min=(int)(c[k]);
                    Memo1->Lines->Add(ListBox1->Items->Strings[k]);
                }
            }
            r++;
        }
        while (r<=q-1);
        delete []c;
        delete []b;
}
//---------------------------------------------------------------------------


