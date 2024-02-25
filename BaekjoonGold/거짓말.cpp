#include <iostream>
#include <vector>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, M, true_person, num;
	vector<int> known_person;
	int known_check[51] = { 0, };
	int party_check[51] = { 0, };
	bool change = true;

	cin >> N >> M;
	cin >> true_person;
	vector<vector<int>> person_party(N + 1);
	vector<vector<int>> party_person(M + 1);

	for (int i = 0; i < true_person; i++)
	{
		cin >> num;
		known_person.push_back(num);
	}

	int person_num, person;
	for (int i = 0; i < M; i++)
	{
		cin >> person_num;
		for (int j = 0; j < person_num; j++)
		{
			cin >> person;
			person_party[person].push_back(i + 1);
			party_person[i + 1].push_back(person);
		}
	}

	vector<int> party;
	while (change)
	{
		change = false;
		while (!known_person.empty())
		{
			if (known_check[known_person.back()] == 0)
			{
				for (int i = 0; i < person_party[known_person.back()].size(); i++)
					party.push_back(person_party[known_person.back()][i]);
				known_check[known_person.back()] = 1;
			}
			known_person.pop_back();
		}

		while (!party.empty())
		{
			for (int i = 0; i < party_person[party.back()].size(); i++)
			{
				if (known_check[party_person[party.back()][i]] == 0)
				{
					known_person.push_back(party_person[party.back()][i]);
					change = true;
				}

				if (party_check[party.back()] == 0)
					party_check[party.back()] = 1;
			}
			party.pop_back();
		}
	}

	int sub = 0;
	for (int i = 1; i <= M; i++)
	{
		if (party_check[i] == 1)
			sub++;
	}
	cout << M - sub;
}