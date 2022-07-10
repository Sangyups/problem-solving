#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

#define endl '\n'
#define pii pair<int, int>

typedef long long ll;

using namespace std;

int T;
int N, Q;
map<int, pii > pos;
vector<pii > queries;

void preproc() {
}

void solution() {
  for (int i = 0; i < Q; ++i) {
    auto [x, y] = queries[i];
    int pos_x = pos[x].first;
    int pos_y = pos[y].second;
    if (pos_x == 0 || pos_y == 0) cout << "no" << endl;
    else if (pos_x < pos_y) cout << "yes" << endl;
    else cout << "no" << endl;
  }
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> T;

  while (T--) {
    cin >> N >> Q;
    for (int i = 0; i < N; ++i) {
      int n;
      cin >> n;
      if (pos[n].first == 0) pos[n].first = i + 1;
      else pos[n].first = min(pos[n].first, i + 1);

      if (pos[n].second == 0) pos[n].second = i + 1;
      else pos[n].second = max(pos[n].second, i + 1);
    }
    for (int i = 0; i < Q; ++i) {
      int a, b;
      cin >> a >> b;
      queries.push_back({a, b});
    }

    preproc();
    solution();
    pos.clear();
    queries.clear();
  }

}
