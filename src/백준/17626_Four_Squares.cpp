#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

#define endl '\n'
#define pii pair<int, int>

typedef long long ll;

using namespace std;

const int MAX = 50000 + 5;

int N;
int arr[MAX];

void clean_up() {}

void pre_proc() {}

void solution() {
    arr[1] = 1;
    for (int i = 2; i <= N; ++i) {
        arr[i] = 4;
        int temp = sqrt(i);
        if (temp * temp == i) arr[i] = 1;
        for (int j = 1; j * j <= i; ++j) {
            arr[i] = min(arr[i], arr[j * j] + arr[i - j * j]);
        }
    }

    cout << arr[N] << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N;

    clean_up();
    pre_proc();
    solution();
}
