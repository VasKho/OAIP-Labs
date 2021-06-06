#include <vcl.h>
#include <iostream.h>
#include <fstream>
#include <string>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

struct Student
{
    string FIO;
    string group;
    string marks;
    string street;
}*stud;
    
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//--------------------ÑÎÇÄÀÒÜ------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
        ofstream file(".\\Database\\result.txt");
        Memo1->Lines->Add("Ôàéë óñïåøíî ñîçäàí");
        file.close();
}
//--------------------ÏÎÊÀÇÀÒÜ-----------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
        ifstream file(".\\Database\\result.txt", ios::binary | ios::ate);
        int size = file.tellg();
        file.close();
        if (size != 0)
        {
            int read (char*);
            int s_num = read(".\\Database\\result.txt");
            for (int n = 0; n < s_num; n++)
                {
                    Memo1->Lines->Add(stud[n].FIO.c_str());
                    Memo1->Lines->Add(stud[n].group.c_str());
                    Memo1->Lines->Add(stud[n].marks.c_str());
                    Memo1->Lines->Add(stud[n].street.c_str());
                    Memo1->Lines->Add("");
                }
            delete[] stud;
        }
        else Memo1->Lines->Add("Îøèáêà ÷òåíèÿ ôàéëà");
        Memo1->Lines->Add("--------------------------------------------------");
}
//--------------------ÄÎÁÀÂÈÒÜ-----------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
        string f, gr, mrk, strt;
        f = Edit1->Text.c_str();
        gr = Edit2->Text.c_str();
        mrk = Edit3->Text.c_str();
        strt = Edit4->Text.c_str();
        ofstream file(".\\Database\\result.txt", ios::binary | ios::app);
        file << f << '\n' << gr << '\n' << mrk << '\n' << strt << '\n' << '~' << endl;
        file.close();
}
//--------------------ËÈÍÅÉÍÛÉ ÏÎÈÑÊ-----------------------------------------
void __fastcall TForm1::Button7Click(TObject *Sender)
{
        int read (char*);
        bool check_marks (string);
        bool check_adress(string);
        int s_num = read(".\\Database\\result.txt");
        int k = 0;
        for (int n = 0; n < s_num; n++)
        {
            if (check_marks(stud[n].marks) && check_adress(stud[n].street))
            {
                Memo1->Lines->Add(stud[n].FIO.c_str());
                Memo1->Lines->Add(stud[n].group.c_str());
                Memo1->Lines->Add(stud[n].marks.c_str());
                Memo1->Lines->Add(stud[n].street.c_str());
                Memo1->Lines->Add("");
                k++;
            }
        }
        Memo1->Lines->Add("Êîëè÷åñòâî ïîäõîäÿùèõ ó÷àùèõñÿ: "+IntToStr(k));
        delete[] stud;
        Memo1->Lines->Add("--------------------------------------------------");
}
//--------------------ÏĞßÌÎÉ ÂÛÁÎĞ-------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
        int read (char*);
        int s_num = read(".\\Database\\result.txt");
        ofstream file(".\\Database\\result.txt", ios::binary);
        int min;
        for (int i = 0; i < s_num; i++)
        {
            min = i;
            const char* s1 = stud[min].FIO.c_str();
            for (int n = i+1; n < s_num; n++)
            {
                const char* s2 = stud[n].FIO.c_str();
                if (strcmp(s1, s2) > 0) min = n;
            }
            Student temp;
            temp = stud[i];
            stud[i] = stud[min];
            stud[min] = temp;
            file << stud[i].FIO << stud[i].group << stud[i].marks << stud[i].street <<  '~' << endl;
        }
        file.close();
        delete[] stud;
}
//--------------------ÁÛÑÒĞÀß ÑÎĞÒÈĞÎÂÊÀ-------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{
        void Quick_Sort(Student*, int, int);
        int read(char*);
        int s_num = read(".\\Database\\result.txt");
        Quick_Sort(stud, 0, --s_num);
        delete[] stud;
}
//--------------------ĞÀÇÄÅËÅÍÈÅÌ--------------------------------------------
void __fastcall TForm1::Button6Click(TObject *Sender)
{
        int read (char*);
        bool check_marks (string);
        bool check_adress(string);
        int s_num = read(".\\Database\\result.txt");
        s_num--;
        int cur_md, i = 0;
        string key = Edit5->Text.c_str();
        key += '\n';
        for(; i < s_num;)
        {
            cur_md = (i + s_num)/2;
            if (stud[cur_md].FIO < key) i = cur_md + 1;
                else s_num = cur_md;
        }
        if (stud[i].FIO == key && check_marks(stud[i].marks) && check_adress(stud[i].street))
        {
            Memo1->Lines->Add(stud[i].FIO.c_str());
            Memo1->Lines->Add(stud[i].group.c_str());
            Memo1->Lines->Add(stud[i].marks.c_str());
            Memo1->Lines->Add(stud[i].street.c_str());
            Memo1->Lines->Add("");
        }
            else Memo1->Lines->Add("Ó÷àùèéñÿ íå íàéäåí");
        delete[] stud;
        Memo1->Lines->Add("--------------------------------------------------");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender)
{
        Memo1->Clear();
}
//---------------------------------------------------------------------------


int read(char* path)
{
    ifstream file(path, ios::binary | ios::ate);
    int size = file.tellg();
    char *buff;
    buff = new char[size];
    file.seekg (0, ios::beg);
    file.read(buff, size);
    buff[size] = '\0';
    file.close();
    int i = 0, field = 1, s_num = 0, num = 0;
    for (int m = 0; m  < size; m++) if (buff[m] == '~') num++;
    stud = new Student[num];
    for (; buff[i] != '\0'; i++)
    {
        if (buff[i] != '\n')
        {
            switch (field)
            {
             case 1: stud[s_num].FIO += buff[i];
             break;
             case 2: stud[s_num].group += buff[i];
             break;
             case 3: stud[s_num].marks += buff[i];
             break;
             case 4: stud[s_num].street += buff[i];
            }
        }
        else field++;
        if (buff[i] == '~')
        {
            s_num++;
            field = 1;
            i++;
        }
    }
    int sch = 0;
    while(sch < s_num)
    {
        stud[sch].FIO += '\n';
        stud[sch].group += '\n';
        stud[sch].marks += '\n';
        stud[sch].street += '\n';
        sch++;
    }
    return s_num;
}


bool check_marks(string s)
{
    if (s[s.length()-2] == ' ') s[s.length()-1] = '\0';
        else s[s.length()-1] = ' ';
    char *buff;
    buff = new char[2];
    int k = 0, n = 0;
    float s_b = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != ' ') buff[n++] = s[i];
        else
        {
            s_b += atof(buff);
            k++;
            n = 0;
            for (int m = 0; m < 2; m++) buff[m] = '\0';
        }
    }
    delete[] buff;
    s_b /= k;
    if (s_b >= 8.5) return true;
        else return false;
}


bool check_adress(string s)
{
    if (s.find("ã. Ìèíñê") < s.length()) return true;
        else if (s.find("ã.Ìèíñê") < s.length()) return true;
                else return false;
}


void Quick_Sort(Student *s, int bg, int end)
{
    int left = bg, right = end;
    Student x = s[(left + right)/2], temp;
    ofstream file(".\\Database\\result.txt", ios::binary);
    do
    {
        while(s[left].FIO < x.FIO) left++;
        while(x.FIO < s[right].FIO) right--;
        if (left <= right)
        {
            temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left++;
            right--;
        }
    }while (left <= right);
    if (bg < right) Quick_Sort(s, bg, end);
    if (left < end) Quick_Sort(s, left, end);
    for (int i = 0; i <= end; i++)
    file << stud[i].FIO << stud[i].group << stud[i].marks << stud[i].street <<  '~' << endl;
    file.close();
}
