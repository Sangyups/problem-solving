#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define endl '\n'
#define pii pair<int, int>

typedef long long ll;

using namespace std;

#define MAX 200005

int T;
int N;
int flag;
vector<int> dominoes[MAX];
int visited[MAX];

void preproc() {
    for (int i = 1; i <= N; ++i) {
        dominoes[i].clear();
        visited[i] = 0;
    }
    flag = 0;
}

int dfs(int n) {
    visited[n] = 1;
    for (auto neigh : dominoes[n]) {
        if (visited[neigh]) continue;
        return dfs(neigh) + 1;
    }
    return 1;
}

void solution() {
    if (flag) {
        cout << "no" << endl;
        return;
    }

    for (int i = 1; i <= N; ++i) {
        if (visited[i]) continue;
        if (dfs(i) & 1) {
            cout << "no" << endl;
            return;
        }
    }
    cout << "yes" << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> T;

    while (T--) {
        cin >> N;
        preproc();

        for (int i = 0; i < N; ++i) {
            int a, b;
            cin >> a >> b;
            dominoes[a].push_back(b);
            dominoes[b].push_back(a);
            if (dominoes[a].size() > 2 || dominoes[b].size() > 2 || a == b) {
                flag = 1;
            }
        }
        solution();
    }
}
