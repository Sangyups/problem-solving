#include <bits/stdc++.h>

#define endl '\n'
#define pii pair<int, int>

typedef long long ll;

using namespace std;

int N, M;

map<string, string> pw_list;

void clean_up() {}

void pre_proc() {}

void solution() {
    for (int i = 0; i < M; ++i) {
        string site;
        cin >> site;
        cout << pw_list[site] << endl;
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        string a, b;
        cin >> a >> b;
        pw_list.insert({a, b});
    }

    clean_up();
    pre_proc();
    solution();
}
