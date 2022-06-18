#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define endl '\n'
#define pii pair<int, int>

typedef long long ll;

using namespace std;

#define MAX 1005

int N, P, K;
int dist[MAX];
int MAX_DIST;
int ans;
vector<pii > graph[MAX];

void preproc() {
}

int dijkstra(int min_cost) {
  fill(dist, dist + MAX, 1987654321);
  priority_queue<pii, vector<pii >, greater<pii > > pq;
  pq.push(make_pair(0, 1));
  dist[1] = 0;
  while (not pq.empty()) {
    auto[curr_dist, curr_node] = pq.top();
    pq.pop();
    if (curr_dist > dist[curr_node]) continue;
    for (int i = 0; i < graph[curr_node].size(); ++i) {
      auto[next_dist, next_node] = graph[curr_node][i];
      int new_dist = curr_dist + (next_dist > min_cost);
      if (new_dist < dist[next_node]) {
        dist[next_node] = new_dist;
        pq.push(make_pair(new_dist, next_node));
      }
    }
  }
  return dist[N] <= K;
}

void solution() {
  int start = 0, end = MAX_DIST;
  ans = 1987654321;
  while (start <= end) {
    int mid = (start + end) / 2;
    if (dijkstra(mid)) {
      end = mid - 1;
      ans = mid;
    } else {
      start = mid + 1;
    }
  }
  cout << (ans == 1987654321 ? -1 : ans);
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  preproc();

  cin >> N >> P >> K;

  for (int i = 0; i < P; ++i) {
    int a, b, distance;
    cin >> a >> b >> distance;
    MAX_DIST = max(MAX_DIST, distance);
    graph[a].push_back(make_pair(distance, b));
    graph[b].push_back(make_pair(distance, a));
  }
  solution();
}
