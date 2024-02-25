#include <iostream>
#include <vector>

using namespace std;
string str;
int N, B, W;
int white_num;
int black_num;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int result = 0;
	vector<int> store;
	cin >> N >> B >> W;
	cin >> str;

	for (int i = 0; i < str.length(); i++)
		if (str[i] == 'B')
			store.push_back(i);

	for (int i = 0; i < store.size()-N+1; i++)
	{
		for (int j = i + N-1; j < store.size(); j++)
		{

		}
	}
}