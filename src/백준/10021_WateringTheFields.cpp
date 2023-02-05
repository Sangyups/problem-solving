#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>

#define endl '\n'
#define pii pair<int, int>

typedef long long ll;

using namespace std;

#define MAX 2005
#define INF 1000000000

int N, C;
pii arr[MAX];
int dist[MAX];
int visited[MAX];
vector<int> node_list;

int get_distance(pii k1, pii k2) {
    return pow(k1.first - k2.first, 2) + pow(k1.second - k2.second, 2);
}

void solution() {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push(make_pair(0, 0));
    int ans = 0;
    while (not pq.empty()) {
        auto [curr_dist, curr_node] = pq.top();
        pq.pop();
        if (visited[curr_node]) continue;
        visited[curr_node] = 1;
        ans += curr_dist;
        node_list.push_back(curr_node);
        for (int i = 0; i < N; ++i) {
            if (i == curr_node or visited[i]) continue;
            int new_dist = get_distance(arr[curr_node], arr[i]);
            if (new_dist < C) continue;
            pq.push(make_pair(new_dist, i));
        }
    }
    if (node_list.size() < N) cout << -1;
    else cout << ans;
}

int main(int argc, const char *argv[]) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N >> C;

    for (int i = 0; i < N; ++i) {
        int x, y;
        cin >> x >> y;
        arr[i] = make_pair(x, y);
    }

    solution();
}
