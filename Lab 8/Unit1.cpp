//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"

#include <iostream.h>
#include <stdio.h>
#include <io.h>
#include <string.h>

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

FILE *inf;

struct Student
{
    String name;
    int birth_d;
    int group_n;
    float s_b;
} stud;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//------------------------------—Œ«ƒ¿Õ»≈ ‘¿…À¿-------------------------------


void __fastcall TForm1::Button2Click(TObject *Sender)
{
        if (inf = fopen(".\\Result\\inf.txt", "rt")) Memo1->Lines->Add("‘‡ÈÎ ÛÒÔÂ¯ÌÓ ÓÚÍ˚Ú");
            else
            {
                inf = fopen(".\\Result\\inf.txt", "wt");
                Memo1->Lines->Add("‘‡ÈÎ ÛÒÔÂ¯ÌÓ ÒÓÁ‰‡Ì");
            }
        fclose(inf);
}
//------------------------------ƒŒ¡¿¬À≈Õ»≈ —“”ƒ≈Õ“¿--------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
        float readl (TEdit *);
        stud.name = Edit1->Text;
        stud.birth_d = Edit6->Text.ToInt();
        stud.group_n = Edit7->Text.ToInt();
        stud.s_b = (readl(Edit2)+readl(Edit3)+readl(Edit4)+readl(Edit5))/4.;
        inf = fopen(".\\Result\\inf.txt", "at");
        fprintf(inf, "Name: %s\nBirth date: %d\nGroup: %d\nAverage mark: %f\nInf. marks: %s \n~\n", stud.name, stud.birth_d,
        stud.group_n, stud.s_b, Edit2->Text);
        fclose(inf);
}
//------------------------------œ–Œ—ÃŒ“– —Œƒ≈–∆»ÃŒ√Œ-------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
        inf = fopen(".\\Result\\inf.txt", "rt");
        Memo1->Lines->LoadFromFile(".\\Result\\inf.txt");
        fclose(inf);
}
//------------------------------—Œ–“»–Œ¬ ¿-----------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
      bool check(string, string , string);
      char *field;
      int desc;
        inf = fopen(".\\Result\\inf.txt", "rt");
        desc = fileno(inf);
        unsigned  i = 0, k = 0, size = filelength(desc);
        field = new char[size];
        fread(field, size, 1, inf);
        fcloseall();
      while(i <= size)          //ÔÓ‚ÂÍ‡ ÍÓÎË˜ÂÒÚ‚‡ ÔÓÎÂÈ
      {
          if (field[i] == '~') k++;
          i++;
      };
      string dat[5];
      i = 0;
      unsigned f = 1;
      while (f <= k)
      {
          for (int m = 0; m < 5; m++)       //Á‡ÔËÒ¸ ËÌÙ. ‚ Ï‡ÒÒË‚
          {
              for(; field[i] != '\n'; i++) dat[m] += field[i];
              i++;
          }
          if (check(dat[2], dat[4], Edit8->Text.c_str()))
          {
              for (int n = 0; n < 5; n++)
                  Memo1->Lines->Add(dat[n].c_str());
              Memo1->Lines->Add('\n');
          }
          i += 2;
          f++;
          for (int q = 0; q < 5; q++) dat[q].clear();
      }
}
//------------------------------Œ◊»—“ ¿ ¬€¬Œƒ¿-------------------------------
void __fastcall TForm1::Button6Click(TObject *Sender)
{
        Memo1->Clear();
}
//---------------------------------------------------------------------------

float readl (TEdit *win)                          //˜ÚÂÌËÂ ÒÚÓ˜ÍË ‰Îˇ ÒÂ‰ÌÂ„Ó ·‡ÎÎ‡
{
    string line = win->Text.c_str();
    line += ' ';
    char *buff;
    buff = new char[2];
    static unsigned i=0;
    unsigned m = 0, k = 0;
    float s_b = 0;
    for (i; i <= line.length(); i++)
    {
        if (line[i]!=' ')
        {
            buff[m]=line[i];
            m++;
        }
        else
        {
            m = 0;
            k++;
            s_b += atoi(buff);
            for (int n = 0; n < 2; n++) buff[n] = '\0';
            continue;
        }
    }
    s_b /= k;
    i = k = 0;
    return s_b;
}

bool check (string ln, string s, string group)    //ÔÓ‚ÂÍ‡ Ì‡ ÒÓÓÚ‚ÂÚÒÚ‚ËÂ ÛÒÎÓ‚Ë˛
{
    if (ln != "Group: "+group) return false;
    string bf;
    bf = s.substr(12);
    char *buff;
    buff = new char[2];
    unsigned m = 0;
    static unsigned i = 0;
    while(i <= bf.size())
    {
        if (bf[i] != ' ')
        {
            buff[m]=bf[i];
            m++;
            i++;
        }
        else if (strncmp(buff, "9", 1) == 0 || strncmp(buff, "10", 2) == 0)
                {
                 m=0;
                 while (buff[m] != '\0') buff[m] = '\0';
                 m=0;
                 i++;
                }
                else
                {
                    i = 0;
                    return false;
                }
    }
    i = 0;
    return true;
}

