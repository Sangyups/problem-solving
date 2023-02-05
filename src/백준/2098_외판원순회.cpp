#include <bits/stdc++.h>

#define endl '\n'
#define print(x) cout << x << endl
#define clearArray(arr, num) memset(arr, num, sizeof(arr))
#define clear2DArray(arr, num, row) \
    for (int i = 0; i < row; i++) { \
        clearArray(arr[i], num);    \
    }
#define pii pair<int, int>
#define ll long long
#define INF 987654321
using namespace std;

#define MAX 16
int N;
int W[MAX][MAX];
int dp[MAX][1 << MAX];

int solution(int cur, int visited) {
    if (dp[cur][visited] != -1) {
        return dp[cur][visited];
    }

    if (visited == (1 << N) - 1) {
        if (W[cur][0] == INF) return INF;
        return W[cur][0];
    }

    dp[cur][visited] = INF;

    for (int i = 0; i < N; i++) {
        if (visited & (1 << i) || W[cur][i] == INF) {
            continue;
        }
        dp[cur][visited] =
            min(dp[cur][visited], solution(i, visited | 1 << i) + W[cur][i]);
    }

    return dp[cur][visited];
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N;
    clear2DArray(dp, -1, MAX);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int n;
            cin >> n;
            if (n == 0) n = INF;
            W[i][j] = n;
        }
    }
    cout << solution(0, 1);

    return 0;
}
