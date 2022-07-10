#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define endl '\n'
#define pii pair<int, int>

typedef long long ll;

using namespace std;

int T;
int N;

void preproc() {
}

void solution() {
  int temp = N;
  int sub = 1;
  while (temp >= 10) {
    sub *= 10;
    temp /= 10;
  }
  cout << N - sub << endl;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> T;
  while (T--) {
    cin >> N;
    preproc();
    solution();
  }

}
