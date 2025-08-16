cat > ./main.cpp << EOF
#include <algorithm>
#include <iostream>
#include <vector>

#define endl '\n'

#ifdef LOCAL
#define debug(x) std::cout << "[DEBUG] " << #x << ": " << x << '\n'
#else
#define debug(x)
#endif

using namespace std;

using pii = pair<int, int>;
using vvi = vector<vector<int>>;
using ll = long long;

void solution() {
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

#ifdef LOCAL
    cout << "#### INPUT ####" << endl;
    cout.flush();
#endif

    ////////////////////////////////////
    // THIS IS WHERE YOU HANDLE INPUT //
    ////////////////////////////////////
    string a;
    cin >> a;
    ////////////////////////////////////
    ////////////////////////////////////

#ifdef LOCAL
    cout << "#### OUTPUT ####" << endl;
    cout.flush();
#endif

    solution();
}

EOF
echo "초기화가 완료되었습니다."
