using pii = pair<int, int>;

const int MAX = 105;

struct Node {
    int x;
    int y;
    int step;

    Node(int x, int y, int step)
        : x(x),
          y(y),
          step(step) {}
};

class Solution {
   public:
    int visited[MAX][MAX];
    int N, M;
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    set<pii> exits;

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        N = maze.size();
        M = maze[0].size();

        for (int i = 0; i < N; ++i) {
            if (maze[i][0] == '.') {
                if (i != entrance[0] || 0 != entrance[1]) {
                    exits.insert({i, 0});
                }
            }
            if (maze[i][M - 1] == '.') {
                if (i != entrance[0] || M - 1 != entrance[1]) {
                    exits.insert({i, M - 1});
                }
            }
        }

        for (int j = 0; j < M; ++j) {
            if (maze[0][j] == '.') {
                if (0 != entrance[0] || j != entrance[1]) {
                    exits.insert({0, j});
                }
            }
            if (maze[N - 1][j] == '.') {
                if (N - 1 != entrance[0] || j != entrance[1]) {
                    exits.insert({N - 1, j});
                }
            }
        }

        auto bfs = [&](int sx, int sy) -> int {
            queue<Node> q;
            visited[sx][sy] = 1;
            q.push({sx, sy, 0});

            while (!q.empty()) {
                auto [x, y, step] = q.front();
                q.pop();

                for (int i = 0; i < 4; ++i) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if (nx < 0 || nx >= N || ny < 0 | ny >= M) continue;
                    if (maze[nx][ny] == '+') continue;
                    if (visited[nx][ny]) continue;

                    if (exits.find({nx, ny}) != exits.end()) {
                        return step + 1;
                    }

                    q.push({nx, ny, step + 1});
                    visited[nx][ny] = 1;
                }
            }

            return -1;
        };

        return bfs(entrance[0], entrance[1]);
    }
};
