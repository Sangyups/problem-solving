#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

#define endl '\n'
#define pii pair<int, int>

typedef long long ll;

using namespace std;

const int MAX = 1005;
const int INF = 1e9 + 5;

int N, M;
int s, e;

vector<pii> adj[MAX];
int dist[MAX];

void clean_up() {}

void pre_proc() {}

void solution() {
  for (int i = 1; i <= N; ++i) {
    dist[i] = INF;
  }
  dist[s] = 0;
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  pq.push({0, s});
  while (!pq.empty()) {
    auto [curr_dist, curr_node] = pq.top();
    pq.pop();
    if (curr_dist > dist[curr_node]) continue;
    for (auto next : adj[curr_node]) {
      auto [next_dist, next_node] = next;
      next_dist += curr_dist;
      if (next_dist < dist[next_node]) {
        dist[next_node] = next_dist;
        pq.push({next_dist, next_node});
      }
    }
  }

  cout << dist[e] << endl;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> N >> M;
  clean_up();

  for (int i = 0; i < M; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    adj[a].push_back({c, b});
  }

  cin >> s >> e;

  pre_proc();
  solution();
}
