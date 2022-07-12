#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>

#define endl '\n'
#define pii pair<int, int>

typedef long long ll;

using namespace std;

int T, N;
vector<int> seq;

void preproc() {
  seq.clear();
}

void solution() {
  for (int i = 0; i < N; ++i) {
    int cnt;
    string s;
    cin >> cnt;
    cin >> s;

    for (int j = 0; j < cnt; ++j) {
      if (s[j] == 'D') {
        if (seq[i] == 9) seq[i] = 0;
        else seq[i]++;
      } else {
        if (seq[i] == 0) seq[i] = 9;
        else seq[i]--;
      }
    }
  }
  for (auto num : seq) {
    cout << num << ' ';
  }
  cout << endl;
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
      seq.push_back(n);
    }
    solution();
  }
}
