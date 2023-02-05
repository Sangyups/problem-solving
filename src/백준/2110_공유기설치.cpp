#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define endl '\n'
#define pii pair<int, int>

typedef long long ll;

using namespace std;

#define MAX (200000 + 5)

int N, C;
int arr[MAX];

void clean_up() {
}

void pre_proc() {
    sort(&arr[0], &arr[N]);
}

void solution() {
    int first = 1;
    int last = arr[N - 1];
    int ans;
    while (first <= last) {
        int gap = (first + last) / 2;
        int cnt = 1;
        int prev = arr[0];
        for (int i = 1; i < N; ++i) {
            if (arr[i] - prev < gap) {
                if (i == N - 1) last = gap - 1;
                continue;
            }
            cnt++;
            prev = arr[i];
            if (cnt == C) {
                first = gap + 1;
                ans = gap;
                break;
            }
            if (i == N - 1) last = gap - 1;
        }
    }
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N >> C;
    clean_up();

    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }
    pre_proc();
    solution();
}
