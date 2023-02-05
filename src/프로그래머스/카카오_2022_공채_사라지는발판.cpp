#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define A 0
#define B 1

using namespace std;
using pii = pair<int, int>;

const int MAX = 10;

int N, M;
int visited[MAX][MAX];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

pii moveA(vector<vector<int>> board, pii aPos, pii bPos, int depth);
pii moveB(vector<vector<int>> board, pii aPos, pii bPos, int depth);

pii moveA(vector<vector<int>> board, pii aPos, pii bPos, int depth) {
    int max_step = depth, min_step = 1e9;
    auto [cx, cy] = aPos;
    if (!board[cx][cy]) return {B, max_step};
    for (int i = 0; i < 4; ++i) {
        int nx = cx + dx[i];
        int ny = cy + dy[i];
        if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
        if (!board[nx][ny]) continue;
        board[cx][cy] = 0;

        pii result = moveB(board, {nx, ny}, bPos, depth + 1);
        auto [winner, step] = result;

        if (winner == A) {
            min_step = min(min_step, step);
        } else {
            max_step = max(max_step, step);
        }
    }
    if (min_step == 1e9) {
        return {B, max_step};
    }
    return {A, min_step};
}

pii moveB(vector<vector<int>> board, pii aPos, pii bPos, int depth) {
    int max_step = depth, min_step = 1e9;
    auto [cx, cy] = bPos;
    if (!board[cx][cy]) return {A, max_step};

    for (int i = 0; i < 4; ++i) {
        int nx = cx + dx[i];
        int ny = cy + dy[i];
        if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
        if (!board[nx][ny]) continue;
        board[cx][cy] = 0;

        pii result = moveA(board, aPos, {nx, ny}, depth + 1);
        auto [winner, step] = result;

        if (winner == B) {
            min_step = min(min_step, step);
        } else {
            max_step = max(max_step, step);
        }
    }
    if (min_step == 1e9) {
        return {A, max_step};
    }
    return {B, min_step};
}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
    N = board.size();
    M = board[0].size();

    auto [winner, answer] = moveA(board, {aloc[0], aloc[1]}, {bloc[0], bloc[1]}, 0);

    return answer;
}
