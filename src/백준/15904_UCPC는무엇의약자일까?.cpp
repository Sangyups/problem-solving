#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define endl '\n'
#define pii pair<int, int>

typedef long long ll;

using namespace std;

string s;

void preproc() {
}

void solution() {
  string answer = "UCPC";
  int j = 0;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == answer[j]) ++j;
  }
  cout << (j == 4 ? "I love UCPC" : "I hate UCPC");
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  getline(cin, s);

  preproc();
  solution();
}
