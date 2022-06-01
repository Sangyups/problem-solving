#include <iostream>
#include <vector>
#include <algorithm>

#define endl '\n'
#define pii pair<int, int>

typedef long long ll;

using namespace std;

#define MAX 101

int N, M;
int graph[MAX][MAX];
int dist[MAX][MAX];

void solution() {
  int mn = 1987654321;
  int ans;

  for (int k = 1; k <= N; ++k)
    for (int i = 1; i <= N; ++i)
      for (int j = 1; j <= N; ++j)
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

  for (int i = 1; i <= N; ++i) {
    int cnt = 0;
    for (int j = 1; j <= N; ++j) {
      cnt += dist[i][j];
    }
    if (mn > cnt) {
      mn = cnt;
      ans = i;
    }
  }

  cout << ans;
}

int main(int argc, const char *argv[]) {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> N >> M;

  for (int i = 0; i < M; ++i) {
    int x, y;
    cin >> x >> y;
    graph[x][y] = 1;
    graph[y][x] = 1;
  }

  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= N; ++j) {
      if (i == j) dist[i][j] = 0;
      else if (graph[i][j]) dist[i][j] = graph[i][j];
      else dist[i][j] = 100000;
    }
  }

  solution();
}
