#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
#include <map>

using namespace std;

struct Begin
{
	char ch;
	int freq;
	Begin* left, * right;
};

Begin* getBegin(char ch, int freq, Begin* left, Begin* right)
{
	Begin* node = new Begin();
	node->ch = ch;
	node->freq = freq;
	node->left = left;
	node->right = right;
	return node;
}

struct PC
{
	bool operator()(Begin* l, Begin* r)
	{
		return l->freq > r->freq;
	}
};

void encode(Begin* root, string str, unordered_map<char, string>& Half)
{
	if (root == nullptr)
    {
        return;
    }

	if (!root->left && !root->right)
    {
		Half[root->ch] = str;
	}

	encode(root->left, str + "0", Half);
	encode(root->right, str + "1", Half);
}

void decode(Begin* root, int& index, string str)
{
	if (root == nullptr)
    {
		return;
	}

	if (!root->left && !root->right)
    {
		cout << root->ch;
		return;
	}

	index++;
	if (str[index] == '0')
    {
        decode(root->left, index, str);
    }
	else
    {
        decode(root->right, index, str);
    }

}

void Build(string text)
{
	unordered_map<char, int> freq;

	for (char ch : text)
    {
		freq[ch]++;
	}

	priority_queue<Begin*, vector<Begin*>, PC> pq;

	for (auto pair : freq)
    {
		pq.push(getBegin(pair.first, pair.second, nullptr, nullptr));
	}

	while (pq.size() != 1)
    {
		Begin* left = pq.top(); pq.pop();
		Begin* right = pq.top();	pq.pop();
		int sum = left->freq + right->freq;
		pq.push(getBegin('\0', sum, left, right));
	}

	Begin* root = pq.top();
	unordered_map<char, string> Half;
	encode(root, "", Half);

    cout<<endl;
	cout << "CoDe:" << endl;

	for (auto pair : Half)
	{
		cout << pair.first << " = " << pair.second << endl;
	}

    cout<<endl;
	cout << "Изначальная строка: " << text << endl;

	string str = " ";
	for (char ch : text)
    {
		str += Half[ch];
	}

    cout<<endl;
	cout << "Цифры:" << str << endl << endl;

    int index = -1;
	while (index < (int)str.size() - 2)
    {
		decode(root, index,str);
	}
}

int main()
{
	setlocale(0,"");

	string text = "пупкин василий кириллович";
	cout << text << endl;
	map<char, int> charCount;

	for (unsigned int i = 0; i < text.size(); i++)
    {
        charCount[text[i]]++;
    }

    cout<<endl;
	cout<<"Кол-во раз встреченных символов:"<<endl;

	for (map<char, int>::iterator it = charCount.begin(); it != charCount.end(); ++it)
    {
        cout << it->first << " = " << it->second << "  ";
        cout<<endl;
    }

    cout<<endl;
	Build(text);

	return 0;
}
