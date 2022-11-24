using pii = pair<int, int>;

const int MAX = 10;

class Solution {
   public:
    int visited[MAX][MAX];
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    int N, M, K;
    map<char, vector<pii>> m;

    int dfs(pii curr_pos, int step, vector<vector<char>> &board, string word) {
        auto [cx, cy] = curr_pos;

        if (word[step] != board[cx][cy]) {
            return 0;
        }

        // cout << cx << " " << cy <<" step: " << step << " " << word[step]<< endl;
        if (step == K - 1) {
            return 1;
        }
        int flag = 0;

        for (int i = 0; i < 4; ++i) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (visited[nx][ny]) continue;

            visited[nx][ny] = 1;
            flag |= dfs(make_pair(nx, ny), step + 1, board, word);
            visited[nx][ny] = 0;
        }

        return flag;
    }

    bool exist(vector<vector<char>> &board, string word) {
        N = board.size();
        M = board[0].size();
        K = word.size();

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                m[board[i][j]].push_back({i, j});
            }
        }

        char first_letter = word[0];

        int res = 0;
        for (const auto &pos : m[first_letter]) {
            fill(&visited[0][0], &visited[MAX - 1][MAX], 0);
            visited[pos.first][pos.second] = 1;
            res |= dfs(pos, 0, board, word);
            if (res) return 1;
        }
        return 0;
    }
};
