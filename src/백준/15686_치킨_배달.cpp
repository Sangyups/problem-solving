#include <algorithm>
#include <climits>
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

vector<pii> houses;
vector<pii> chickens;
vector<int> chosen;
int ans = INT_MAX;

int calc_dist(vector<pii> &chicken_combination) {
    int sum = 0;
    for (const auto &house : houses) {
        auto &[house_x, house_y] = house;
        int dist = INT_MAX;
        for (const auto &chicken : chicken_combination) {
            auto &[chicken_x, chicken_y] = chicken;
            dist = min(dist, abs(house_x - chicken_x) + abs(house_y - chicken_y));
        }
        sum += dist;
    }

    return sum;
}

void combination(int depth, int next, int M) {
    if (depth == M) {
        vector<pii> chicken_combinations(M);
        for (int i = 0; i < M; i++) {
            chicken_combinations[i] = chickens[chosen[i]];
            debug(chosen[i]);
        }
        debug("====");
        ans = min(ans, calc_dist(chicken_combinations));
        return;
    }

    for (int i = next; i < chickens.size(); i++) {
        chosen[depth] = i;
        combination(depth + 1, i + 1, M);
    }
}

void solution(vvi &map, int M) {
    for (int i = 0; i < map.size(); i++) {
        for (int j = 0; j < map.size(); j++) {
            if (map[i][j] == 1) {
                houses.push_back({i, j});
            } else if (map[i][j] == 2) {
                chickens.push_back({i, j});
            }
        }
    }

    chosen = vector<int>(M);
    combination(0, 0, M);
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
    int N, M;
    cin >> N >> M;
    vvi map(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }
    ////////////////////////////////////
    ////////////////////////////////////

#ifdef LOCAL
    cout << "#### OUTPUT ####" << endl;
    cout.flush();
#endif

    solution(map, M);
    cout << ans;
}
