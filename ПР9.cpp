#include "iostream"
#include "windows.h"

int max_order(int num)
{
    int max = 0;
    while (num > 1)
    {
        num /= 10;
        max++;
    }
    return max;
}

int velich_order(int num, int order)
{
    while (order > 1)
    {
        num /= 10;
        order--;
    }
    return num % 10;
}

void sort_order(int** mas_add, int* mas, int order,int n)
{
    int* mas_col, i, j, temp = 0;
    mas_col = new int[n];
    for (i = 0; i < n; i++)
        mas_col[i] = 0;
    for (i = 0; i < n; i++)
    {
        int a = velich_order(mas[i], order);
        mas_add[mas_col[a]][a] = mas[i];
        mas_col[a]++;
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < mas_col[i]; j++)
        {
            mas[temp] = mas_add[j][i];
            temp++;
        }
    }
}

int main()
{
    using namespace std;

    setlocale(0, "");

    int n, col_order = 0;
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int order, i, * mas, ** mas_add;

    cout << "Пожалуйста ^_^, введите размер последовательности: ";
    cin >> n;
    mas = new int[n];
    cout << "*Вжух* Элементы последовательности: " << endl;

    for (int i = 0; i < n; i++)
    {
        mas[i] = rand() % 100;
        cout << "[" << i + 1 << "]="<<mas[i]<<endl;
    }

    cout<<endl;

    mas_add = new int* [n];

    for (i = 0; i < n; i++)
    {
        mas_add[i] = new int[n];
    }

    for (i = 0; i < n; i++)
    {
        if (col_order < max_order(mas[i]))
        {
            col_order = max_order(mas[i]);
        }
    }

    for (order = 1; order <= col_order; order++)
    {
        sort_order(mas_add, mas, order,n);
    }
    for (i = 0; i < n; i++)
    {
        cout << mas[i] << endl;
    }
    return 0;
}
