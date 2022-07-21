#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define endl '\n'
#define pii pair<int, int>

typedef long long ll;

using namespace std;

int N, K;
int arr[15];
int mx;
int mx_idx;

void clean_up() {
}

void pre_proc() {
}

void solution() {
  int cnt = 0;
  for (int i = mx_idx; i >= 0; --i) {
    int coin = arr[i];
    while (K >= coin) {
      K -= coin;
      cnt++;
    }
    if (K == 0) break;
  }

  cout << cnt << endl;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> N >> K;
  for (int i = 0; i < N; ++i) {
    cin >> arr[i];
    if (arr[i] <= K && mx < arr[i]) {
      mx = arr[i];
      mx_idx = i;
    }
  }

  clean_up();
  pre_proc();
  solution();
}
