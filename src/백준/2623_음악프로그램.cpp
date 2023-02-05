#include <bits/stdc++.h>

#define endl '\n'
#define print(x) cout << x << endl
#define clearArray(arr, num) memset(arr, num, sizeof(arr))
#define clear2DArray(arr, num, row) \
    for (int i = 0; i < row; i++) { \
        clearArray(arr[i], num);    \
    }
#define pii pair<int, int>
#define INF 1987654321
typedef long long ll;
using namespace std;

const int MAX = 1001;
int N, M;
int ans[MAX];
vector<int> arr[MAX];
int degree[MAX];

void solution() {
    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (degree[i] == 0) {
            q.push(i);
        }
    }
    for (int i = 1; i <= N; i++) {
        if (q.empty()) {
            print(0);
            return;
        }
        int tmp = q.front();
        ans[i] = tmp;
        q.pop();
        for (auto a : arr[tmp]) {
            if (--degree[a] == 0) {
                q.push(a);
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        print(ans[i]);
    }
}

int main(int argc, const char* argv[]) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int n, first;
        cin >> n >> first;
        for (int j = 0; j < n - 1; j++) {
            int m;
            cin >> m;
            arr[first].push_back(m);
            degree[m]++;
            first = m;
        }
    }

    solution();
}
