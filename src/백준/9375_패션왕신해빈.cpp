#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

#define endl '\n'
#define pii pair<int, int>

typedef long long ll;

using namespace std;

int n;
map<string, int> clothes;

void solution() {
    int answer = 1;
    for (auto cloth : clothes) {
        answer *= (cloth.second + 1);
    }
    cout << answer - 1 << endl;
}

int main(int argc, const char *argv[]) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;

    while (T--) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            string cloth, type;
            cin >> cloth >> type;
            clothes[type]++;
        }
        solution();
        clothes.clear();
    }
}