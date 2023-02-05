#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#define endl '\n'
#define pii pair<int, int>

typedef long long ll;

using namespace std;

int T, N;
string s;
int solved[30];

void preproc() {
    memset(solved, 0, sizeof(solved));
}

void solution() {
    int sum = 0;
    for (int i = 0; i < N; ++i) {
        sum++;
        if (!solved[s[i] - 'A']) {
            sum++;
            solved[s[i] - 'A'] = 1;
        }
    }
    cout << sum << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> T;

    while (T--) {
        cin >> N;
        cin >> s;
        preproc();
        solution();
    }
}
