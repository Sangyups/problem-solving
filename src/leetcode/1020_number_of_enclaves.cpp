#define MAX 505

using pii = pair<int, int>;

class Solution {
   public:
    int N, M;
    int visited[MAX][MAX];
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    int bfs(pii start, vector<vector<int>>& grid) {
        int cnt = 1;
        queue<pii> q;
        q.push(start);
        bool enclaved = !isAtBoundary(start);

        while (!q.empty()) {
            auto [cx, cy] = q.front();
            q.pop();

            for (int i = 0; i < 4; ++i) {
                int nx = cx + dx[i];
                int ny = cy + dy[i];

                if (nx < 0 || nx >= N || ny < 0 || ny >= M) {
                    continue;
                }
                if (grid[nx][ny] == 0) {
                    continue;
                }
                if (visited[nx][ny]) {
                    continue;
                }

                pii next_point = {nx, ny};
                enclaved &= !isAtBoundary(next_point);
                visited[nx][ny] = 1;
                ++cnt;
                q.push(next_point);
            }
        }

        return enclaved ? cnt : 0;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        N = grid.size();
        M = grid[0].size();
        int answer = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (grid[i][j] == 0) {
                    continue;
                }
                if (visited[i][j]) {
                    continue;
                }
                visited[i][j] = 1;
                answer += bfs({i, j}, grid);
            }
        }

        return answer;
    }
    bool isAtBoundary(pii p) {
        auto& [x, y] = p;
        return x == 0 || x == N - 1 || y == 0 || y == M - 1;
    }
};
