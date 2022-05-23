#include <bits/stdc++.h>

#define endl '\n'
#define print(x) cout << x << endl
#define clearArray(arr, num) memset(arr, num, sizeof(arr))
#define clear2DArray(arr, num, row) \
  for (int i = 0; i < row; i++) {   \
    clearArray(arr[i], num);        \
  }
#define pii pair<int, int>
#define INF 1987654321
typedef long long ll;
using namespace std;

const int MAX = 5005;
int N;
// vector<int> p;
// vector<int> m;
vector<ll> arr;
int comb[MAX];
ll ans[3];
ll temp = 3000000001;

bool func(int a, int b) {
  ll key = -(arr[a] + arr[b]);
  int idx = int(lower_bound(arr.begin(), arr.end(), key) - arr.begin());

  if (arr[idx] == key && !(idx == a || idx == b)) {
    ans[0] = arr[a];
    ans[1] = arr[b];
    ans[2] = arr[idx];
    return true;
  }

  int x = idx - 1;
  int y = idx;

  while (x == a || x == b || x >= N) {
    x--;
  }
  while (y == a || y == b) {
    y++;
  }

  if (x < 0) {
    if (abs(arr[a] + arr[b] + arr[y]) < temp) {
      ans[0] = arr[a];
      ans[1] = arr[b];
      ans[2] = arr[y];
      temp = abs(arr[a] + arr[b] + arr[y]);
    }
  } else if (y >= N) {
    if (abs(arr[a] + arr[b] + arr[x]) < temp) {
      ans[0] = arr[a];
      ans[1] = arr[b];
      ans[2] = arr[x];
      temp = abs(arr[a] + arr[b] + arr[x]);
    }
  } else {
    ll sum;
    int target;
    if (abs(arr[a] + arr[b] + arr[y]) < abs(arr[a] + arr[b] + arr[x])) {
      sum = abs(arr[a] + arr[b] + arr[y]);
      target = y;
    } else {
      sum = abs(arr[a] + arr[b] + arr[x]);
      target = x;
    }
    if (sum < temp) {
      ans[0] = arr[a];
      ans[1] = arr[b];
      ans[2] = arr[target];
      temp = abs(arr[a] + arr[b] + arr[target]);
    }
  }

  return false;
}

void solution() {
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      if (func(i, j)) return;
      // cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << ": " << abs(ans[0] + ans[1] + ans[2]) << endl;
    }
  }
}

int main(int argc, const char* argv[]) {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> N;
  for (int i = 0; i < N; i++) {
    int n;
    cin >> n;
    // if (n > 0) {
    //   p.push_back(n);
    // } else {
    //   m.push_back(n);
    // }
    arr.push_back(n);
    sort(arr.begin(), arr.end());
  }

  solution();

  sort(ans, ans + 3);
  cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << endl;
  // cout << abs(ans[0] + ans[1] + ans[2]) << endl;
}
