#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define endl '\n'
#define pii pair<int, int>

typedef long long ll;

using namespace std;

#define MAX 3005

int R, C, H, W;
int mat[MAX][MAX];
int check[MAX][MAX];
int sum[MAX][MAX];

void clean_up() {
}

void pre_proc() {
}

void get_accumulated_sum() {
    for (int i = 1; i <= R; ++i) {
        for (int j = 1; j <= C; ++j) {
            sum[i][j] = check[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
        }
    }
}

bool is_median(int median) {
    for (int i = 1; i <= R; ++i) {
        for (int j = 1; j <= C; ++j) {
            if (mat[i][j] > median) check[i][j] = 1;
            else if (mat[i][j] < median) check[i][j] = -1;
            else check[i][j] = 0;
        }
    }
    get_accumulated_sum();

    for (int i = 1; i <= R - H + 1; ++i) {
        for (int j = 1; j <= C - W + 1; ++j) {
            int ex = i + H - 1;
            int ey = j + W - 1;
            int temp = sum[ex][ey] - sum[i - 1][ey] - sum[ex][j - 1] + sum[i - 1][j - 1];
            if (temp <= 0) return true;
        }
    }
    return false;
}

void solution() {
    int start = 1;
    int end = R * C;
    int result;

    while (start <= end) {
        int mid = (start + end) / 2;
        if (is_median(mid)) {
            result = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    cout << result;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> R >> C >> H >> W;
    clean_up();
    for (int i = 1; i <= R; ++i) {
        for (int j = 1; j <= C; ++j) {
            cin >> mat[i][j];
        }
    }
    pre_proc();
    solution();
}
