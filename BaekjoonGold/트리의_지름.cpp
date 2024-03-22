#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
int visited[10001];
vector<pair<int, int> >node[10001];
int answer = -1, maxnode = 0;

void dfs(int current, int dist) {

    visited[current] = 1;
    if (answer < dist) {
        answer = dist;
        maxnode = current;
    }
    for (int i = 0; i < node[current].size(); i++) {
        if (visited[node[current][i].first] == 1)
            continue;
        dfs(node[current][i].first, dist + node[current][i].second);
    }
}

int main() {
    cin >> n;
    int start, end, dist;
    for (int i = 0; i < n - 1; i++) {
        cin >> start >> end >> dist;
        node[start].push_back(make_pair(end, dist));
        node[end].push_back(make_pair(start, dist));
    }
    dfs(1, 0); 
    fill(visited, visited + 10001, 0);
    answer = -1;
    dfs(maxnode, 0);
    cout << answer << endl;
}