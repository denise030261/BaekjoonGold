#include <iostream>

using namespace std;

int N, M;
int moveX[4] = { 0,0,-1,1 };
int moveY[4] = { -1,1,0,0 };
int arr[501][501];
bool visited[501][501];
int answer = 0;
int preanswer = 0;
int roote = 0;

void dfs(int x,int y)
{
	visited[x][y] = true;
	roote++;
	preanswer+=arr[x][y];

	if (roote == 4)
	{
		if (preanswer > answer)
		{
			answer = preanswer;
		}
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int dx = x + moveX[i];
		int dy = y + moveY[i];

		if (dx > 0 &&dx <= N && dy > 0 && dy<=M)
		{
			if (!visited[dx][dy])
			{
				dfs(dx, dy);
				visited[dx][dy] = false;
				roote--;
				preanswer -= arr[dx][dy];
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> arr[i][j];
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (!visited[i][j])
			{
				dfs(i, j);
				visited[i][j] = false;
				roote--;
				preanswer -= arr[i][j];
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			roote = 0;
			preanswer = 0;

			if (!((i == 1 && j == 1) || (i == 1 && j == M)) || (i == N && j == 1) || (i == N && j == M))
			{
				int Min = 999;
				preanswer += arr[i][j];
				roote++;

				for (int k = 0; k < 4; k++)
				{
					int dx = i + moveX[k];
					int dy = j + moveY[k];

					if (dx > 0 && dx <= N && dy > 0 && dy <= M)
					{
						if (Min > arr[dx][dy])
							Min = arr[dx][dy];

						preanswer += arr[dx][dy];
						roote++;
					}
				}

				if (roote == 5)
				{
					preanswer -= Min;
				}

				if (answer < preanswer)
					answer = preanswer;
			}
		}
	}
	
	cout << answer;
}