#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define endl '\n'
#define pii pair<int, int>

typedef long long ll;

using namespace std;

const int MAX = 1e5 + 1;

int N;

void clean_up() {}

void pre_proc() {}

void solution() {
    int mx[3];
    int mn[3];

    int a, b, c;
    cin >> a >> b >> c;
    mx[0] = a;
    mx[1] = b;
    mx[2] = c;
    mn[0] = a;
    mn[1] = b;
    mn[2] = c;

    for (int i = 1; i < N; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        int mx0 = max(mx[0], mx[1]);
        int mx1 = max({mx[0], mx[1], mx[2]});
        int mx2 = max(mx[1], mx[2]);

        int mn0 = min(mn[0], mn[1]);
        int mn1 = min({mn[0], mn[1], mn[2]});
        int mn2 = min(mn[1], mn[2]);

        mx[0] = mx0 + a;
        mx[1] = mx1 + b;
        mx[2] = mx2 + c;

        mn[0] = mn0 + a;
        mn[1] = mn1 + b;
        mn[2] = mn2 + c;
    }

    cout << max({mx[0], mx[1], mx[2]}) << ' ' << min({mn[0], mn[1], mn[2]})
         << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N;

    clean_up();
    pre_proc();
    solution();
}
