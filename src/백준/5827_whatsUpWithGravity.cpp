#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define endl '\n'
#define pii pair<int, int>

typedef long long ll;

using namespace std;

#define MAX 505

int N, M;
char grid[MAX][MAX];
int visited[MAX][MAX][2];
pii start, goal;
int dy[3] = {-1, 1, 0};

void preproc() {
}

pii follow_gravity(int reversed_gravity, pii coord) {
  auto[cx, cy] = coord;
  if (coord == goal) return goal;
  if (reversed_gravity) {
    while (grid[cx - 1][cy] != '#' and cx > 0) {
      if (grid[cx - 1][cy] == 'D') return goal;
      cx--;
    }
    if (cx == 0) return {-1, -1};
  } else {
    while (grid[cx + 1][cy] != '#' and cx < N - 1) {
      if (grid[cx + 1][cy] == 'D') return goal;
      cx++;
    }
    if (cx == N - 1) return {-1, -1};
  }
  return {cx, cy};
}

void solution() {
  pii new_start = follow_gravity(0, start);
  if (new_start.first == -1) {
    cout << -1 << endl;
    return;
  }
  if (new_start == goal) {
    cout << 0 << endl;
    return;
  }
  fill(&visited[0][0][0], &visited[MAX - 1][MAX - 1][2], 1987654321);
  priority_queue<pair<int, pii >, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;
  pq.push({0, new_start});
  visited[new_start.first][new_start.second][0] = 0;

  while (not pq.empty()) {
    auto[g_cnt, coord] = pq.top();
    pq.pop();
    auto[cx, cy] = coord;
    if (visited[cx][cy][g_cnt & 1] < g_cnt) continue;
    if (coord == goal) {
      cout << g_cnt << endl;
      return;
    }
    for (int i = 0; i < 3; ++i) {
      int nx = cx;
      int ny = cy + dy[i];
      if (i == 2) g_cnt++;
      if (ny < 0 or ny >= M or grid[nx][ny] == '#') continue;
      pii temp = follow_gravity(g_cnt & 1, {nx, ny});
      if (temp.first == -1) continue;
      nx = temp.first;
      ny = temp.second;
      if (visited[nx][ny][g_cnt & 1] > g_cnt) {
        pq.push({g_cnt, {nx, ny}});
        visited[nx][ny][g_cnt & 1] = g_cnt;
      }
    }
  }
  cout << -1 << endl;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  preproc();

  cin >> N >> M;

  for (int i = 0; i < N; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < s.size(); ++j) {
      grid[i][j] = s[j];
      if (s[j] == 'C') start = {i, j};
      else if (s[j] == 'D') goal = {i, j};
    }
  }
  grid[start.first][start.second] = '.';

  solution();
}

