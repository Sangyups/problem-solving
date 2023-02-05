#include <algorithm>
#include <iostream>
#include <vector>

#define endl '\n'
#define pii pair<int, int>

typedef long long ll;

using namespace std;

ll M, N;
ll x, y;

ll gcd(ll a, ll b) {
    while (b != 0) {
        ll r = a % b;
        a = b;
        b = r;
    }
    return a;
}

ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}

void solution() {
    ll limit = lcm(M, N);
    if (x == M) x = 0;
    for (int i = 0;; ++i) {
        ll index = y + N * i;
        if (index > limit) break;
        if (index % M == x) {
            cout << index << endl;
            return;
        }
    }
    cout << -1 << endl;
}

int main(int argc, const char *argv[]) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;

    while (T--) {
        cin >> M >> N >> x >> y;
        solution();
    }
}
