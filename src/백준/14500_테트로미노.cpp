#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define endl '\n'
#define pii pair<int, int>

typedef long long ll;

using namespace std;

#define MAX 505

int N, M;
int mat[MAX][MAX];
pii tetro[19][4] = {
    // 1
    {{0, 0}, {1, 0}, {1, 1}, {2, 0}},
    // 2
    {{0, 1}, {1, 0}, {1, 1}, {2, 1}},
    // 3
    {{0, 1}, {1, 0}, {1, 1}, {1, 2}},
    // 4
    {{0, 0}, {0, 1}, {0, 2}, {1, 1}},
    // 5
    {{0, 0}, {1, 0}, {0, 1}, {1, 1}},
    // 6
    {{0, 0}, {1, 0}, {2, 0}, {3, 0}},
    // 7
    {{0, 0}, {0, 1}, {0, 2}, {0, 3}},
    // 8
    {{0, 0}, {1, 0}, {2, 0}, {2, 1}},
    // 9
    {{1, 0}, {1, 1}, {1, 2}, {0, 2}},
    // 10
    {{0, 0}, {0, 1}, {1, 1}, {2, 1}},
    // 11
    {{0, 0}, {0, 1}, {0, 2}, {1, 0}},
    // 12
    {{0, 0}, {0, 1}, {1, 1}, {1, 2}},
    // 13
    {{0, 1}, {1, 0}, {1, 1}, {2, 0}},
    // 14
    {{0, 0}, {1, 0}, {1, 1}, {2, 1}},
    // 15
    {{0, 1}, {0, 2}, {1, 0}, {1, 1}},
    // 16
    {{2, 0}, {2, 1}, {1, 1}, {0, 1}},
    // 17
    {{0, 0}, {0, 1}, {0, 2}, {1, 2}},
    // 18
    {{0, 0}, {0, 1}, {1, 0}, {2, 0}},
    // 19
    {{0, 0}, {1, 0}, {1, 1}, {1, 2}},
};

void clean_up() {
}

void pre_proc() {
}

void solution() {
  int ans = 0;
  for (int k = 0; k < 19; ++k) {
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
        int sum = 0;
        for (int l = 0; l < 4; ++l) {
          int nx = i + tetro[k][l].first;
          int ny = j + tetro[k][l].second;
          if (nx < 0 || nx >= N || ny < 0 || ny >= M) {
            sum = 0;
            break;
          }
          sum += mat[nx][ny];
        }
        ans = max(ans, sum);
      }
    }
  }
  cout << ans << endl;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> N >> M;
  clean_up();
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      cin >> mat[i][j];
    }
  }
  pre_proc();
  solution();
}
