#include <iostream>
#include <time.h>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void massivchik ( long size, int* array)
{

   srand(time(0));

   for (long i = 0; i < size; i++)
   {
       array[i] = 1 + rand() % 9;
   }

    cout <<"�������� ������� ����������. ��������..."<< endl;

}

int main()
{

	setlocale(0,"");

	long N = 500000;
	int a[N];

	cout <<""<< endl;

	massivchik( N, a);
	unsigned long counter=0;
	int buff = 0;
	DWORD time1 = ::GetTickCount();
	int i, j, step;
    int tmp;

    for (step = N / 2; step > 0; step /= 2)
        for (i = step; i < N; i++)
        {
            tmp = a[i];
            for (j = i; j >= step; j -= step)
            {
                if (tmp < a[j - step])
                {
                    a[j] = a[j - step];
                }

                else
                {
                    break;
                }

            }
            a[j] = tmp;
        }

	DWORD time2 = ::GetTickCount() - time1;

	cout << endl;
	cout<<"������� �� ��������! ^_^"<<endl;
	cout<<"��������� ��������� ���������� �����: "<<time2<<"��"<<endl;
	cout<<"���-�� �������� ��������� � �����������: "<<counter*2-N<<endl;

	return 0;

}
