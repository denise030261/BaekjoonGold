#include <iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>

using namespace std;

vector<pair<int, int>> v;
int d[100001];
int main() {
	int c, n;
	cin >> c >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}
	for (int i = 0; i < v.size(); i++)
	{
		for (int k = 1; k <= 100001; k++)
		{
			if (k - v[i].first >= 0)
				d[k] = max(d[k], d[k - v[i].first] + v[i].second);
		}

	}
	for (int i = 1; i <= 100001; i++)
	{
		if (d[i] >= c)
		{
			cout << i;
			break;
		}
	}
}
