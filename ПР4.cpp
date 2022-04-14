#include <iostream>

using namespace std;

int main()
{

    setlocale(0,"");

    int meg, Stewie;
    int lois  = 0;

    cout << "Введите размер массива: ";
    cin >> meg;

    int* arr = new int[meg];
    for (int i = 0; i < meg; i++)
    {
        arr[i] = rand() % 100000;
        cout << arr[i] << "  ";
    }

    cout << endl;
    cout << "Введите искомое число: ";
    cin >> Stewie;
    if (arr[meg - 1] != Stewie)
    {
        arr[meg - 1] = Stewie;
        for (; arr[lois ] != Stewie; lois ++);
        lois ++;
    }
    else
    {
        cout << meg;
        return 0;
    }
    cout << "Позиция числа: " << lois ;

}
