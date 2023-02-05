#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define pii pair<int, int>

vector<string> grid;
vector<vector<pii>> to_delete;
int N, M;
int answer;

void move_board() {
    for (int i = N - 1; i >= 0; --i) {
        for (int j = 0; j < M; ++j) {
            if (grid[i][j] == ' ') continue;
            int r = i;
            int c = j;
            while (r < N - 1 && grid[r + 1][c] == ' ') {
                swap(grid[r][c], grid[r + 1][c]);
                ++r;
            }
        }
    }
}

void delete_board() {
    for (auto coords : to_delete) {
        for (auto coord : coords) {
            auto [x, y] = coord;
            if (grid[x][y] != ' ') {
                grid[x][y] = ' ';
                answer++;
            }
        }
    }
}

void check_board() {
    for (int i = 0; i < N - 1; ++i) {
        for (int j = 0; j < M - 1; ++j) {
            char temp = grid[i][j];
            if (temp == ' ') continue;
            vector<pii> coords;
            for (int k = 0; k < 2; ++k) {
                for (int l = 0; l < 2; ++l) {
                    if (temp == grid[i + k][j + l]) {
                        coords.push_back({i + k, j + l});
                    }
                }
            }
            if (coords.size() == 4) {
                to_delete.push_back(coords);
            }
        }
    }
}

int solution(int m, int n, vector<string> board) {
    grid = board;
    N = m;
    M = n;

    do {
        delete_board();
        move_board();
        to_delete.clear();
        check_board();
    } while (to_delete.size());

    return answer;
}
