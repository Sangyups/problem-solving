#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define endl '\n'
#define pii pair<int, int>

typedef long long ll;

using namespace std;

#define MAX 10005

int N;
pii arr[MAX];
int schedule[MAX];

void preproc() {
    sort(arr, arr + N, greater<>());
}

void solution() {
    int sum = 0;
    for (int i = 0; i < N; ++i) {
        auto [pay, day] = arr[i];
        while (day >= 1 && schedule[day]) day--;
        if (day >= 1) {
            schedule[day] = pay;
            sum += pay;
        }
    }
    cout << sum << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N;

    for (int i = 0; i < N; ++i) {
        int a, b;
        cin >> a >> b;
        arr[i] = {a, b};
    }

    preproc();
    solution();
}
