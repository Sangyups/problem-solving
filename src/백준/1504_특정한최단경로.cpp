#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

#define endl '\n'
#define pii pair<int, int>

typedef long long ll;

using namespace std;

const int MAX = 805;
const int INF = 1e9 + 5;

int N, E;
int v1, v2;
vector<pii> adj[MAX];
int dist[MAX];

void clean_up() {}

void pre_proc() {}

int dijkstra(int start, int end) {
  for (int i = 1; i <= N; ++i) {
    dist[i] = INF;
  }
  dist[start] = 0;
  priority_queue<pii, vector<pii>, greater<pii>> pq;

  pq.push({0, start});

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
  return dist[end];
}

void solution() {
  ll temp1 = 0;
  for (int i = 0; i < 1; ++i) {
    int temp;

    temp = dijkstra(1, v1);
    if (temp != INF)
      temp1 += temp;
    else {
      temp1 = -1;
      break;
    }

    temp = dijkstra(v1, v2);
    if (temp != INF)
      temp1 += temp;
    else {
      temp1 = -1;
      break;
    }

    temp = dijkstra(v2, N);
    if (temp != INF)
      temp1 += temp;
    else {
      temp1 = -1;
      break;
    }
  }

  ll temp2 = 0;
  for (int i = 0; i < 1; ++i) {
    int temp;

    temp = dijkstra(1, v2);
    if (temp != INF)
      temp2 += temp;
    else {
      temp2 = -1;
      break;
    }

    temp = dijkstra(v2, v1);
    if (temp != INF)
      temp2 += temp;
    else {
      temp2 = -1;
      break;
    }

    temp = dijkstra(v1, N);
    if (temp != INF)
      temp2 += temp;
    else {
      temp2 = -1;
      break;
    }
  }

  ll answer;

  if (temp1 == -1 && temp2 == -1)
    answer = -1;
  else if (temp1 == -1)
    answer = temp2;
  else if (temp2 == -1)
    answer = temp1;
  else
    answer = min(temp1, temp2);

  cout << answer << endl;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> N >> E;

  clean_up();

  for (int i = 0; i < E; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    adj[a].push_back({c, b});
    adj[b].push_back({c, a});
  }
  cin >> v1 >> v2;

  pre_proc();
  solution();
}
