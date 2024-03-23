#include <iostream>
#include <algorithm>

using namespace std;

int R, C; // 세로 R, 가로 C
int dx[4] = {-1,1,0,0};
int dy[4] = { 0,0,-1,1 };
bool visited[26] = { 0, };
char arr[20][20];
int answer = 0;

void dfs(int x,int y, int dist)
{
	visited[arr[y][x] - 'A'] = true;
	dist++;
	answer = max(dist, answer);

	for (int i = 0; i < 4; i++)
	{
		int next_x = x + dx[i];
		int next_y = y + dy[i];
		if ((next_x >= 0 && next_x < C) && (next_y >= 0 && next_y < R))
		{
			if (!visited[arr[next_y][next_x] - 'A'])
			{
				dfs(next_x, next_y, dist);
				visited[arr[next_y][next_x] - 'A'] = false;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> R >> C;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> arr[i][j];
		}
	}

	dfs(0, 0, 0);

	cout << answer;
}