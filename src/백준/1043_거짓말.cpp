#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define endl '\n'
#define pii pair<int, int>

typedef long long ll;

using namespace std;

const int MAX = 55;

int N, M;
vector<int> real;
int checked[MAX][2];
vector<int> parties[MAX];
vector<int> attendance[MAX];
int cnt;

void clean_up() {}

void pre_proc() {}

void dfs(int p) {
    for (auto party : attendance[p]) {
        if (checked[party][1]) continue;
        checked[party][1] = 1;
        ++cnt;
        for (auto person : parties[party]) {
            if (checked[person][0]) continue;
            checked[p][0] = 1;
            dfs(person);
        }
    }
}

void solution() {
    for (auto person : real) {
        if (checked[person][0]) continue;
        checked[person][0] = 1;
        dfs(person);
    }
    cout << M - cnt << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N >> M;

    clean_up();

    int temp;
    cin >> temp;
    for (int i = 0; i < temp; ++i) {
        int num;
        cin >> num;
        real.push_back(num);
    }

    for (int i = 0; i < M; ++i) {
        cin >> temp;
        for (int j = 0; j < temp; ++j) {
            int num;
            cin >> num;
            parties[i].push_back(num);
            attendance[num].push_back(i);
        }
    }
    pre_proc();
    solution();
}
