#include <iostream>
#include <vector>
#include <queue>

int N;
int dy[4] = { 0,0,-1,1 };
int dx[4] = { 1,-1,0,0 };
int vertex[125][125];
int distances[125][125];

using namespace std;

void dijkstra()
{
	queue <pair<int, int>> q;
	q.push(make_pair(0,0));
	distances[0][0] = vertex[0][0];

	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny >= 0 && ny < N && nx >= 0 && nx < N)
			{
				if (distances[ny][nx] > distances[y][x] + vertex[ny][nx])
				{
					distances[ny][nx] = distances[y][x] + vertex[ny][nx];
					q.push(make_pair(ny, nx));
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int cost;
	int problem_number = 0;

	while (1)
	{
		problem_number++;
		cin >> N;
		if (N == 0)
			break;
		
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> vertex[i][j];
				distances[i][j] = 99999999;
			}
		}

		dijkstra();
		cout << "Problem " << problem_number << ": " << distances[N-1][N-1] << '\n';
	}
}