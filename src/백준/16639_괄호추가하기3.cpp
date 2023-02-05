#include <algorithm>
#include <iostream>
#include <vector>

#define endl '\n'
#define pii pair<int, int>

typedef long long ll;

using namespace std;

#define MAX 25

int N;
int num_n;
int op_n;
ll nums[MAX];
char ops[MAX];
ll mn[MAX][MAX];
ll mx[MAX][MAX];
string s;

void preproc() {
    fill(&mn[0][0], &mn[MAX - 1][MAX], 3500000000);
    fill(&mx[0][0], &mx[MAX - 1][MAX], -3500000000);
}

ll calc(ll a, ll b, char op) {
    if (op == '*') return a * b;
    if (op == '+') return a + b;
    if (op == '-') return a - b;
}

void solution() {
    for (int gap = 1; gap < num_n; ++gap) {
        for (int i = 0; i < num_n - gap; ++i) {
            int j = i + gap;
            for (int k = i; k < j; ++k) {
                mx[i][j] = max(mx[i][j], calc(mx[i][k], mx[k + 1][j], ops[k]));
                mx[i][j] = max(mx[i][j], calc(mx[i][k], mn[k + 1][j], ops[k]));
                mx[i][j] = max(mx[i][j], calc(mn[i][k], mn[k + 1][j], ops[k]));
                mx[i][j] = max(mx[i][j], calc(mn[i][k], mx[k + 1][j], ops[k]));

                mn[i][j] = min(mn[i][j], calc(mn[i][k], mn[k + 1][j], ops[k]));
                mn[i][j] = min(mn[i][j], calc(mn[i][k], mx[k + 1][j], ops[k]));
                mn[i][j] = min(mn[i][j], calc(mx[i][k], mx[k + 1][j], ops[k]));
                mn[i][j] = min(mn[i][j], calc(mx[i][k], mn[k + 1][j], ops[k]));
                // cout << "max " << i << ' ' << k << ' ' << j << ' ' << calc(mx[i][k], mx[k + 1][j], ops[k]) << endl;
                // cout << "min " << i << ' ' << k << ' ' << j << ' ' << calc(mn[i][k], mn[k + 1][j], ops[k]) << endl;
            }
        }
    }
    cout << max(mx[0][num_n - 1], mn[0][num_n - 1]) << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    preproc();

    int N;

    cin >> N;
    num_n = N / 2 + 1;
    op_n = N / 2;

    cin >> s;

    int j = 0, k = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (i % 2 == 0) {
            nums[j] = ll(s[i] - '0');
            mn[j][j] = nums[j];
            mx[j][j] = nums[j];
            j++;
        } else {
            ops[k] = s[i];
            ++k;
        }
    }

    solution();
}
