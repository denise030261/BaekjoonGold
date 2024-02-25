#include <iostream>
#include <vector>

using namespace std;

int N;
int Visited[50] = { 0, };
int ChildNode[50] = { 0, };
vector<int> Nodes(50);
vector<int> DeleteNodes;

void Dfs()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < DeleteNodes.size(); j++)
		{
			if (Nodes[i] == DeleteNodes[j] && Visited[i]==0)
			{
				DeleteNodes.push_back(i);
				Visited[i] = 1;
				ChildNode[i] = -2;
				Dfs();
			} 
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int result = 0;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> Nodes[i];
		if (Nodes[i] != -1)
			ChildNode[Nodes[i]]++;
	}

	int DeleteNode;
	cin >> DeleteNode;
	DeleteNodes.push_back(DeleteNode);
	Visited[DeleteNode] = 1;
	ChildNode[DeleteNode] = -2;
	for (int i = 0; i < N; i++)
	{
		if (Nodes[DeleteNode] == i)
			ChildNode[i]--;
	}
	
	Dfs();

	for (int i = 0; i < N; i++)
	{
		if (ChildNode[i] == 0)
			result++;
	}

	cout << result;
}