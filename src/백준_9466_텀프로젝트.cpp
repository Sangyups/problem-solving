#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

#define endl '\n'
#define pii pair<int, int>

typedef long long ll;

using namespace std;

#define MAX 100001

int students[MAX];
int visited[MAX];
int finished[MAX];
int order, cnt;
int T, N;

void dfs(int curr) {
  int next = students[curr];

  if (!visited[next]) {
    visited[next] = ++order;
    dfs(next);
  } else if (!finished[next]) {
    cnt += visited[curr] - visited[next] + 1;
  }
  finished[curr] = 1;
}

void solution() {
  for (int i = 1; i <= N; i++) {
    if (visited[i]) continue;
    dfs(i);
  }

  cout << N - cnt << endl;
}

int main(int argc, const char *argv[]) {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> T;

  for (int t = 0; t < T; t++) {
    memset(students, 0, sizeof(students));
    memset(visited, 0, sizeof(visited));
    memset(finished, 0, sizeof(finished));
    order = 0;
    cnt = 0;
    cin >> N;
    for (int i = 1; i <= N; i++) {
      cin >> students[i];
    }
    solution();
  }
}