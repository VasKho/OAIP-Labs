//---------------------------------------------------------------------------

#include <vcl.h>
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
        for (int i=1; i<=11; i++)
        {
            StringGrid1->Cells[i][0]=IntToStr(random(50)-24);
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
        const int N=Edit1->Text.ToDouble()+1;
        StringGrid1->ColCount=N;
        int sum=0,k=StrToInt(StringGrid1->Cells[1][0]);
        for (int i=1; i<=N-1; i++)
        {
            if (StrToInt(StringGrid1->Cells[i][0])<StrToInt(StringGrid1->Cells[i+1][0]) & StrToInt(StringGrid1->Cells[i][0])<=k)
            k=StrToInt(StringGrid1->Cells[i][0]);
        }
        int i;
        for (i=1; i<=N-1; i++)
        {
            if (StrToInt(StringGrid1->Cells[i][0])==k)
               {
                   for (i; i<N-1; i++)
                      {
                          sum+=StrToInt(StringGrid1->Cells[i+1][0]);
                      }
               }
        }
        Edit2->Text=IntToStr(sum);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
        int n=StringGrid1->ColCount;
        for (int i=1; i<=n+1; i++)
        {
            StringGrid1->Cells[i][0]=IntToStr(random(50)-24);
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
        StringGrid1->ColCount=Edit1->Text.ToDouble()+1;
}
//---------------------------------------------------------------------------
