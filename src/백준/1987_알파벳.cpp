#include <algorithm>
#include <iostream>
#include <vector>

#define endl '\n'

#ifdef LOCAL
#define debug(x) std::cout << "[DEBUG] " << #x << ": " << x << '\n'
#else
#define debug(x)
#endif

using namespace std;

using pii = pair<int, int>;
using ll = long long;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int visited[26];

int ans = 0;

void dfs(int x, int y, int cnt, const vector<string> &board) {
    ans = max(ans, cnt);

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= board.size() || ny < 0 || ny >= board[0].size()) {
            continue;
        }

        int char_index = board[nx][ny] - 'A';
        if (visited[char_index]) {
            continue;
        }

        visited[char_index] = 1;
        dfs(nx, ny, cnt + 1, board);
        visited[char_index] = 0;
    }
};

void solution(int r, int c, vector<string> board) {
    visited[board[0][0] - 'A'] = 1;
    dfs(0, 0, 1, board);
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

#ifdef LOCAL
    cout << "#### INPUT ####" << endl;
    cout.flush();
#endif

    ////////////////////////////////////
    // THIS IS WHERE YOU HANDLE INPUT //
    ////////////////////////////////////
    int r;
    int c;

    cin >> r >> c;

    vector<string> board(r);

    for (int i = 0; i < r; i++) {
        cin >> board[i];
    }
    ////////////////////////////////////
    ////////////////////////////////////

#ifdef LOCAL
    cout << "#### OUTPUT ####" << endl;
    cout.flush();
#endif

    solution(r, c, board);
    cout << ans << endl;
}
