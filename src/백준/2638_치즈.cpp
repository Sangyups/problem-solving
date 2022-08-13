#include <bits/stdc++.h>

#define endl '\n'
#define pii pair<int, int>

typedef long long ll;

using namespace std;

const int MAX = 105;

int N, M;
int cheese[MAX][MAX];
int visited[MAX][MAX];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void clean_up() {
}

void pre_proc() {
}

void solution() {
  int time = 0;
  int is_changed;
  do {
    is_changed = 0;
    queue<pii> q;
    fill(&visited[0][0], &visited[N - 1][M], 0);
    q.push({0, 0});
    visited[0][0] = 1;
    while (!q.empty()) {
      auto [cx, cy] = q.front();
      q.pop();
      for (int i = 0; i < 4; ++i) {
        int nx = cx + dx[i];
        int ny = cy + dy[i];
        if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
        if (cheese[nx][ny]) {
          ++visited[nx][ny];
          if (visited[nx][ny] == 2) {
            cheese[nx][ny] = 0;
            is_changed = 1;
          }
          continue;
        }
        if (visited[nx][ny]) continue;
        visited[nx][ny] = 1;
        q.push({nx, ny});
      }
    }
    ++time;
  } while (is_changed);
  cout << time - 1 << endl;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> N >> M;

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      cin >> cheese[i][j];
    }
  }
  clean_up();
  pre_proc();
  solution();
}
