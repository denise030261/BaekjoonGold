#include <iostream>

using namespace std;

char arr[3072][6144];

void dfs(int x, int y, int n)
{
	if (n == 3)
	{
		arr[x][y] = '*';
		arr[x + 1][y - 1] = '*';
		arr[x + 1][y + 1] = '*';
		for (int i = y - 2; i <= y + 2; i++)
		{
			arr[x + 2][i] = '*';
		}

		return;
	}

	dfs(x, y, n / 2);
	dfs(x + n / 2, y - n / 2, n / 2);
	dfs(x + n / 2, y + n / 2, n / 2);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 2 * N; j++)
		{
			arr[i][j] = ' ';
		}
	}

	dfs(0, N - 1, N);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 2 * N-1; j++)
		{
			cout << arr[i][j];
		}
		cout << '\n';
	}
}