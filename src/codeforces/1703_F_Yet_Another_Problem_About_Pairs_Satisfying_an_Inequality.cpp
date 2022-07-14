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
vector<int> arr;

void preproc() {
  arr.clear();
  arr.push_back(-1);
}

void solution() {
  ll cnt = 0;
  vector<int> valid_indices;
  for (int i = 1; i <= N; ++i) {
    if (arr[i] < i) valid_indices.push_back(i);
  }
  for (int k = 0; k < valid_indices.size(); ++k) {
    int j = valid_indices[k];
    int a_j = arr[j];
    auto it = lower_bound(valid_indices.begin(), valid_indices.begin() + k, a_j);
    cnt += ll(it - valid_indices.begin());
  }
  cout << cnt << endl;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cin >> T;

  while (T--) {
    cin >> N;
    preproc();
    for (int i = 0; i < N; ++i) {
      int n;
      cin >> n;
      arr.push_back(n);
    }
    solution();
  }
}
