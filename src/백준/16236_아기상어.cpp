#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

#define endl '\n'
#define pii pair<int, int>

typedef long long ll;

using namespace std;

const int MAX = 25;
const int INF = 2e9;

int N;
int shark_size = 2;
int mat[MAX][MAX];
int visited[MAX][MAX];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int sx, sy;

void clean_up() {
}

void pre_proc() {
}

pair<int, pii> bfs(int x, int y) {
    queue<pair<pii, int> > q;
    q.push({{x, y}, 0});
    vector<pair<int, pii> > fishes = {{INF, {INF, INF}}};
    visited[x][y] = 1;
    while (!q.empty()) {
        auto [coord, step] = q.front();
        auto [cx, cy] = coord;
        // cout << cx << ' ' << cy << endl;
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (visited[nx][ny] || mat[nx][ny] > shark_size) continue;
            if (mat[nx][ny] > 0 && mat[nx][ny] < shark_size) {
                fishes.push_back({step + 1, {nx, ny}});
            }
            visited[nx][ny] = 1;
            q.push({{nx, ny}, step + 1});
        }
    }
    sort(fishes.begin(), fishes.end());
    return fishes[0];
}

void solution() {
    int ans = 0;
    int shark_exp = 0;
    while (true) {
        fill(&visited[0][0], &visited[N - 1][N], 0);
        auto [step, coord] = bfs(sx, sy);
        if (step == INF) break;
        auto [x, y] = coord;
        ans += step;
        ++shark_exp;
        if (shark_size == shark_exp) {
            shark_exp = 0;
            ++shark_size;
        }
        mat[x][y] = 0;
        sx = x;
        sy = y;
    }

    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N;
    clean_up();

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> mat[i][j];
            if (mat[i][j] == 9) {
                sx = i;
                sy = j;
                mat[i][j] = 0;
            }
        }
    }
    pre_proc();
    solution();
}
