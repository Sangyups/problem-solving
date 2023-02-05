#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define endl '\n'
#define pii pair<int, int>

typedef long long ll;

using namespace std;

#define MAX (1000 + 5)

int N;
int arr[MAX];

void clean_up() {
}

void pre_proc() {
    arr[1] = 1;
    arr[2] = 3;
}

void solution() {
    for (int i = 3; i <= N; ++i) {
        arr[i] = (arr[i - 1] + arr[i - 2] * 2) % 10007;
    }
    cout << arr[N];
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N;

    clean_up();
    pre_proc();
    solution();
}
