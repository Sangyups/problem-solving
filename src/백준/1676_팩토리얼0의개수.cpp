#include <algorithm>
#include <iostream>
#include <vector>

#define endl '\n'
#define pii pair<int, int>

typedef long long ll;

using namespace std;

int N;

void solution() {
    int cnt = 0;
    for (int i = 1; i <= N; ++i) {
        int temp = i;
        while (temp % 5 == 0 && temp > 0) {
            ++cnt;
            temp /= 5;
        }
    }
    cout << cnt;
}

int main(int argc, const char *argv[]) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N;

    solution();
}