#include <algorithm>
#include <iostream>
#include <vector>

#define endl '\n'
#define pii pair<int, int>

typedef long long ll;

using namespace std;

#define MAX 2188

int N;
int mat[MAX][MAX];
int cnt[3];

void solution(int sx, int sy, int size) {
    if (size == 0) return;

    int temp = mat[sx][sy];

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (mat[sx + i][sy + j] != temp) {
                for (int k = 0; k < 3; ++k) {
                    for (int l = 0; l < 3; ++l) {
                        solution(sx + (size / 3) * k, sy + (size / 3) * l, size / 3);
                    }
                }
                return;
            }
        }
    }
    if (temp == -1) cnt[0]++;
    else if (temp == 0) cnt[1]++;
    else cnt[2]++;
}

int main(int argc, const char *argv[]) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> mat[i][j];
        }
    }

    solution(0, 0, N);

    for (int c : cnt) {
        cout << c << endl;
    }
}
