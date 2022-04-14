#include <iostream>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;


int main()
{
	setlocale(0,"");

	vector<int> num1;
	vector<int> num2;
	vector<int> res;
	string N1("85238567246576530658126356327563265095636150365216503796517235636525");
	string N2("464265364423565372136735723757352574");

	for(int i = 0; i<N1.size();i++)
    {
		int grif = (int)(N1[i] -'0');
		num1.push_back(grif);
	}

	for(int i = 0; i<N2.size();i++)
	{
		int grif = (int)(N2[i] -'0');
		num2.push_back(grif);
	}

	long size = 0;

	if(num1.size()>num2.size())
	{
		size = num1.size();
	}
	else
	{
	    size = num2.size();
    }

	for(int i = size/2; i>=0;i--)
    {
		int grif = 0;
		res.push_back(grif);
	}

	for(int i = 0; i<N1.size();i++)
    {
		int grif = (int)(N1[i] -'0');
		res.push_back(grif);
	}
	for(int i = 0; i<N2.size();i++)
	{
		int T1,T2;
		T1 = res[res.size()-i-1];
		T2 = N2[N2.size()-i-1];
		res[res.size()-1-i] = (int)T1+T2-'0';
	}
	for(int i = 0; i<res.size();i++)
	{
		for(int j = 0; j<res.size();j++)
		{
			if(res[j]>9)
			{
				res[j] = res[j] -10;
				res[j-1]++;
			}
		}
	}

	int first = res.size();

	for(int i = 0; i<res.size();i++)
	{
		if(res[i] !=0 )
        {
			first = i;
			break;
		}
	}

	cout<<"1-е число: ";

	for(int i = 0; i<N1.size();i++)
	{

		cout<<N1[i]<<" ";
	}

	cout<<endl<<endl;
	cout<<"2-е число: ";

	for(int i = 0; i<N2.size();i++)
	{

		cout<<N2[i]<<" ";
	}

	cout<<endl<<endl;
	cout<<"Результат: ";

	for(int i = first; i<res.size();i++)
    {

		cout<<res[i]<<" ";
	}

	cout<<endl;

	return 0;
}
