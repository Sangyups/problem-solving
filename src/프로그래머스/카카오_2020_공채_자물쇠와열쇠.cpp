#include <iostream>
#include <string>
#include <vector>

#define pii pair<int, int>

using namespace std;

int N, M;
vector<vector<int>> key_global, lock_global;

void rotate() {
    int temp[M][M];
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < M; ++j) {
            temp[i][j] = key_global[M - 1 - j][i];
        }
    }
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < M; ++j) {
            key_global[i][j] = temp[i][j];
        }
    }
}

int open_lock(int dx, int dy) {
    int cnt = 0;
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < M; ++j) {
            int cx = i + dx;
            int cy = j + dy;
            if (cx < 0 || cx >= N || cy < 0 || cy >= N) continue;
            if (key_global[i][j] & lock_global[cx][cy]) return 0;
            if (!key_global[i][j] & !lock_global[cx][cy]) return 0;
            if (key_global[i][j] == 1 && lock_global[cx][cy] == 0) ++cnt;
        }
    }
    return cnt;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = true;

    N = lock.size();
    M = key.size();

    key_global = key;
    lock_global = lock;

    vector<pii> empty;
    vector<pii> key_pos;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (!lock[i][j]) empty.push_back({i, j});
        }
    }
    if (empty.size() == 0) return answer;

    for (int k = 0; k < 4; ++k) {
        rotate();
        for (int i = 0; i < M + N - 1; ++i) {
            for (int j = 0; j < M + N; ++j) {
                int dx = i - (M - 1);
                int dy = j - (M - 1);
                if (open_lock(dx, dy) == empty.size()) return true;
            }
        }
    }

    return false;
}
