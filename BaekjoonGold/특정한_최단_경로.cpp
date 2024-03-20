#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#define INF 99999999

using namespace std;

vector<pair<int, int>> arr[801];
int dist[801];

void dijkstra(int dijStart)
{
	priority_queue<pair<int, int>>pq;
	pq.push({ 0,dijStart });

	dist[dijStart] = 0;

	while (!pq.empty())
	{
		int currentMoney = pq.top().first;
		int currentNode = pq.top().second;
		pq.pop();

		for (int i = 0; i < arr[currentNode].size(); i++)
		{
			int cost = currentMoney + arr[currentNode][i].second;

			if (cost < dist[arr[currentNode][i].first])
			{
				dist[arr[currentNode][i].first] = cost;
				pq.push(make_pair(cost, arr[currentNode][i].first));
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, E, first, second, point, u, v;
	cin >> N >> E;

	for (int i = 0; i < E; i++)
	{
		cin >> first >> second >> point;

		arr[first].push_back({ second,point });
		arr[second].push_back({ first,point });
	}
	cin >> u >> v;

	fill(dist, dist + 801, INF);
	dijkstra(1);
	int dijStart1 = dist[u];
	int dijStart2 = dist[v];

	fill(dist, dist + 801, INF);
	dijkstra(u);
	int middle = dist[v];
	int dijEndU = dist[N];

	fill(dist, dist + 801, INF);
	dijkstra(v);
	int dijEndV = dist[N];


	int answer = min(middle + dijStart1 + dijEndV, middle + dijStart2 + dijEndU);

	if (answer >= INF)
	{
		cout << -1;
		return 0;
	}

	cout << answer;
}
