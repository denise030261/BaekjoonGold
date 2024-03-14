#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int N, M;
int answer = 9999999;

vector<pair<int, int>> house;
vector<pair<int, int>> chicken;
vector<pair<int, int>> location;

bool visited[13] = { 0, };

int calculate(pair<int, int> a, pair<int, int> b)
{
	return abs(a.first - b.first) + abs(a.second - b.second);
}

void location_position(int order, int length)
{
	if (length == M)
	{
		int result = 0;
		for (int i = 0; i < house.size(); i++)
		{
			int minNum = 9999999;
			for (int j = 0; j < location.size(); j++)
			{
				minNum = min(minNum, calculate(location[j], house[i]));
			}
			result += minNum;
		}

		answer = min(answer, result);
		return;
	}

	for (int i = order; i < chicken.size(); i++)
	{
		if (visited[i] == true)
			continue;

		visited[i] = true;
		location.push_back(make_pair(chicken[i].first, chicken[i].second));
		location_position(i, length + 1);
		visited[i] = false;
		location.pop_back();
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	int num;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> num;

			if (num == 1)
			{
				house.push_back(make_pair(i + 1, j + 1));
			}
			else if (num == 2)
			{
				chicken.push_back(make_pair(i + 1, j + 1));
			}
		}
	}

	location_position(0, 0);

	cout << answer;
}