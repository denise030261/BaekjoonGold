#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int start, target,location,second;
	int answer=9999999;
	bool visited[100001] = {0,};
	queue<pair<int, int>> q;

	cin >> start >> target;

	q.push(pair<int, int>(start, 0));

	while (!q.empty())
	{
		location = q.front().first;
		second = q.front().second;
		q.pop();
		visited[location] = true;

		if (location==target)
		{
			answer = min(second,answer);
		}
		if (location * 2 < 100001)
		{
			if(!visited[location * 2])
				q.push(pair<int, int>(location * 2, second));
		}
		if (location + 1 < 100001)
		{
			if(!visited[location + 1])
				q.push(pair<int, int>(location + 1, second + 1));
		}
		if (location - 1 >= 0)
		{
			if(!visited[location - 1])
				q.push(pair<int, int>(location - 1, second + 1));
		}
	}

	cout << answer;
}