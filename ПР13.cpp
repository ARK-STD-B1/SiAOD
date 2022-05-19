#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    setlocale(0,"");

    const int q =4;
    int mass[q][q];
    int X;

    cout << "Ручной ввод '0'"<< endl;
    cout << "Автоматический ввод '1'"<< endl << endl;
    cin >> X;
    cout << endl;

    switch (X)
    {
    case 0:
    {
        for(int i = 0; i < q; i++) {
            for (int k = 0; k < q; k++) {
                cout << "Ввод графов: a[" << i << "][" << k << "] ";
                cin >> mass[i][k];
            }
        }
        break;
    }

    case 1:
    {
        for (int i = 0; i < q; i++) {
            for (int k = 0; k < q; k++) {
                mass[i][k]=rand() % 10;
            }
        }
        break;
    }
    }

    for (int i = 0; i < q; i++)
    {
        for (int k = 0; k < q; k++)
        {
            cout << mass[i][k] << " ";
        }
        cout << endl;
    }

    cout << endl;

    int g = 7;
    bool* post = new bool[g];
    memset(post, false, sizeof(bool) * g);
    post[0] = true;

    for (int l = 0; l < g - 1; l++)
    {
        int mini2 = -1, mini1 = -1;
        for (int i = 0; i < g; i++)
            if (post[i])
            {
                for (int k = 0; k < g; k++)
                {
                    if (!post[k] && mass[i][k] > 0 && (mini1 == -1 || mass[i][k] < mass[mini1][mini2]))
                    {
                        mini1 = i, mini2 = k;
                    }
                }
            }
        post[mini2] = true;
        cout << mini1 << " >>> " << mini2 << endl;
    }

    return 0;
}
