#define EMPTY 0
#define BLOCK 1

using pii = pair<int, int>;

const int MAX = 45;

class Solution {
   public:
    struct Node {
        int x, y, step, d_cnt;

        Node(int x, int y, int step, int d_cnt)
            : x(x),
              y(y),
              step(step),
              d_cnt(d_cnt) {}
    };
    int visited[MAX][MAX][MAX * MAX];
    int N, M;
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    int bfs(vector<vector<int>>& grid, pii start, int k) {
        queue<Node> q;
        auto [sx, sy] = start;
        if (sx == N - 1 && sy == M - 1) return 0;
        q.push(Node(sx, sy, 0, 0));
        visited[sx][sy][0] = 1;

        while (!q.empty()) {
            auto [cx, cy, step, d_cnt] = q.front();
            q.pop();

            for (int i = 0; i < 4; ++i) {
                int nx = cx + dx[i];
                int ny = cy + dy[i];

                if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                if (visited[nx][ny][d_cnt]) continue;
                if (grid[nx][ny] == BLOCK && visited[nx][ny][d_cnt + 1]) continue;

                if (nx == N - 1 && ny == M - 1) {
                    return step + 1;
                }

                if (grid[nx][ny] == BLOCK && d_cnt < k) {
                    q.push(Node(nx, ny, step + 1, d_cnt + 1));
                    visited[nx][ny][d_cnt + 1] = 1;
                }
                if (grid[nx][ny] == EMPTY) {
                    q.push(Node(nx, ny, step + 1, d_cnt));
                    visited[nx][ny][d_cnt] = 1;
                }
            }
        }

        return -1;
    }

    int shortestPath(vector<vector<int>>& grid, int k) {
        N = grid.size();
        M = grid[0].size();
        return bfs(grid, {0, 0}, k);
    }
};
