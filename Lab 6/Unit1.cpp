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
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
        int n,m,i1=0,i2=0;
        n=Edit1->Text.ToDouble();
        m=Edit2->Text.ToDouble();
        StringGrid1->ColCount=Edit2->Text.ToDouble();
        StringGrid1->RowCount=Edit1->Text.ToDouble();
        do
        {
            for (i1; i1<=m; i1++)
            {StringGrid1->Cells[i1][i2]=IntToStr(random(50)-24);}
            i2++;
            i1=0;
        }
        while (i2<=n);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
        int n,m,k=0,i1=1,i2=0;
        StringGrid1->ColCount=Edit2->Text.ToDouble();
        StringGrid1->RowCount=Edit1->Text.ToDouble();
        n=Edit1->Text.ToDouble();
        m=Edit2->Text.ToDouble();
        do
        {
            for (i1; i1<=m-1; i1++)
            {
                if (StrToInt(StringGrid1->Cells[i1][i2])>StrToInt(StringGrid1->Cells[i1-1][i2]) && StrToInt(StringGrid1->Cells[i1][i2])<StrToInt(StringGrid1->Cells[i1+1][i2]))
                k++;
            }
            i2++;
            i1=1;
        }
        while (i2<=n);
        Edit3->Text=IntToStr(k);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
        int n,m,i1=0,i2=0;
        n=Edit1->Text.ToDouble();
        m=Edit2->Text.ToDouble();
        do
        {
            for (i1; i1<=m; i1++)
            {StringGrid1->Cells[i1][i2]=IntToStr(random(50)-24);}
            i2++;
            i1=0;
        }
        while (i2<=n);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit1Change(TObject *Sender)
{
        StringGrid1->RowCount=Edit1->Text.ToDouble();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit2Change(TObject *Sender)
{
        StringGrid1->ColCount=Edit2->Text.ToDouble();
}
//---------------------------------------------------------------------------

