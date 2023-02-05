#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define endl '\n'
#define pii pair<int, int>

typedef long long ll;

using namespace std;

#define MAX 70

int N;
int mat[MAX][MAX];

string solution(int sx, int sy, int size) {
    int temp = mat[sx][sy];
    string ans = "";
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (mat[sx + i][sy + j] != temp) {
                ans += "(";
                for (int k = 0; k < 2; ++k) {
                    for (int l = 0; l < 2; ++l) {
                        ans += solution(sx + (size / 2) * k, sy + (size / 2) * l, size / 2);
                    }
                }
                ans += ")";
                return ans;
            }
        }
    }
    return to_string(temp);
}

int main(int argc, const char *argv[]) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N;
    string s;

    for (int i = 0; i < N; ++i) {
        cin >> s;
        for (int j = 0; j < s.size(); ++j) {
            mat[i][j] = s[j] - 48;
        }
    }

    cout << solution(0, 0, N);
}
