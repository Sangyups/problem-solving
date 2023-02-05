#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

#define endl '\n'
#define pii pair<int, int>

typedef long long ll;

using namespace std;

int T, N;
vector<string> original_s;
set<string> ss;

void preproc() {
    original_s.clear();
    ss.clear();
}

void solution() {
    string ans = "";
    for (auto s : original_s) {
        string s1, s2;
        int flag = 0;
        for (int i = 1; i < s.size(); ++i) {
            s1 = s.substr(0, i);
            s2 = s.substr(i);
            if (ss.find(s1) != ss.end() && ss.find(s2) != ss.end()) {
                flag = 1;
                break;
            }
        }
        if (flag) ans += '1';
        else ans += '0';
    }
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> T;

    while (T--) {
        cin >> N;
        preproc();
        for (int i = 0; i < N; ++i) {
            string s;
            cin >> s;
            original_s.push_back(s);
            ss.insert(s);
        }
        solution();
    }
}
