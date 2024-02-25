#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<char> str;
vector<char> Alphabet;
int L, C;

void dfs(int Depth,int Gather,int Consonant)
{
	if (str.size() == L)
	{
		if (Gather >= 1 && Consonant >= 2)
		{
			for (int i = 0; i < str.size(); i++)
				cout << str[i];
			cout << '\n';
		}
		return;
	}
	for (int i = Depth; i < C; i++)
	{
		str.push_back(Alphabet[i]);
		if (Alphabet[i] == 'a' || Alphabet[i] == 'e' || Alphabet[i] == 'i' || Alphabet[i] == 'o' || Alphabet[i] == 'u')
			Gather++;
		else
			Consonant++;
		dfs(i + 1, Gather,Consonant);
		str.pop_back();
		if (Alphabet[i] == 'a' || Alphabet[i] == 'e' || Alphabet[i] == 'i' || Alphabet[i] == 'o' || Alphabet[i] == 'u')
			Gather--;
		else
			Consonant--;
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int Gather = 0; //모음
	int Consonant = 0; //자음
	cin >> L >> C;

	for (int i = 0; i < C; i++)
	{
		char alp;
		cin >> alp;
		Alphabet.push_back(alp);
	} 

	sort(Alphabet.begin(), Alphabet.end());

	dfs(0,Gather,Consonant);
}