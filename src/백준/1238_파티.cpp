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

int N, M, X;
vector<pii> graph[MAX];
vector<pii> graph_inverted[MAX];
int dist[MAX];
int dist_inverted[MAX];

void clean_up() {}

void pre_proc() {
  for (int i = 1; i <= N; ++i) {
    dist[i] = INF;
    dist_inverted[i] = INF;
  }
}

void solution() {
  int start = X;
  dist[X] = 0;
  dist_inverted[X] = 0;

  priority_queue<pii> pq;
  pq.push({0, X});

  while (!pq.empty()) {
    auto [curr_dist, curr_node] = pq.top();
    pq.pop();

    if (curr_dist > dist[curr_node]) continue;
    for (auto next : graph[curr_node]) {
      auto [next_dist, next_node] = next;
      next_dist += curr_dist;
      if (next_dist < dist[next_node]) {
        dist[next_node] = next_dist;
        pq.push({next_dist, next_node});
      }
    }
  }

  pq = priority_queue<pii>();
  pq.push({0, X});

  while (!pq.empty()) {
    auto [curr_dist, curr_node] = pq.top();
    pq.pop();

    if (curr_dist > dist_inverted[curr_node]) continue;
    for (auto next : graph_inverted[curr_node]) {
      auto [next_dist, next_node] = next;
      next_dist += curr_dist;
      if (next_dist < dist_inverted[next_node]) {
        dist_inverted[next_node] = next_dist;
        pq.push({next_dist, next_node});
      }
    }
  }

  int answer = 0;
  for (int i = 1; i <= N; ++i) {
    answer = max(answer, dist[i] + dist_inverted[i]);
  }
  cout << answer << endl;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> N >> M >> X;

  clean_up();

  for (int i = 0; i < M; ++i) {
    int a, b, t;
    cin >> a >> b >> t;
    graph[a].push_back({t, b});
    graph_inverted[b].push_back({t, a});
  }
  pre_proc();
  solution();
}
