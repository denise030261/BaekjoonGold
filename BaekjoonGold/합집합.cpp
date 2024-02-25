#include <iostream>
#include <vector>

using namespace std;
long long int num[5000001] = { 0, };

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		long long int x, y;
		cin >> x >> y;
		num[x / 2] = max(num[x / 2], y / 2);
	}
	
	long long int result = 0;
	long long int maxSide = 0;
	for (int i = 5000000; i > 0; i--)
	{
		maxSide = max(maxSide, num[i]);
		result += maxSide;
	}

	cout << result * 4;
}