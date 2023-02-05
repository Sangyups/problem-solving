#include <algorithm>
#include <iostream>
#include <vector>

#define endl '\n'
#define pii pair<int, int>

typedef long long ll;

using namespace std;

int N, M;
int people[1025][1025];
int K;
int ranges[100000][4];

void solution() {
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            people[i][j] += people[i - 1][j] + people[i][j - 1] - people[i - 1][j - 1];
        }
    }

    for (int i = 0; i < K; ++i) {
        int x1 = ranges[i][0];
        int y1 = ranges[i][1];
        int x2 = ranges[i][2];
        int y2 = ranges[i][3];
        cout << people[x2][y2] - people[x1 - 1][y2] - people[x2][y1 - 1] + people[x1 - 1][y1 - 1] << endl;
    }
}

int main(int argc, const char *argv[]) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N >> M;

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            cin >> people[i][j];
        }
    }

    cin >> K;

    for (int i = 0; i < K; ++i) {
        cin >> ranges[i][0] >> ranges[i][1] >> ranges[i][2] >> ranges[i][3];
    }

    solution();
}
