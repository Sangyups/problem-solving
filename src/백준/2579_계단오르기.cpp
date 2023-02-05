#include <algorithm>
#include <iostream>
#include <vector>

#define endl '\n'
#define pii pair<int, int>

typedef long long ll;

using namespace std;

#define MAX 305

int N;
int arr[MAX];
int dp[MAX];

void solution() {
    dp[0] = arr[0];
    dp[1] = dp[0] + arr[1];
    dp[2] = max(arr[0] + arr[2], arr[1] + arr[2]);

    for (int i = 3; i < N; ++i) {
        dp[i] = max(dp[i - 2] + arr[i], dp[i - 3] + arr[i - 1] + arr[i]);
    }

    cout << dp[N - 1];
}

int main(int argc, const char *argv[]) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N;

    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    solution();
}
