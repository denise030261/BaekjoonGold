#include <iostream>
#include <algorithm>
#include<vector>
#include<queue>
#define INF 999999999

using namespace std;

int N, M, targetStart;

vector<pair<int, int> > arr[1001];
int dist[1001];

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

		if (dist[currentNode] < currentMoney) 
			continue;

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

	int N, M, targetStart, targetEnd;
	cin >> N >> M;

	int start, end, money;
	for (int i = 0; i < M; i++)
	{
		cin >> start >> end >> money;
		arr[start].push_back({ end,money });
	}

	fill(dist, dist + 1001, INF);

	cin >> targetStart >> targetEnd;

	dijkstra(targetStart);

	cout << dist[targetEnd];
}