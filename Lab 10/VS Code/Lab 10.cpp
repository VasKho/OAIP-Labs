#include <iostream>
#include <fstream>
 #include <string.h>

using namespace std;

struct Student
{
    char* FIO;
    char* group;
    char* marks;
    char* street;
}*stud;

void create();              //Создать файл
void show();                //Просмотр содержимого
void add();                 //Добавление записи
void line_search();         //Линейный поиск
void straight_choise();     //Прямой выбор
void quick_sort();          //Quick sort
void by_div();              //Разделением

int main()
{
    int choise;
    while(true)
    {
        cout << "1 - Создать файл;\n2 - Просмотреть файл;\n3 - Добавить запись;\n4 - Линейный поиск;\n5 - Прямой выбор;\n6 - Quick Sort;\n7 - Разделением;\n8 - Выход;\n";
        cin >> choise;
        switch (choise)
        {
            case 1: create(); break;
            case 2: show(); break;
            case 3: add(); break;
            case 4: line_search(); break;
            case 5: straight_choise(); break;
            case 6: quick_sort(); break;
            case 7: by_div(); break;
            case 8: return 0;
        }
    }
}

void create()
{
    ofstream file("./Database/result.txt");
    cout << "Файл успешно создан" << endl;
    file.close();
}

void show()
{
    ifstream file("./Database/result.txt", ios::binary | ios::ate);
    int size = file.tellg();
    file.close();
    if (size != 0)
    {
        int read (string);
        int s_num = read("./Database/result.txt");
        for (int n = 0; n < s_num; n++)
            {
                cout << stud[n].FIO;
                cout << stud[n].group;
                cout << stud[n].marks;
                cout << stud[n].street;
                cout << endl;
            }
    }
    else cout << "Ошибка чтения файла";
    cout << "--------------------------------------------------"  << endl;
}

void add()
{
    string f, gr, mrk, strt;
    cout << "Введите фамилию: ";
    cin.ignore();
    getline(cin, f);
    cout << "Введите номер группы: ";
    getline(cin, gr);
    cout << "Введите оценки: ";
    getline(cin, mrk);
    cout << "Введите адрес: ";
    getline(cin, strt);
    ofstream file("./Database/result.txt", ios::binary | ios::app);
    file << f << '\n' << gr << '\n' << mrk << '\n' << strt << '\n' << '~' << endl;
    file.close();
}

void line_search()
{
    int read(string);
    bool check_marks(char*);
    bool check_adress(char*);
    int s_num = read("./Database/result.txt");
    int k = 0;
    for (int n = 0; n < s_num; n++)
    {
        if (check_marks(stud[n].marks) && check_adress(stud[n].street))
        {
            cout << stud[n].FIO;
            cout << stud[n].group;
            cout << stud[n].marks;
            cout << stud[n].street;
            cout << endl;
            k++;
        }
    }
    cout << "Количество подходящих учащихся: " << k << endl;
    cout << "--------------------------------------------------" << endl;
}

void straight_choise()
{
    int read (string);
    int s_num = read("./Database/result.txt");
    ofstream file("./Database/result.txt", ios::binary);
    int min;
    for (int i = 0; i < s_num; i++)
    {
        min = i;
        const char* s1 = stud[min].FIO;
        for (int n = i+1; n < s_num; n++)
        {
            const char* s2 = stud[n].FIO;
            if (strcmp(s1, s2) > 0) min = n;
        }
        Student temp;
        temp = stud[i];
        stud[i] = stud[min];
        stud[min] = temp;
        file << stud[i].FIO << stud[i].group << stud[i].marks << stud[i].street <<  '~' << endl;
    }
    file.close();
}

void quick_sort()
{
    void Quick_Sort(Student*, int, int);
    int read(string);
    int s_num = read("./Database/result.txt");
    Quick_Sort(stud, 0, s_num - 1);
    ofstream file("./Database/result.txt", ios::binary);
    for (int i = 0; i < s_num; i++) file << stud[i].FIO << stud[i].group << stud[i].marks << stud[i].street <<  '~' << endl;
    file.close();
}

void by_div()
{
    int read (string);
    bool check_marks (char*);
    bool check_adress(char*);
    int s_num = read("./Database/result.txt");
    s_num--;
    int cur_md, i = 0;
    string key;
    cout << "Введите фамилию для поиска: ";
    cin.ignore();
    getline(cin, key);
    key += '\n';
    for(; i < s_num;)
    {
        cur_md = (i + s_num)/2;
        if (stud[cur_md].FIO < key) i = cur_md + 1;
            else s_num = cur_md;
    }
    if ((strcmp(stud[i].FIO, key.c_str()) == 0) && check_marks(stud[i].marks) && check_adress(stud[i].street))
    {
        cout << stud[i].FIO;
        cout << stud[i].group;
        cout << stud[i].marks;
        cout << stud[i].street;
        cout << endl;
    }
        else cout << "Учащийся не найден" << endl;
    cout << "--------------------------------------------------" << endl;
}

int read(string path)
{
    ifstream file(path.c_str(), ios::binary | ios::ate);
    int size = file.tellg();
    char *buff;
    buff = new char[size];
    file.seekg (0, ios::beg);
    file.read(buff, size);
    buff[size] = '\0';
    int i = 0, field = 1, s_num = 0, num = 0;
    for (int m = 0; m  < size; m++) if (buff[m] == '~') num++;
    stud = new Student[num];
    for (int q = 0; q < num; q++)
    {
        stud[q].FIO = new char[30];
        stud[q].group = new char[7];
        stud[q].marks = new char[8];
        stud[q].street = new char[15];
    }
    for (; i < size; i++)
    {
        if (buff[i] != '\n')
        {
            switch (field)
            {
             case 1: strncat(stud[s_num].FIO, &buff[i], 1);
             break;
             case 2: strncat(stud[s_num].group, &buff[i], 1);
             break;
             case 3: strncat(stud[s_num].marks, &buff[i], 1);
             break;
             case 4: strncat(stud[s_num].street, &buff[i], 1);
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
        strcat(stud[sch].FIO, "\n");
        strcat(stud[sch].group, "\n");
        strcat(stud[sch].marks,"\n");
        strcat(stud[sch].street, "\n");
        sch++;
    }
    return s_num;
}

bool check_marks(char* str)
{
    string s = str;
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

bool check_adress(char* str)
{
    string s = str;
    if (s.find("г. Минск") < s.length()) return true;
        else if (s.find("г.Минск") < s.length()) return true;
                else return false;
}

void Quick_Sort(Student *s, int bg, int end)
{
    int left = bg, right = end;
    Student x = s[(left + right)/2], temp;
    do
    {
        while(strncmp(s[left].FIO, x.FIO, 30) <= 0) left++;
        while(strncmp(x.FIO, s[right].FIO, 30) <= 0) right--;
        if (left <= right)
        {
            temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left++;
            right--;
        }
    }while (left <= right);
    if (bg < right) Quick_Sort(s, bg, right);
    if (left < end) Quick_Sort(s, left, end);
}