#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#define endl '\n'
#define pii pair<int, int>

typedef long long ll;

using namespace std;

int T;
string s;

void preproc() {
}

void solution() {
    int days = 1;
    char arr[3] = {0, 0, 0};
    for (int i = 0; i < s.size(); ++i) {
        int flag = 1;
        for (int j = 0; j < 3; ++j) {
            if (arr[j] == 0 || arr[j] == s[i]) {
                arr[j] = s[i];
                flag = 0;
                break;
            }
        }
        if (flag) {
            days++;
            memset(arr, 0, sizeof(arr));
            arr[0] = s[i];
        }
    }

    cout << days << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> T;

    while (T--) {
        cin >> s;
        preproc();
        solution();
    }
}
