#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

#define endl '\n'
#define pii pair<int, int>

typedef long long ll;

using namespace std;

#define MAX 105

int N, K, R;
int visited[MAX][MAX];
int road[MAX][MAX][4];
int cnt;

// 0 = left, 1 = right, 2 = up, 3 = down
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int comb[2] = {-1, -1};
pii cow[MAX * MAX];

void preproc() {
}

void save_road(int r1, int c1, int r2, int c2) {
    int r_diff, c_diff;
    r_diff = r2 - r1;
    c_diff = c2 - c1;

    if (r_diff == 0 and c_diff == -1) {
        road[r1][c1][0] = 1;
        road[r2][c2][1] = 1;
    } else if (r_diff == 0 and c_diff == 1) {
        road[r1][c1][1] = 1;
        road[r2][c2][0] = 1;
    } else if (r_diff == -1 and c_diff == 0) {
        road[r1][c1][2] = 1;
        road[r2][c2][3] = 1;
    } else if (r_diff == 1 and c_diff == 0) {
        road[r1][c1][3] = 1;
        road[r2][c2][2] = 1;
    }
}

void bfs(pii start, pii goal) {
    memset(visited, 0, sizeof(visited));
    queue<pii> q;
    visited[start.first][start.second] = 1;
    q.push(start);

    while (not q.empty()) {
        auto [cx, cy] = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (nx < 0 or nx >= N or ny < 0 or ny >= N) continue;
            if (road[cx][cy][i] == 1) continue;
            if (visited[nx][ny]) continue;
            if (nx == goal.first and ny == goal.second) {
                cnt++;
            }
            visited[nx][ny] = 1;
            q.push({nx, ny});
        }
    }
}

void solution() {
    int MAX_PAIR = K * (K - 1) / 2;
    for (int i = 0; i < K; ++i) {
        for (int j = i + 1; j < K; ++j) {
            bfs(cow[i], cow[j]);
        }
    }

    cout << MAX_PAIR - cnt;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    preproc();

    cin >> N >> K >> R;

    for (int i = 0; i < R; ++i) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        save_road(r1 - 1, c1 - 1, r2 - 1, c2 - 1);
    }

    for (int i = 0; i < K; ++i) {
        int r, c;
        cin >> r >> c;
        cow[i] = {r - 1, c - 1};
    }

    solution();
}
