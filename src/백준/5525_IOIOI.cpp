#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define endl '\n'
#define pii pair<int, int>

typedef long long ll;

using namespace std;

int N, M;
string s;

void clean_up() {
}

void pre_proc() {
}

void solution() {
  int ans = 0;
  for (int i = 0; i < M - 2; ++i) {
    if (s[i] == 'O') continue;

    int cnt = 0;
    while (s[i + 1] == 'O' && s[i + 2] == 'I') {
      cnt++;
      if (cnt == N) {
        cnt--;
        ans++;
      }
      i += 2;
    }
  }

  cout << ans << endl;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> N >> M;
  clean_up();

  cin >> s;
  pre_proc();
  solution();
}
