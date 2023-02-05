#include <algorithm>
#include <iostream>
#include <vector>

#define endl '\n'
#define pii pair<int, int>

typedef long long ll;

using namespace std;

#define MAX 100002

int N;
pii arr[MAX];
int dp[MAX];
vector<int> outsider[MAX];

void solution() {
    dp[3] = arr[3].first - arr[0].first;
    outsider[0] = {arr[0].second};
    outsider[1] = {arr[0].second, arr[1].second};
    outsider[2] = {arr[0].second, arr[1].second, arr[2].second};
    for (int i = 4; i < N; ++i) {
        if (i % 4 == 3) {
            dp[i] = arr[i].first - arr[i - 3].first + dp[i - 4];
            continue;
        }

        if (dp[i - 1] > dp[i - 4] + arr[i].first - arr[i - 3].first) {
            dp[i] = dp[i - 4] + arr[i].first - arr[i - 3].first;
            for (auto o : outsider[i - 4]) outsider[i].push_back(o);
        } else {
            dp[i] = dp[i - 1];
            for (auto o : outsider[i - 1]) outsider[i].push_back(o);
            outsider[i].push_back(arr[i].second);
        }
    }
    cout << dp[N - 1] << endl;
    for (auto o : outsider[N - 1]) cout << o << endl;
}

int main(int argc, const char *argv[]) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N;

    for (int i = 0; i < N; ++i) {
        cin >> arr[i].first;
        arr[i].second = i;
    }

    sort(arr, arr + N);

    solution();
}