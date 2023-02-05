#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

#define endl '\n'
#define pii pair<int, int>

typedef long long ll;

using namespace std;

#define MAX 105

int n;
ll arr[MAX] = {1, 1, 1, 2, 2, 3, 4, 5, 7, 9, 12};

ll solution(int n) {
    if (arr[n]) return arr[n];
    arr[n] = solution(n - 1) + solution(n - 5);
    return arr[n];
}

int main(int argc, const char *argv[]) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int T;

    cin >> T;

    while (T--) {
        cin >> n;
        cout << solution(n - 1) << endl;
    }
}
