#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define endl '\n'
#define pii pair<int, int>

typedef long long ll;

using namespace std;

int T;
int N, K;
vector<int> chests;

void preproc() {
    chests.clear();
}

void solution() {
    ll temp = 0;
    for (int i = 0; i < min(N, 31); ++i) {
        int val = chests[i];
        val >>= i + 1;
        temp += val;
    }
    ll ans = temp;
    ll sum = 0;
    for (int i = 0; i < N; ++i) {
        sum += chests[i] - K;
        temp = sum;
        for (int j = i + 1; j < min(N, i + 32); ++j) {
            int val = chests[j];
            val >>= j - i;
            temp += val;
        }
        ans = max(ans, temp);
    }

    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> T;
    while (T--) {
        cin >> N >> K;
        preproc();

        for (int i = 0; i < N; ++i) {
            int n;
            cin >> n;
            chests.push_back(n);
        }
        solution();
    }
}
