#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

struct tree
{
    int key;
    string text;
    tree *left, *right;
};

tree* make_tree(string, int);//

void add(tree*, string, int);//

void print(tree*, int = 0);//

void find (tree*, int);//

tree* make_AVL (tree*);//

tree* del(tree**, int);//

int task(tree*, char, int = 0);

int main()
{
    tree* root = new tree;
    root = make_tree("Create", 8);
    add(root, "Text here", 3);
    add(root, "Test 1", 1);
    add(root, "Test 2", 6);
    add(root, "Test 3", 7);
    add(root, "Test 4", 4);
    add(root, "Test 17", 5);
    add(root, "Test 7", 14);
    add(root, "Test 8", 12);
    add(root, "Test 9", 13);
    add(root, "Test 10", 11);
    add(root, "Test 11", 15);
    add(root, "Test 12", 19);
    add(root, "Test 13", 16);
    add(root, "Test 14", 17);
    add(root, "Test 15", 18);
    add(root, "Test 16", 20);
    print(root);
    while (true)
    {
        int num;
        string line;
        char s;
        cout << "Введите номер функции:\n1 - Добавить элемент\n2 - Удалить элемент\n3 - Вывести дерево\n4 - Сбалансировать дерево\n5 - Выполнение задания\n0 - Выход\n";
        int ch;
        cin >> ch;
        switch(ch)
        {
            case 1:
            cout << "Введите ключ: ";
            cin >> num;
            cin.ignore();
            cout << "Введите текст: ";
            getline(cin, line);
            add(root, line, num);
            break;
            case 2:
            cout << "Введите ключ: ";
            cin >> num;
            root = del(&root, num);
            break;
            case 3: print(root);
            break;
            case 4: root = make_AVL(root);
            break;
            case 5:
            cout << "Введите первую букву: ";
            cin >> s;
            cout << "Найдено " << task(root, s) <<  " совпадений" <<endl;
            break;
            case 0: return 0;
        }
    }
    return 0;
}

tree* make_tree(string line, int key)                                      //Создание листа
{
    tree* leaf = new tree;
    leaf->key = key;
    leaf->text = line;
    leaf->left = leaf->right = NULL;
    return leaf;
}

void add(tree* root, string text, int key)                                 //Добавление листа
{
    tree* leaf = new tree, *anc;
    leaf = root;
    while (leaf)
    {
        anc = leaf;
        if (key < leaf->key) leaf = leaf->left;
            else if (key > leaf->key) leaf = leaf->right;
                else cout << "Ключ не уникален" << endl;
    }
    leaf = make_tree(text, key);
    if (key < anc->key) anc->left = leaf;
        else anc->right = leaf;
}

void print(tree* rt, int depth)                                            //Вывод дерева
{
    string str;
    if (rt)
    {
        print(rt->right, depth + 1);
        for (int i = 0; i < depth; i++) str += "    ";
        cout << str << rt->key << " - " << rt->text << endl;
        print(rt->left, depth + 1);
    }
}

void find(tree* root, int key)                                             //Поиск по ключу
{
    tree* leaf = new tree;
    leaf = root;
    while (leaf)
    {
        if (key < leaf->key) leaf = leaf->left;
            else if (key > leaf->key) leaf = leaf->right;
                else 
                {
                    cout << leaf->text << '\n' << leaf->key << endl;
                    return;
                }
    }
    cout << "Запись не найдена" << endl;
}

int height(tree* node)                                                     //Высота дерева 
{
    if(node == 0)
    return 0;
    int left = 0, right = 0;
    if (node->left != NULL)
    {
        left = height(node->left);
    }
    if (node->right != NULL)
    {
        right = height(node->right);
    }
    int max = left > right ? left : right;
    return max + 1;    
}

void add_to_arr (tree* nd, int *num, string *t, int &idx)                  //Запись данных в массив
{
    num[idx] = nd->key;
    t[idx] = nd->text;
    if (nd->left) add_to_arr(nd->left, num, t, ++idx);
    if (nd->right) add_to_arr(nd->right, num, t, ++idx);
};

void balance(tree **node, int idx, int size, int *a, string *b)            //Балансировка дерева
{
    if (idx == size) 
    { 
        *node = NULL;
        return;
    }
    else 
    {
        int m = (idx + size) / 2;
        *node = new tree;
        (*node)->key = a[m];
        (*node)->text = b[m];
        balance(&(*node)->right, idx, m, a, b);
        balance(&(*node)->left, m+1, size, a, b);
    }
}

tree* make_AVL (tree* root)                                                //Балансировка
{
    int *keys, h = height(root), size = 0, max, temp_i, sch = 0;
    string *lines, temp_s;
    for (int i = 0; i < h; i++) size += pow(2, i);
    keys = new int[size];
    lines = new string[size];
    int pos = 0;
    add_to_arr (root, keys, lines, pos);       
    for (int m = 0; m < size - 1; m++)
    {
        max = m;
        for (int n = m + 1; n < size; n++) if (keys[max] < keys[n]) max = n;
        temp_i = keys[max];
        keys[max] = keys[m];
        keys[m] = temp_i;
        temp_s = lines[max];
        lines[max] = lines[m];
        lines[m] = temp_s;
    }
    for (int n = 0; keys[n] != '\0'; n++) sch++;
    int* res_keys = new int[sch];
    string* res_lines = new string[sch];
    for (int i = 0, k = 0; i < sch; i++)
    {
        if (keys[i] != 0) 
        {
            res_keys[k] = keys[i];
            res_lines[k] = lines[i]; 
            k++;
        }
    }
    delete[] lines;
    delete[] keys;
    balance(&root, 0, sch, res_keys, res_lines);
    return root;
}

tree* del(tree** rt, int key)                                                //Удаление
{
    tree *anc = *rt, *ch, *del;
    del = *rt;
    while (del != NULL)                                                            //Поиск элемента по ключу
    {
        if (key < del->key) 
        {
            anc = del;
            del = del->left;
        }
            else if (key > del->key) 
            {
                anc = del;
                del = del->right;
            }
            else break;
    }
    if (del == NULL) 
    {
        cout << "Элемент не найден!" << endl;
        return *rt;
    }
    if ((del == anc) && ((anc->left == NULL) || (anc->right == NULL)))
    {
        if (anc->left == NULL) 
        {
            rt = &anc->right;
            return *rt;
        }
        else 
        {
            rt = &anc->left;
            return *rt;
        }
    }
    if ((del->left == NULL) && (del->right == NULL))                                         //Если дочерних элементов нет
    {
        if (anc->key < key) anc->right = NULL;
            else anc->left = NULL;
        delete del;
        return *rt;
    }
    if (del->right == NULL)                                                       //Если нет правого узла
    {
        if (anc->right == del) anc->right = del->left;
            else anc->left = del->left;
        return *rt;
    }
    if (del->left == NULL)                                                        //Если нет левого узла
    {
        if (anc->right == del) anc->right = del->right;
            else anc->left = del->right;
            return *rt;
    }
    if (del->left && del->right)                                           //Если есть оба дочерних узла
    {
        tree* temp = del->right;
        ch = temp;
        while(ch->left != NULL) 
        {
            temp = ch;
            ch = ch->left;
        }
        temp->left = ch->right;
        if (ch == del->right) del->right = del->right->right;
        del->key = ch->key;
        del->text = ch->text;
        return *rt;
    }
}

int task(tree* cur_rt, char chr, int match)                                //Задание
{
    if (!cur_rt) return match;
    if (cur_rt->text[0] == chr) match++;
    match = task(cur_rt->left, chr, match);
    match = task(cur_rt->right, chr, match);
}