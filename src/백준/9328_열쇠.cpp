#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

#define endl '\n'
#define pii pair<int, int>

typedef long long ll;

using namespace std;

#define MAX 102

int T;
int h, w;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
char building[MAX][MAX];
int visited[MAX][MAX];
int answer;
vector<pair<char, pii >> doors;

void open_doors(char key) {
  for (auto door: doors) {
    if (door.first == toupper(key)) {
      auto[x, y] = door.second;
      building[x][y] = '.';
    }
  }
}

void bfs(int start_x, int start_y) {
  queue<pii > q;
  q.push(make_pair(start_x, start_y));

  while (!q.empty()) {
    auto[cx, cy] = q.front();
    q.pop();
    for (int i = 0; i < 4; ++i) {
      int nx = cx + dx[i];
      int ny = cy + dy[i];
      if (nx < 0 || nx > h + 1 || ny < 0 || ny > w + 1) continue;
      if (building[nx][ny] == '*' || (building[nx][ny] >= 'A' && building[nx][ny] <= 'Z') || visited[nx][ny]) continue;
      if (building[nx][ny] >= 'a' && building[nx][ny] <= 'z') {
        open_doors(building[nx][ny]);
        for (int i = 0; i < MAX; i++) {
          memset(visited[i], 0, sizeof(visited[i]));
        }
        building[nx][ny] = '.';
      } else if (building[nx][ny] == '$') {
        building[nx][ny] = '.';
        answer++;
      }
      q.push(make_pair(nx, ny));
      visited[nx][ny] = 1;
    }
  }
}

void solution() {
  bfs(0, 0);
  cout << answer << endl;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> T;

  while (T--) {
    cin >> h >> w;

    for (int i = 1; i <= h; ++i) {
      for (int j = 1; j <= w; ++j) {
        char temp;
        cin >> temp;
        if (temp >= 'A' && temp <= 'Z') {
          doors.push_back(make_pair(temp, make_pair(i, j)));
        }
        building[i][j] = temp;
      }
    }

    string keys;
    cin >> keys;
    if (keys != "0") {
      for (int i = 0; i < keys.length(); ++i) {
        open_doors(keys[i]);
      }
    }

    solution();

    answer = 0;
    doors.clear();
    for (int i = 0; i < MAX; i++) {
      memset(visited[i], 0, sizeof(visited[i]));
    }
    for (int i = 0; i < MAX; i++) {
      memset(building[i], 0, sizeof(building[i]));
    }
  }

}
