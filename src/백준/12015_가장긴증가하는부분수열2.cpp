#include <iostream>
#include <vector>
#include <algorithm>

#define endl '\n'
#define pii pair<int, int>

typedef long long ll;

using namespace std;

#define MAX 1000001

int N;
int arr[MAX];
vector<int> dp;

void solution() {
  dp.push_back(arr[0]);

  for (int i = 1; i < N; ++i) {
    if (dp.back() < arr[i]) {
      dp.push_back(arr[i]);
    } else {
      int idx = lower_bound(dp.begin(), dp.end(), arr[i]) - dp.begin();
      dp[idx] = arr[i];
    }
  }

  cout << dp.size() << endl;
}

int main(int argc, const char *argv[]) {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> N;

  for (int i = 0; i < N; ++i) {
    cin >> arr[i];
  }

  solution();
}
