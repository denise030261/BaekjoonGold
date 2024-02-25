#include <iostream>
#include <vector>

#define MAX 987654321

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	vector<pair<int, int>> v; // 가격과 그 가격의 고객
	int person[100001] = { 0, }; // 사람에 따라 얼마나 최소의 비용이 드는 배열
	int C, N;

	cin >> C >> N;
	for (int i = 0; i < N; i++)
	{
		int cost, client;
		cin >> cost >> client;
		v.push_back(make_pair(cost, client));
	}

	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j <= 100000; j++)
		{
			if (j - v[i].first >= 0)
			{
				person[j] = max(person[j], person[j - v[i].first] + v[i].second);
			}

		}
	}

	for (int i = 1; i <= 100000; i++)
	{
		if (person[i] >= C)
		{
			cout << i;
			break;
		}
	}

}