#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

#define UP 0
#define DOWN 3
#define LEFT 1
#define RIGHT 2

#define CCW 0
#define CW 1

using namespace std;
using pii = pair<int, int>;

const int MAX = 105;

struct Point {
    int x;
    int y;
    int direction;

    Point(int x, int y, int direction)
        : x(x),
          y(y),
          direction(direction) {}
};

int N;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
int rdx[4] = {-1, -1, 1, 1};
int rdy[4] = {-1, 1, -1, 1};
int visited[MAX][MAX][4];

int get_distance(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

int rotate_dir(int prev_dir, int direction) {
    if (direction == CCW) {
        if (prev_dir == RIGHT) return UP;
        if (prev_dir == UP) return LEFT;
        if (prev_dir == LEFT) return DOWN;
        if (prev_dir == DOWN) return RIGHT;
    } else if (direction == CW) {
        if (prev_dir == RIGHT) return DOWN;
        if (prev_dir == UP) return RIGHT;
        if (prev_dir == LEFT) return UP;
        if (prev_dir == DOWN) return LEFT;
    }
}

int bfs(vector<vector<int>> &board) {
    int start_dir = RIGHT;
    Point start = Point(0, 0, start_dir);

    queue<pair<Point, int>> q;
    q.push({start, 0});
    visited[0][0][start_dir] = 1;
    visited[0][1][3 - start_dir] = 1;

    while (!q.empty()) {
        auto [curr_pos, step] = q.front();
        q.pop();

        int x = curr_pos.x;
        int y = curr_pos.y;
        int direction = curr_pos.direction;

        int x2 = x + dx[direction];
        int y2 = y + dy[direction];

        // 수평, 수직이동
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            int nx2 = x2 + dx[i];
            int ny2 = y2 + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (nx2 < 0 || nx2 >= N || ny2 < 0 || ny2 >= N) continue;

            if (visited[nx][ny][direction]) continue;
            if (visited[nx2][ny2][3 - direction]) continue;

            if (board[nx][ny]) continue;
            if (board[nx2][ny2]) continue;

            Point np = Point(nx, ny, direction);
            q.push({np, step + 1});
            visited[nx][ny][direction] = 1;
            visited[nx2][ny2][3 - direction] = 1;
        }

        // 회전이동
        for (int r_dir = 0; r_dir < 2; ++r_dir) {
            // 회전축 결정
            int xs[2] = {x, x2};
            int ys[2] = {y, y2};

            for (int i = 0; i < 2; ++i) {
                int cx = xs[i];
                int cy = ys[i];
                int curr_dir = (i == 0 ? direction : 3 - direction);
                int next_dir = rotate_dir(curr_dir, r_dir);

                int rx = cx + dx[next_dir];
                int ry = cy + dy[next_dir];

                int rx_temp;
                int ry_temp;
                for (int j = 0; j < 4; ++j) {
                    rx_temp = cx + rdx[j];
                    ry_temp = cy + rdy[j];
                    int a = get_distance(xs[1 - i], ys[1 - i], rx_temp, ry_temp);
                    int b = get_distance(rx, ry, rx_temp, ry_temp);

                    if (a == 1 && b == 1) break;
                }

                if (rx < 0 || rx >= N || ry < 0 || ry >= N) continue;
                if (rx_temp < 0 || rx_temp >= N || ry_temp < 0 || ry_temp >= N) continue;

                if (visited[cx][cy][next_dir]) continue;
                if (visited[rx][ry][3 - next_dir]) continue;

                if (board[rx][ry]) continue;
                if (board[rx_temp][ry_temp]) continue;

                Point np = Point(cx, cy, next_dir);
                q.push({np, step + 1});
                visited[cx][cy][next_dir] = 1;
                visited[rx][ry][3 - next_dir] = 1;
            }
        }
        if (visited[N - 1][N - 1][LEFT] || visited[N - 1][N - 1][UP]) return step + 1;
    }

    return -1;
}

int solution(vector<vector<int>> board) {
    N = board.size();
    int answer = bfs(board);

    return answer;
}
