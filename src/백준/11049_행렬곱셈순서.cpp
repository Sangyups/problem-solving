#include <iostream>
#include <vector>
#include <algorithm>

#define endl '\n'
#define pii pair<int, int>

typedef long long ll;

using namespace std;

#define MAX 502

int N;
int mat[MAX][2];
int dp[MAX][MAX];

void solution() {
  for (int s = 1; s < N; ++s) {
    for (int i = 1; i <= N - s; ++i) {
      int j = i + s;
      for (int k = i; k < j; ++k) {
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + mat[i][0] * mat[k][1] * mat[j][1]);
      }
    }
  }
  cout << dp[1][N];
}

int main(int argc, const char *argv[]) {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> N;
  fill(&dp[0][0], &dp[MAX - 1][MAX], 2147483647);

  for (int i = 1; i <= N; ++i) {
    cin >> mat[i][0] >> mat[i][1];
    dp[i][i] = 0;
  }

  solution();
}
