#include <iostream>

using namespace std;

int MRT(int p[], int i, int j)
{
	if (i == j)
    {
 		return 0;
    }

	int f;
	int mini = INT_MAX;
	int county;

	for (f = i; f < j; f++)
	{
		county = MRT(p, i, f) + MRT(p, f + 1, j) + p[i - 1] * p[f] * p[j];

		if (county < mini)
        {
			mini = county;
        }

	}

	return mini;
}

int main()
{
	setlocale(0, "");

	int arr[] = { 5,10,3,12,5 };
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << "Âîçâðàùàåò êîëè÷åñòâî ýëåìåíòîâ â êîíòåéíåðå >>> "<< MRT(arr, 1, n - 1);

	return 0;
}
