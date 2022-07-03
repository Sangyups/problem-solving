#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define endl '\n'
#define pii pair<int, int>

typedef long long ll;

using namespace std;

#define MAX 2505
#define pll pair<ll, ll>

int N;
vector<vector<int>> arr;

bool cmp(vector<int> &v1, vector<int> &v2) {
  return v1[4] < v2[4];
}

void preproc() {
}

int ccw(pll p1, pll p2, pll p3) {
  ll cross_product = (p2.first - p1.first) * (p3.second - p1.second);
  cross_product -= (p3.first - p1.first) * (p2.second - p1.second);

  if (cross_product > 0) {
    return 1;
  } else {
    return -1;
  }
}

void solution() {
  ll sum = 0;

  for (int i = 0; i < N; ++i) {
    vector<int> line_a = arr[i];
    ll cnt = 1;
    for (int j = i + 1; j < N; ++j) {
      vector<int> line_b = arr[j];
      pll p1 = {line_a[0], line_a[1]};
      pll p2 = {line_a[2], line_a[3]};
      pll p3 = {line_b[0], line_b[1]};
      pll p4 = {line_b[2], line_b[3]};
      if (ccw(p1, p2, p3) * ccw(p1, p2, p4) < 0 && ccw(p3, p4, p1) * ccw(p3, p4, p2) < 0) {
        ++cnt;
      }
    }
    sum += cnt * line_a[4];
  }

  cout << sum;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> N;

  for (int i = 0; i < N; ++i) {
    vector<int> temp;
    for (int j = 0; j < 5; ++j) {
      int n;
      cin >> n;
      temp.push_back(n);
    }
    arr.push_back(temp);
  }

  sort(arr.begin(), arr.end(), cmp);

  preproc();

  solution();
}
