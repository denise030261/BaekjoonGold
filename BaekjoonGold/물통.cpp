#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int A, B, C;
	bool visite[201][201][201] = { 0, };
	vector<int> num;
	queue<pair<pair<int,int>,int>> store;
	cin >> A >> B >> C;

	store.push(make_pair(make_pair(0, 0), C));
	
	while (!store.empty())
	{
		int a = store.front().first.first;
		int b = store.front().first.second;
		int c = store.front().second;
		store.pop();

		if (visite[a][b][c] == true)
			continue;
		visite[a][b][c] = true;

		if (a == 0)
			num.push_back(c);

		if (a + b > B) // A -> B
			store.push(make_pair(make_pair(a + b - B, B), c));
		else
			store.push(make_pair(make_pair(0, a + b), c));

		if (a + c > C) // A -> C
			store.push(make_pair(make_pair(a + c - C, b), C));
		else
			store.push(make_pair(make_pair(0, b), a + c));

		if (b + a > A) // B -> A
			store.push(make_pair(make_pair(A, b + a - A), c));
		else
			store.push(make_pair(make_pair(b + a, 0), c));

		if (a + c > A) // C -> A
			store.push(make_pair(make_pair(A, b), c + a - A));
		else
			store.push(make_pair(make_pair(a + c, b), 0));

		if (c + b > B) // C -> B
			store.push(make_pair(make_pair(a, B), b + c - B));
		else
			store.push(make_pair(make_pair(a, c + b), 0));

		if (c + b > C) // B -> C
			store.push(make_pair(make_pair(a, b + c - C), C));
		else
			store.push(make_pair(make_pair(a, 0), c + b));
	}

	sort(num.begin(), num.end());

	for (int i = 0; i < num.size(); i++)
		cout << num[i] << ' ';
}