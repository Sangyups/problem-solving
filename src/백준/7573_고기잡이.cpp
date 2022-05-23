#include <bits/stdc++.h>

#define endl '\n'
#define print(x) cout << #x << ": " << x << endl
#define printPair(x, y) cout << #x << ' ' << #y << ": " << x << ' ' << y << endl
#define clearArray(arr, num) memset(arr, num, sizeof(arr))
#define clear2DArray(arr, num, row) \
  for (int i = 0; i < row; i++) {   \
    clearArray(arr[i], num);        \
  }
#define pii pair<int, int>
const int INF = 1987654321;
typedef long long ll;
using namespace std;

const int MAX = 10001;
int N, I, M;
int ans;
vector<pii> fishes;

void searchFish(int x, int y, int h, int w) {
  // if (x < 1 || y < 1 || x + h > N || y + w > N) return;
  int cnt = 0;
  for (auto fish : fishes) {
    int i = fish.first;
    int j = fish.second;
    if (i >= x && i <= x + h && j >= y && j <= y + w) {
      cnt++;
    }
  }
  ans = max(ans, cnt);
}

void takePosition(int h, int w) {
  for (auto fish : fishes) {
    int x = fish.first;
    int y = fish.second;
    for (int i = 0; i <= h; i++) {
      searchFish(x - i, y, h, w);
    }
    for (int j = 0; j <= w; j++) {
      searchFish(x, y - j, h, w);
    }
  }
}

void makeNet() {
  for (int w = 1; w < I; w++) {
    int h = I - w;
    if (w < N && h < N) {
      takePosition(h, w);
    }
  }
}

void solution() {
  makeNet();
  cout << ans << endl;
}

int main(int argc, const char* argv[]) {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cin >> N >> I >> M;

  I /= 2;
  for (int i = 0; i < M; i++) {
    int x, y;
    cin >> x >> y;
    fishes.push_back(make_pair(x, y));
  }
  sort(fishes.begin(), fishes.end());
  solution();
}
