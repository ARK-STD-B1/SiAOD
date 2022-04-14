#include <iostream>

using namespace std;

void merge(int *,int, int , int );

void sortirovochka(int *arr, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid=(low+high)/2;
        sortirovochka(arr,low,mid);
        sortirovochka(arr,mid+1,high);
        merge(arr,low,high,mid);
    }
}

void merge(int *arr, int low, int high, int mid)
{
    int i, j, k, c[100000];
    i = low;
    k = low;
    j = mid + 1;

    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            c[k] = arr[i];
            k++;
            i++;
        }
        else
        {
            c[k] = arr[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        c[k] = arr[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        c[k] = arr[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++)
    {
        arr[i] = c[i];
    }

}

int main()
{
    setlocale(0,"");

    int myarray[100000], num;

    cout<<"Кол-во элементов для сортировочки: ";
    cin>>num;

    for (int i = 0; i < num; i++)
    {
        myarray[i] = rand() % 100000;

        cout << myarray[i];

        if (i != num-1)
         {
             cout<<", ";
         }
         else
         {
             cout<<".";
         }
    }
    cout<<endl;

    sortirovochka(myarray, 0, num-1);
    cout<<endl;
    cout<<"Готово ^_^ : ";
    for (int i = 0; i < num; i++)
    {
        cout << myarray[i];

         if (i != num-1)
         {
             cout<<", ";
         }
         else
         {
             cout<<".";
         }
    }

    return 0;
}
