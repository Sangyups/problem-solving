#include <bits/stdc++.h>

#define endl '\n'
#define pii pair<int, int>

typedef long long ll;

using namespace std;

const int MAX = 1000005;
int N;
int tree[MAX];

void clean_up() {
}

void pre_proc() {
}

void post_order(int start, int end) {
    if (start >= end) return;
    if (start == end - 1) {
        cout << tree[start] << endl;
        return;
    }
    int idx = start + 1;
    while (idx < end && tree[start] > tree[idx]) ++idx;

    post_order(start + 1, idx);
    post_order(idx, end);
    cout << tree[start] << endl;
}

void solution() {
    post_order(0, N);
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int num;
    int idx = 0;
    while (true) {
        cin >> num;
        if (cin.eof()) break;
        tree[idx++] = num;
    }
    N = idx;

    clean_up();
    pre_proc();
    solution();
}
