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

	massivchik (N, a);
	unsigned long counter=0;
	int buff = 0;
	DWORD time1 = ::GetTickCount();
    int temp=0;

	for (int i=1; i<=N ; i++)
    {
        for (int j=1; j<=N-i; j++)
        {
            if (a [j]>a [j+1])
            {
                counter++;
                temp=a[j];
                a [j]=a [j+1];
                a [j+1]=temp;
            }
        }
	}

	DWORD time2 = ::GetTickCount() - time1;

	cout << endl;
	cout<<"������� �� ��������! ^_^"<<endl;
	cout<<"��������� ��������� ���������� �����: "<<time2<<"��"<<endl;
	cout<<"���-�� �������� ��������� � �����������: "<<counter*2-N<<endl;

	return 0;

}
