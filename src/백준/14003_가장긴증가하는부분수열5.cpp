#include <algorithm>
#include <iostream>
#include <vector>

#define endl '\n'
#define pii pair<int, int>

typedef long long ll;

using namespace std;

#define MAX 1000001

int N;
int arr[MAX][2];

void solution() {
    vector<int> dp;
    dp.push_back(arr[0][0]);
    for (int i = 1; i < N; i++) {
        if (dp.back() < arr[i][0]) {
            dp.push_back(arr[i][0]);
            arr[i][1] = dp.size() - 1;
        } else {
            int idx = lower_bound(dp.begin(), dp.end(), arr[i][0]) - dp.begin();
            dp[idx] = arr[i][0];
            arr[i][1] = idx;
        }
    }
    int temp = dp.size() - 1;
    for (int i = N - 1; i >= 0; --i) {
        if (arr[i][1] == temp) {
            dp[temp--] = arr[i][0];
        }
    }
    cout << dp.size() << endl;
    for (auto num : dp) cout << num << ' ';
}

int main(int argc, const char *argv[]) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N;

    for (int i = 0; i < N; ++i) {
        cin >> arr[i][0];
    }

    solution();
}
