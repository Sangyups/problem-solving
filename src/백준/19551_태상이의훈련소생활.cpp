#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

#define endl '\n'
#define pii pair<int, int>
#define tiii tuple<int, int, int>

typedef long long ll;

using namespace std;

#define MAX 100002

int N, M;
int height[MAX];
int d_height[MAX];
tiii instruction[MAX];

void solution() {
    for (auto inst : instruction) {
        auto [a, b, k] = inst;
        d_height[a] += k;
        d_height[b + 1] -= k;
    }
    for (int i = 1; i <= N; i++) {
        height[i] += d_height[i];
        cout << height[i] << ' ';
        d_height[i + 1] += d_height[i];
    }
}

int main(int argc, const char *argv[]) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> height[i];
    }

    for (int i = 0; i < M; i++) {
        int a, b, k;
        cin >> a >> b >> k;
        instruction[i] = make_tuple(a, b, k);
    }

    solution();
}
