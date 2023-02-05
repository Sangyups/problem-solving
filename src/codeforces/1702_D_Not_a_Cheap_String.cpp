#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

#define endl '\n'
#define pii pair<int, int>

typedef long long ll;

using namespace std;

int T;
string w;
int p;

void preproc() {
}

void solution() {
    int curr_val = 0;
    priority_queue<pair<char, int>> pq;
    for (int i = 0; i < w.size(); ++i) {
        curr_val += w[i] - 'a' + 1;
        pq.push({w[i], i});
    }

    if (curr_val <= p) {
        cout << w << endl;
        return;
    }

    vector<int> deleted_idx;

    while (curr_val > p) {
        auto [c, v] = pq.top();
        pq.pop();
        deleted_idx.push_back(v);
        curr_val -= c - 'a' + 1;
    }
    sort(deleted_idx.begin(), deleted_idx.end());
    int j = 0;
    for (int i = 0; i < w.size(); ++i) {
        if (j < deleted_idx.size() && i == deleted_idx[j]) {
            j++;
            continue;
        }
        cout << w[i];
    }
    cout << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> T;

    while (T--) {
        cin >> w;
        cin >> p;

        preproc();
        solution();
    }
}
