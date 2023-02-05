#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

#define endl '\n'
#define pii pair<int, int>

typedef long long ll;

using namespace std;

#define MAX 2000001

int N;
int arr[MAX];

void solution() {
    int cnt = 1;

    for (int i = 1; i <= (N + 1) / 2; ++i) {
        cnt += int(log2(arr[i]));
    }
    cout << cnt << endl;
}

int main(int argc, const char *argv[]) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N;

    for (int i = 1; i <= N; ++i) {
        cin >> arr[i];
    }

    sort(arr + 1, arr + 1 + N);

    solution();
}