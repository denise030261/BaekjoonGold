#include <iostream>

using namespace std;

int N, method, answer;
int arr[17][17];
bool visited[17][17] = { 0, };

void dfs(int x, int y, int cur_method)
{
	visited[x][y] = true;
	if (x == N && y == N)
	{
		answer++;
		return;
	}

	if (cur_method == 2)
	{
		if (y + 1 <= N && arr[x][y + 1] == 0 && !visited[x][y + 1])
		{
			dfs(x, y + 1, 0);
			visited[x][y + 1] = false;
		}
		if (x + 1 <= N && arr[x + 1][y] == 0 && !visited[x + 1][y])
		{
			dfs(x + 1, y, 1);
			visited[x + 1][y] = false;
		}
		if (y + 1 <= N && arr[x][y + 1] == 0 && !visited[x][y + 1])
		{
			if (x + 1 <= N && arr[x + 1][y] == 0 && !visited[x + 1][y])
			{
				if (arr[x + 1][y + 1] == 0 && !visited[x + 1][y + 1])
				{
					dfs(x + 1, y + 1, 2);
					visited[x + 1][y + 1] = false;
				}
			}
		}
	}
	else if (cur_method == 1)
	{
		if (x + 1 <= N && arr[x + 1][y] == 0 && !visited[x + 1][y])
		{
			dfs(x + 1, y, 1);
			visited[x + 1][y] = false;
		}
		if (y + 1 <= N && arr[x][y + 1] == 0 && !visited[x][y + 1])
		{
			if (x + 1 <= N && arr[x + 1][y] == 0 && !visited[x + 1][y])
			{
				if (arr[x + 1][y + 1] == 0 && !visited[x + 1][y + 1])
				{
					dfs(x + 1, y + 1, 2);
					visited[x + 1][y + 1] = false;
				}
			}
		}
	}
	else if (cur_method == 0)
	{

		if (y + 1 <= N && arr[x][y + 1] == 0 && !visited[x][y + 1])
		{
			dfs(x, y + 1, 0);
			visited[x][y + 1] = false;
		}
		if (y + 1 <= N && arr[x][y + 1] == 0 && !visited[x][y + 1])
		{
			if (x + 1 <= N && arr[x + 1][y] == 0 && !visited[x + 1][y])
			{
				if (arr[x + 1][y + 1] == 0 && !visited[x + 1][y + 1])
				{
					dfs(x + 1, y + 1, 2);
					visited[x + 1][y + 1] = false;
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> arr[i][j];
		}
	}
	answer = 0;

	dfs(1, 2, 0);

	cout << answer;
}