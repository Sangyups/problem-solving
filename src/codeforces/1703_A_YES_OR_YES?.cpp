#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define endl '\n'
#define pii pair<int, int>

typedef long long ll;

using namespace std;

int T;
string s;

void preproc() {
}

void solution() {
  transform(s.begin(), s.end(), s.begin(), ::tolower);
  if (s == "yes") cout << "yes" << endl;
  else cout << "no" << endl;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cin >> T;

  while (T--) {
    cin >> s;
    preproc();
    solution();
  }
}
