#include <iostream>
#include <vector>
#include <algorithm>

#define endl '\n'
#define pii pair<int, int>

typedef long long ll;

using namespace std;

#define pll pair<ll, ll>

pll p[5];

int ccw(pll p1, pll p2, pll p3) {
  auto[x1, y1] = p1;
  auto[x2, y2] = p2;
  auto[x3, y3] = p3;

  ll result = (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);

  if (result > 0) {
    return 1;
  } else if (result < 0) {
    return -1;
  } else {
    return 0;
  }
}

void solution() {

  int result1 = ccw(p[1], p[2], p[3]) * ccw(p[1], p[2], p[4]);
  int result2 = ccw(p[3], p[4], p[1]) * ccw(p[3], p[4], p[2]);

  if (result1 == 0 and result2 == 0) {
    if (p[1] > p[2]) swap(p[1], p[2]);
    if (p[3] > p[4]) swap(p[3], p[4]);

    if ((p[2] >= p[3] and p[2] <= p[4]) or (p[4] >= p[1] and p[4] <= p[2])) {
      cout << 1 << endl;
      return;
    }

  } else if (result1 <= 0 and result2 <= 0) {
    cout << 1 << endl;
    return;
  }
  cout << 0 << endl;

}

int main(int argc, const char *argv[]) {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  for (int i = 1; i < 5; ++i) {
    cin >> p[i].first >> p[i].second;
  }

  solution();
}
