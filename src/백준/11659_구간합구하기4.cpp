#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define endl '\n'
#define pii pair<int, int>

typedef long long ll;

using namespace std;

#define MAX (100000+5)

int N, M;
int arr[MAX];

void clean_up() {
}

void pre_proc() {
  for (int i = 2; i <= N; ++i) {
    arr[i] += arr[i - 1];
  }
}

void solution() {
  for (int i = 0; i < M; ++i) {
    int s, e;
    cin >> s >> e;
    cout << arr[e] - arr[s - 1] << endl;
  }
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> N >> M;
  clean_up();

  for (int i = 1; i <= N; ++i) {
    cin >> arr[i];
  }
  pre_proc();
  solution();
}
