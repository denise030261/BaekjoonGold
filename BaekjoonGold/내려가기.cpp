#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int arrMin[3] = { 0, };
	int arrMax[3] = { 0, };
	int num[3];

	int N,a,b,c;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> num[0] >> num[1] >> num[2];

		a = arrMin[0];
		b = arrMin[1];
		c = arrMin[2];

		arrMin[0] = min(a, b) + num[0];
		arrMin[2] = min(b, c) + num[2];
		arrMin[1] = min(min(a, b), c) + num[1];

		a = arrMax[0];
		b = arrMax[1];
		c = arrMax[2];

		arrMax[0] = max(a, b) + num[0];
		arrMax[2] = max(b, c) + num[2];
		arrMax[1] = max(max(a, b), c) + num[1];

	}

	cout << max(max(arrMax[0],arrMax[1]),arrMax[2]) << ' ' << min(min(arrMin[0], arrMin[1]), arrMin[2]);
}