#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define endl '\n'
#define pii pair<int, int>

typedef long long ll;

using namespace std;

#define INF 1000000000
#define MAX 35

int N, M, K, X;
vector<pii > graph[MAX];
int dist[MAX];

void solution(int start) {
  dist[start] = 0;

  priority_queue<pii, vector<pii >, greater<pii>> pq;

  pq.push(make_pair(0, start));

  while (not pq.empty()) {
    auto[curr_distance, curr] = pq.top();
    pq.pop();

    if (dist[curr] < curr_distance) continue;

    for (auto v : graph[curr]) {
      auto[distance, next] = v;
      int next_distance = curr_distance + distance;
      if (next_distance < dist[next]) {
        dist[next] = next_distance;
        pq.push(make_pair(next_distance, next));
      }
    }
  }

}

int main(int argc, const char *argv[]) {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> N >> M >> K >> X;

  for (int i = 0; i < MAX; ++i) dist[i] = INF;

  while (M--) {
    int i, j;
    cin >> i >> j;
    graph[i].push_back(make_pair(1, j));
  }

  solution(X);
  int no_answer = 1;
  for (int i = 1; i <= N; ++i) {
    if (dist[i] == K) {
      cout << i << endl;
      no_answer = 0;
    }
  }
  if (no_answer) cout << -1 << endl;
}