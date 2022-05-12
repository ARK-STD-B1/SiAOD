#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>

using namespace std;

int pos(const char* s, const char* p, int n)
{
	int i, j;
	int Dex, Sin;

	for (Dex = 0; p[Dex]; Dex++);
	for (Sin = 0; s[Sin]; Sin++);

	for (i = 0; i <= Sin - Dex; i++){
		for (j = 0; s[i + j] == p[j]; j++);
		if (j - Dex == 1 && i == Sin - Dex && !(n - 1)) return i;
		if (j == Dex)
			if (n - 1) n--;
			else return i;
	}

	return -1;
}
int main()
{
	setlocale(0, "");

	char x[30];char y[33];
	int N, k, g;
	int ar[30];

	string line, a;
	ifstream f("C://Users//Admin//OneDrive//Рабочий стол//TEXT.txt");
	cout << "код ASCII: \n";

	k = 0;

	while (f >> N)
    {
		ar[k++] = N;
	}

	for (int i = 0; i < k; i++)
	{
		cout << ar[i] << " ";
	}

	f.close();

	cout << endl;
	cout << "Перевод: \n";

	for (int i = 0; i < 30; i++)
    {
		y[i] = ar[i];
		cout << y[i] << "";
	}

	cout << endl;

	ofstream out("C://DUST.txt", ios::binary | ios::out);
	out.write((char*)&y, sizeof y);
	out.close();

	ifstream in("C://Users//Admin//OneDrive//Рабочий стол//TEXT_bi.txt", ios::binary | ios::in);
	in.read((char*)&x, sizeof x);

	in.close();

	cout << "Файловые данные:\n";
	cout << x << endl;
	cout << "Номерок для поиска: \n";
	cin >> a;

	const char* s = x;
	const char* p = a.c_str();
	int i, n = 0;

	for (i = 1; n != -1; i++)
    {
		n = pos(s, p, i);

		if (n >= 0)
			cout << n << endl;
	}

	cout << "После дезентеграции:\n ";

	for (int i = 0; i <= 5; i++)
    {
		for (int j = 0; j < 30; ++j)
        {
			x[j] = x[j + 1];
		}
	}

	for (int i = 0; i <= 30; i++)
    {
		cout << x[i] << "";
	}

	return 0;
}
