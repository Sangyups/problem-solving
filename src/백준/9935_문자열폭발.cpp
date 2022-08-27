#include <bits/stdc++.h>

#define endl '\n'
#define pii pair<int, int>

typedef long long ll;

using namespace std;

string s;
string cut;
int N;

void clean_up() {
}

void pre_proc() {
}

void solution() {
  string ans = "";
  for (int i = 0; i < s.size(); ++i) {
    ans += s[i];
    int idx = ans.size() - 1;
    if (s[i] != cut[N - 1]) continue;
    int flag = 1;
    for (int j = 1; j < N; ++j) {
      if (ans[idx - j] != cut[N - 1 - j]) {
        flag = 0;
        break;
      }
    }
    if (flag) {
      for (int j = 0; j < N; ++j) ans.pop_back();
    }
  }
  cout << (ans.size() ? ans : "FRULA") << endl;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> s;
  cin >> cut;
  N = cut.size();

  clean_up();
  pre_proc();
  solution();
}
