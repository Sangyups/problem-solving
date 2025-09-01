#include <algorithm>
#include <iostream>
#include <vector>

#define endl '\n'

#ifdef LOCAL
constexpr bool local = true;
#else
constexpr bool local = false;
#endif
#define debug(x)                                            \
    if constexpr (local) {                                  \
        std::cout << "[DEBUG] " << #x << ": " << x << endl; \
    }
#define debugall(c)                                           \
    if constexpr (local) {                                    \
        std::cout << "[DEBUG] " << #c << ": ";                \
        for (const auto &elem : c) std::cout << elem << ", "; \
        std::cout << endl;                                    \
    }

using namespace std;

using pii = pair<int, int>;
using vvi = vector<vector<int>>;
using ll = long long;

void combination(int depth, int next, int r, vector<int> &arr, vector<int> &result) {
    if (depth == r) {
        for (int i = 0; i < r; i++) {
            cout << result[i] << ' ';
        }
        cout << endl;
        return;
    }

    for (int i = next; i < arr.size(); i++) {
        result[depth] = arr[i];
        combination(depth + 1, i, r, arr, result);

        while (i < arr.size() - 1 && arr[i] == arr[i + 1]) {
            i++;
        }
    }
}

void solution(vector<int> &arr, int r) {
    sort(arr.begin(), arr.end());
    vector<int> result(r);
    combination(0, 0, r, arr, result);
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    if constexpr (local) {
        cout << "#### INPUT ####" << endl;
        cout.flush();
    }

    /////////////////////////////////////
    // THIS IS WHERE YOU HANDLE INPUTS //
    /////////////////////////////////////
    int N, M;
    cin >> N >> M;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    /////////////////////////////////////
    /////////////////////////////////////

    if constexpr (local) {
        cout << "#### OUTPUT ####" << endl;
        cout.flush();
    }

    solution(arr, M);
}
