#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

#define endl '\n'
#define pii pair<int, int>

typedef long long ll;

using namespace std;

#define MAX 5005
#define INF 1987654321

int N, Q;

vector<pii> graph[MAX];
int visited[MAX];

void solution(int k, int start) {
    queue<pii> q;
    visited[start] = 1987654321;
    q.push(make_pair(start, visited[start]));
    while (not q.empty()) {
        auto [curr_node, curr_dist] = q.front();
        q.pop();
        for (auto g : graph[curr_node]) {
            auto [next_node, next_dist] = g;
            if (visited[next_node]) continue;
            next_dist = min(curr_dist, next_dist);
            visited[next_node] = next_dist;
            q.push(make_pair(next_node, next_dist));
        }
    }
    int ans = 0;
    for (int i = 1; i <= N; ++i) {
        cout << visited[i] << ' ';
        if (visited[i] >= k and i != start) ans++;
    }
    cout << endl;
    cout << ans << endl;
}

int main(int argc, const char *argv[]) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N >> Q;

    for (int i = 1; i < N; ++i) {
        int x, y, d;
        cin >> x >> y >> d;
        graph[x].push_back(make_pair(y, d));
        graph[y].push_back(make_pair(x, d));
    }
    while (Q--) {
        int k, v;
        cin >> k >> v;
        solution(k, v);
        memset(visited, 0, sizeof(visited));
    }
}
