#include <bits/stdc++.h>

#define endl '\n'
#define print(x) cout << x << endl
#define clearArray(arr, num) memset(arr, num, sizeof(arr))
#define clear2DArray(arr, num, row) \
    for (int i = 0; i < row; i++) { \
        clearArray(arr[i], num);    \
    }
#define pii pair<int, int>
const int INF = 1987654321;
typedef long long ll;
using namespace std;

const int MAX = 1002;
int N;
string str1 = "a", str2 = "b";
int len1, len2;
int dp[MAX][MAX];

void solution() {
    for (int i = 1; i < len1; i++) {
        for (int j = 1; j < len2; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if (str1[i] == str2[j]) {
                dp[i][j] = max(dp[i - 1][j - 1] + 1, dp[i][j]);
            }
        }
    }
    int ans_len = dp[len1 - 1][len2 - 1];
    cout << ans_len << endl;
    if (ans_len == 0) return;

    // for (int i = 0; i < len1; i++) {
    //   for (int j = 0; j < len2; j++) {
    //     cout << dp[i][j] << ' ';
    //   }
    //   cout << endl;
    // }

    char ans[ans_len];

    for (int i = len1 - 1; i > 0; i--) {
        for (int j = len2 - 1; j > 0; j--) {
            if (dp[i][j] == dp[len1 - 1][len2 - 1] && str1[i] == str2[j]) {
                ans[--dp[len1 - 1][len2 - 1]] = str1[i];
                break;
            }
        }
    }
    for (int i = 0; i < ans_len; i++) {
        cout << ans[i];
    }
    cout << endl;
}

int main(int argc, const char* argv[]) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string a, b;
    cin >> a >> b;
    str1.append(a);
    str2.append(b);
    len1 = int(str1.length());
    len2 = int(str2.length());

    solution();
}
