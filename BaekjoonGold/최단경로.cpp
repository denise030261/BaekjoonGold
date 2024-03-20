#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <queue>
#define INF 98765432

using namespace std;

int dist[20001];
vector<pair<int, int>> v[30001];

void dijkstra(int dijStart)
{
	priority_queue< pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> >> pq;
	dist[dijStart] = 0;
	pq.push({ 0,dijStart });

	while (!pq.empty())
	{
		int curStart = pq.top().second;
		int curDist = pq.top().first;
		pq.pop();

		if (dist[curStart] < curDist)
			continue;

		for (int i = 0; i < v[curStart].size(); i++)
		{
			if (dist[v[curStart][i].first] > curDist + v[curStart][i].second)
			{
				dist[v[curStart][i].first] = curDist + v[curStart][i].second;
				pq.push({ dist[v[curStart][i].first] ,v[curStart][i].first });
			}
		}
	}
}

int main()
{
	int V, E, Start;
	scanf("%d %d", &V, &E);
	scanf("%d", &Start);

	int start, end, distance;
	for (int i = 0; i < E; i++)
	{
		scanf("%d %d %d", &start, &end,&distance);
		v[start].push_back({ end,distance });

		if (V < i)
		{
			continue;
		}
		else
		{
			dist[i] = INF;
		}
	}

	for (int i = E; i <= V; i++)
	{
		dist[i] = INF;
	}

	dijkstra(Start);

	for (int i = 1; i <= V; i++)
	{
		if (dist[i] == INF)
			printf("INF\n");
		else
			printf("%d\n", dist[i]);
	}
}