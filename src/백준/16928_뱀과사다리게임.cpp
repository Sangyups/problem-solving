#include <bits/stdc++.h>

#define endl '\n'
#define pii pair<int, int>

typedef long long ll;

using namespace std;

const int MAX = 105;

int N, M;
int special[MAX];
int visited[MAX];

void clean_up() {}

void pre_proc() {}

void solution() {
  queue<int> q;
  q.push(1);

  while (!q.empty()) {
    int curr = q.front();
    q.pop();
    for (int i = 1; i <= 6; ++i) {
      int next = curr + i;
      if (special[next]) next = special[next];
      if (next > 100) continue;
      if (visited[next]) continue;

      q.push(next);
      visited[next] = visited[curr] + 1;
    }
  }

  cout << visited[100] << endl;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> N >> M;

  for (int i = 0; i < N + M; ++i) {
    int x, y;
    cin >> x >> y;
    special[x] = y;
  }

  clean_up();
  pre_proc();
  solution();
}
