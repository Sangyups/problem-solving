#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define endl '\n'
#define pii pair<int, int>

typedef long long ll;

using namespace std;

int N;
int col_size;
char mat[3072][6143];

void clean_up() {
}

void pre_proc() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < col_size; ++j) {
            mat[i][j] = ' ';
        }
    }
}

void fill_star(int x, int y) {
    mat[x][y] = '*';

    mat[x + 1][y - 1] = '*';
    mat[x + 1][y + 1] = '*';

    mat[x + 2][y - 2] = '*';
    mat[x + 2][y - 1] = '*';
    mat[x + 2][y] = '*';
    mat[x + 2][y + 1] = '*';
    mat[x + 2][y + 2] = '*';
}

void triangle(int x, int y, int len) {
    if (len == 3) {
        fill_star(x, y);
        return;
    }

    triangle(x, y, len / 2);
    triangle(x + len / 2, y - len / 2, len / 2);
    triangle(x + len / 2, y + len / 2, len / 2);
}

void solution() {
    triangle(0, col_size / 2, N);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < col_size; ++j) {
            cout << mat[i][j];
        }
        cout << endl;
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N;
    col_size = (N / 3) * 5 + N / 3 - 1;
    clean_up();
    pre_proc();
    solution();
}
