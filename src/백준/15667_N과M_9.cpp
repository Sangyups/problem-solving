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

vector<int> arr;
vector<int> chosen;
vector<bool> visited;

void combination(int depth, int r) {
    if (depth == r) {
        for (int i = 0; i < r; i++) {
            cout << chosen[i] << ' ';
        }
        cout << endl;
        return;
    }

    for (int i = 0; i < arr.size(); i++) {
        if (visited[i]) {
            continue;
        }
        chosen[depth] = arr[i];
        visited[i] = true;
        combination(depth + 1, r);
        visited[i] = false;

        while (i < arr.size() - 1 && arr[i] == arr[i + 1]) {
            i++;
        }
    }
}

void solution(vector<int> &arr, int M) {
    sort(arr.begin(), arr.end());

    chosen = vector<int>(M);
    combination(0, M);
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    if constexpr (local) {
        cout << "#### INPUT ####" << endl;
        cout.flush();
    }

    ////////////////////////////////////
    // THIS IS WHERE YOU HANDLE INPUT //
    ////////////////////////////////////
    int N, M;
    cin >> N >> M;

    arr = vector<int>(N);
    visited = vector<bool>(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    ////////////////////////////////////
    ////////////////////////////////////

    if constexpr (local) {
        cout << "#### OUTPUT ####" << endl;
        cout.flush();
    }

    solution(arr, M);
}
