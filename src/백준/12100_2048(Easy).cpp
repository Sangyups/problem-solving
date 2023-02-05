#include <algorithm>
#include <iostream>
#include <vector>

#define endl '\n'
#define pii pair<int, int>

typedef long long ll;

using namespace std;

#define MAX 20
#define DOWN 1
#define UP 2
#define LEFT 3
#define RIGHT 4

int N;
int answer;
int board[MAX][MAX];

void copy_array(int from[MAX][MAX], int to[MAX][MAX]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            to[i][j] = from[i][j];
        }
    }
}

void solution(int direction, int cnt) {
    if (cnt == 6) return;

    int new_board[MAX][MAX];
    copy_array(board, new_board);

    if (direction == DOWN) {
        for (int j = 0; j < N; ++j) {
            int x = N - 1, y = j;
            for (int i = N - 2; i >= 0; --i) {
                if (board[i][j] == 0) continue;
                if (board[i][j] == board[x][y]) {
                    board[x][y] *= 2;
                    answer = max(board[x][y], answer);
                    board[i][j] = 0;
                    x = i;
                    y = j;
                } else {
                    x = i;
                    y = j;
                }
            }
        }
        for (int j = 0; j < N; ++j) {
            for (int i = N - 1; i >= 0; --i) {
                if (board[i][j] == 0) continue;
                while (i + 1 < N and board[i + 1][j] == 0) {
                    swap(board[i][j], board[i + 1][j]);
                    i += 1;
                }
            }
        }
    } else if (direction == UP) {
        for (int j = 0; j < N; ++j) {
            int x = 0, y = j;
            for (int i = 1; i < N; ++i) {
                if (board[i][j] == 0) continue;
                if (board[i][j] == board[x][y]) {
                    board[x][y] *= 2;
                    answer = max(board[x][y], answer);
                    board[i][j] = 0;
                    x = i;
                    y = j;
                } else {
                    x = i;
                    y = j;
                }
            }
        }
        for (int j = 0; j < N; ++j) {
            for (int i = 0; i < N; ++i) {
                if (board[i][j] == 0) continue;
                while (i - 1 >= 0 and board[i - 1][j] == 0) {
                    swap(board[i][j], board[i - 1][j]);
                    i -= 1;
                }
            }
        }
    } else if (direction == LEFT) {
        for (int i = 0; i < N; ++i) {
            int x = i, y = 0;
            for (int j = 1; j < N; ++j) {
                if (board[i][j] == 0) continue;
                if (board[i][j] == board[x][y]) {
                    board[x][y] *= 2;
                    answer = max(board[x][y], answer);
                    board[i][j] = 0;
                    x = i;
                    y = j;
                } else {
                    x = i;
                    y = j;
                }
            }
        }
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (board[i][j] == 0) continue;
                while (j - 1 >= 0 and board[i][j - 1] == 0) {
                    swap(board[i][j], board[i][j - 1]);
                    j -= 1;
                }
            }
        }
    } else {
        for (int i = 0; i < N; ++i) {
            int x = i, y = N - 1;
            for (int j = N - 2; j >= 0; --j) {
                if (board[i][j] == 0) continue;
                if (board[i][j] == board[x][y]) {
                    board[x][y] *= 2;
                    answer = max(board[x][y], answer);
                    board[i][j] = 0;
                    x = i;
                    y = j;
                } else {
                    x = i;
                    y = j;
                }
            }
        }
        for (int i = 0; i < N; ++i) {
            for (int j = N - 1; j >= 0; --j) {
                if (board[i][j] == 0) continue;
                while (j + 1 < N and board[i][j + 1] == 0) {
                    swap(board[i][j], board[i][j + 1]);
                    j += 1;
                }
            }
        }
    }
    solution(DOWN, cnt + 1);
    solution(UP, cnt + 1);
    solution(LEFT, cnt + 1);
    solution(RIGHT, cnt + 1);
    copy_array(new_board, board);
}

int main(int argc, const char *argv[]) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> board[i][j];
            answer = max(board[i][j], answer);
        }
    }

    solution(DOWN, 1);
    solution(UP, 1);
    solution(LEFT, 1);
    solution(RIGHT, 1);

    cout << answer << endl;
}
