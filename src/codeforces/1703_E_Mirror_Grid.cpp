#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>

#define endl '\n'
#define pii pair<int, int>

typedef long long ll;

using namespace std;

#define MAX 105

int T, N;
char grid[MAX][MAX];

void preproc() {
  for (int i = 0; i < N; ++i) {
    memset(grid[i], 0, sizeof(grid[i]));
  }
}

void solution() {
  int ans = 0;
  for (int i = 0; i < N / 2; ++i) {
    for (int j = i; j < i + N - 2 * i - 1; ++j) {
      int x = i, y = j;
      int cnt[2] = {0, 0};
      cnt[grid[x][y] - '0']++;
      for (int k = 0; k < 3; ++k) {
        int temp = x;
        x = y;
        y = N - 1 - temp;
        cnt[grid[x][y] - '0']++;
      }
      ans += min(cnt[0], cnt[1]);
    }
  }
  cout << ans << endl;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cin >> T;

  while (T--) {
    cin >> N;
    preproc();
    for (int i = 0; i < N; ++i) {
      string s;
      cin >> s;
      for (int j = 0; j < N; ++j) {
        grid[i][j] = s[j];
      }
    }
    solution();
  }
}
