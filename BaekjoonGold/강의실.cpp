#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;
	
	vector<pair<int, int>> Class;
	priority_queue<int, vector<int>, greater<int>> end_time;

	for (int i = 0; i < N; i++)
	{
		int class_num;
		int start;
		int end;

		cin >> class_num >> start >> end;
		Class.push_back(make_pair(start, end));
	}

	sort(Class.begin(), Class.end());

	for (int i = 0; i < N; i++)
	{
		if (i == 0)
		{
			end_time.push(Class[i].second);
			continue;
		}

		if (end_time.top() > Class[i].first)
		{
			end_time.push(Class[i].second);
		}
		else
		{
			end_time.pop();
			end_time.push(Class[i].second);
		}
	}

	cout << end_time.size();
}