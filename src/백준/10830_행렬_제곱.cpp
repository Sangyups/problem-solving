#include <iostream>
#include <vector>

#define endl '\n'

#ifdef LOCAL
#define debug(x) std::cout << "[DEBUG] " << #x << ": " << x << '\n'
#else
#define debug(x)
#endif

using namespace std;

using pii = pair<int, int>;
using ll = long long;

vector<vector<int>> multiply(const vector<vector<int>> &a, const vector<vector<int>> &b) {
    auto n = a.size();
    vector<vector<int>> res(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                res[i][j] += a[i][k] * b[k][j];
            }
            res[i][j] %= 1000;
        }
    }

    return res;
}

vector<vector<int>> solution(int n, ll b, vector<vector<int>> a) {
    vector<vector<int>> ans(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        ans[i][i] = 1;
    }

    while (b > 0) {
        if (b % 2) {
            ans = multiply(ans, a);
        }
        a = multiply(a, a);

        b /= 2;
    }

    return ans;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

#ifdef LOCAL
    cout << "#### INPUT ####" << endl;
    cout.flush();
#endif

    ////////////////////////////////////
    // THIS IS WHERE YOU HANDLE INPUT //
    ////////////////////////////////////
    int n;
    ll b;
    cin >> n >> b;

    vector<vector<int>> a(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    ////////////////////////////////////
    ////////////////////////////////////

#ifdef LOCAL
    cout << "#### OUTPUT ####" << endl;
    cout.flush();
#endif

    auto ans = solution(n, b, a);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans.size(); j++) {
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }
}
