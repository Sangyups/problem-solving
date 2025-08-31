cat > ./main.cpp << 'EOF'
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

void solution() {
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
    string a;
    cin >> a;
    ////////////////////////////////////
    ////////////////////////////////////

    if constexpr (local) {
        cout << "#### OUTPUT ####" << endl;
        cout.flush();
    }

    solution();
}

EOF
echo "초기화가 완료되었습니다."
