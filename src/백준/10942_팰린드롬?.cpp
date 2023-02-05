#include <algorithm>
#include <iostream>
#include <vector>

#define endl '\n'
#define pii pair<int, int>

typedef long long ll;

using namespace std;

int N, M;
int arr[2001];
int dp[2001][2001];

void solution() {
    for (int i = 1; i < N; ++i) {
        if (arr[i] == arr[i + 1]) dp[i][i + 1] = 1;
    }
    for (int k = 2; k <= N - 1; ++k) {
        for (int i = 1; i <= N - k; ++i) {
            int j = i + k;
            if (arr[i] == arr[j] and dp[i + 1][j - 1])
                dp[i][j] = 1;
        }
    }
}

int main(int argc, const char *argv[]) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N;

    for (int i = 1; i <= N; ++i) {
        cin >> arr[i];
        dp[i][i] = 1;
    }

    solution();

    cin >> M;

    for (int i = 0; i < M; ++i) {
        int s, e;
        cin >> s >> e;
        cout << dp[s][e] << endl;
    }
}
