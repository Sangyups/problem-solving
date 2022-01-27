#include <bits/stdc++.h>

#define endl '\n'
#define print(x) cout << x << endl
#define clearArray(arr, num) memset(arr, num, sizeof(arr))
#define clear2DArray(arr, num, row) \
  for (int i = 0; i < row; i++) {   \
    clearArray(arr[i], num);        \
  }
#define pii pair<int, int>
const int INF = 987654321;
typedef long long ll;
using namespace std;

const int MAX = 100;
const int COST_MAX = 10001;
int mem[MAX];
int cost[MAX];
int dp[MAX][COST_MAX];
int N, M, total_cost;

void solution() {
  for (int i = 0; i <= total_cost; i++) {
    if (cost[0] <= i) {
      dp[0][i] = mem[0];
    }
  }

  for (int i = 1; i < N; i++) {
    for (int j = 0; j <= total_cost; j++) {
      if (j - cost[i] >= 0) {
        dp[i][j] = dp[i - 1][j - cost[i]] + mem[i];
      }
      dp[i][j] = max(dp[i][j], dp[i - 1][j]);
    }
  }
  
  // for(int i = 0 ; i < N; i++ ) {
  //   for(int j = 0; j <=total_cost ; j++) {
  //     cout << dp[i][j] << ' ';
  //   }
  //   cout << endl;
  // }
  
  for (int i = 0; i <= total_cost; i++) {
    if (dp[N - 1][i] >= M) {
      cout << i << endl;
      break;
    }
  }
}

int main(int argc, const char* argv[]) {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    cin >> mem[i];
  }
  for (int i = 0; i < N; i++) {
    cin >> cost[i];
    total_cost += cost[i];
  }

  solution();
}
