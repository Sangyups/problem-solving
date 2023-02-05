#include <algorithm>
#include <cstring>
#include <iostream>
#include <tuple>
#include <vector>

#define endl '\n'
#define pii pair<int, int>

typedef long long ll;

using namespace std;

#define MAX 20
#define RED '1'
#define BLUE '2'
#define RIGHT 1
#define LEFT -1
#define UP 2
#define DOWN -2
#define tii tuple<int, int, int>

int N, K, flag;

char board[MAX][MAX];
vector<pii> arr[MAX][MAX];
vector<tii> position;

void preproc() {
    for (int i = 0; i < MAX; ++i) {
        for (int j = 0; j < MAX; ++j) {
            board[i][j] = BLUE;
        }
    }
    position.push_back(make_tuple(0, 0, 0));
}

pii get_direction(int direction) {
    if (direction == RIGHT) return make_pair(0, 1);
    if (direction == LEFT) return make_pair(0, -1);
    if (direction == UP) return make_pair(-1, 0);
    if (direction == DOWN) return make_pair(1, 0);
}

void clear_space(int x, int y) {
    arr[x][y].clear();
}

void reverse_space(int x, int y) {
    reverse(arr[x][y].begin(), arr[x][y].end());
    for (int i = 0; i < arr[x][y].size(); ++i) {
        position[arr[x][y][i].first] = make_tuple(x, y, i + 1);
    }
}

void move_space(int from_x, int from_y, int to_x, int to_y) {
    for (int i = 0; i < arr[from_x][from_y].size(); ++i) {
        arr[to_x][to_y].push_back(arr[from_x][from_y][i]);
        position[arr[from_x][from_y][i].first] = make_tuple(to_x, to_y, arr[to_x][to_y].size());
    }
    if (arr[to_x][to_y].size() >= 4) {
        flag = 1;
        return;
    }
    clear_space(from_x, from_y);
}

void solution() {
    int ans = 0;
    while (not flag and ++ans <= 1000) {
        for (int i = 1; i < position.size(); ++i) {
            auto [x, y, prior] = position[i];
            if (prior != 1) continue;
            auto [dx, dy] = get_direction(arr[x][y][0].second);
            int nx = x + dx;
            int ny = y + dy;
            if (board[nx][ny] == RED) {
                reverse_space(x, y);
                move_space(x, y, nx, ny);
            } else if (board[nx][ny] == BLUE) {
                nx = x - dx;
                ny = y - dy;
                arr[x][y][0].second = -arr[x][y][0].second;
                if (board[nx][ny] == RED) {
                    reverse_space(x, y);
                    move_space(x, y, nx, ny);
                } else if (board[nx][ny] != BLUE) {
                    move_space(x, y, nx, ny);
                }
            } else {
                move_space(x, y, nx, ny);
            }
        }
    }

    cout << (ans > 1000 ? -1 : ans);
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    preproc();

    cin >> N >> K;

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cin >> board[i][j];
        }
    }

    for (int i = 1; i <= K; ++i) {
        int x, y, direction;
        cin >> x >> y >> direction;
        if (direction == 2) direction = -1;
        else if (direction == 3) direction = 2;
        else if (direction == 4) direction = -2;
        position.push_back(make_tuple(x, y, 1));
        arr[x][y].push_back(make_pair(i, direction));
    }

    solution();
}
