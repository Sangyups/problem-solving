#include <bits/stdc++.h>

#define endl '\n'
#define print(x) cout << x << endl
#define clearArray(arr, num) memset(arr, num, sizeof(arr))
#define clear2DArray(arr, num, row) \
    for (int i = 0; i < row; i++) { \
        clearArray(arr[i], num);    \
    }
#define pii pair<int, int>
#define FOR(i, a, b)
#define INF 987654321
typedef long long ll;
using namespace std;

#define MAX 100000
int N, M;
vector<int> comp[MAX];
int degree[MAX];
vector<int> ans;

void solution() {
    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (degree[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int tmp = q.front();
        q.pop();
        ans.push_back(tmp);
        for (auto next : comp[tmp]) {
            if (--degree[next] == 0) {
                q.push(next);
            }
        }
    }
    for (auto res : ans) {
        cout << res << ' ';
    }
    cout << endl;
}

int main(int argc, const char* argv[]) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        comp[a].push_back(b);
        degree[b]++;
    }

    solution();
}
