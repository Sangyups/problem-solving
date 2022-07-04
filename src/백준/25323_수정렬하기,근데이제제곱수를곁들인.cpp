#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

#define endl '\n'
#define pii pair<int, int>

typedef long long ll;

using namespace std;

#define MAX 500005
int N;
ll arr[MAX];
ll sorted_arr[MAX];

void preproc() {
}

ll gcd(ll a, ll b) {
  if (a < b) return gcd(b, a);
  if (b == 0) return a;
  else return gcd(b, a % b);
}

int is_square(ll num) {
  int sqrt_num = sqrt(num);
  if (sqrt_num * sqrt_num == num) return 1;
  return 0;
}

void solution() {
  for (int i = 0; i < N; ++i) {
    ll gcd_num = gcd(arr[i], sorted_arr[i]);
    ll new_a = arr[i] / gcd_num;
    ll new_b = sorted_arr[i] / gcd_num;
    if (!is_square(new_a) || !is_square(new_b)) {
      cout << "NO";
      return;
    }
  }
  cout << "YES";
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> N;

  for (int i = 0; i < N; ++i) {
    cin >> arr[i];
    sorted_arr[i] = arr[i];
  }

  sort(sorted_arr, sorted_arr + N);

  preproc();
  solution();
}
