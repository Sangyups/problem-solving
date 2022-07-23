#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define endl '\n'
#define pii pair<int, int>

typedef long long ll;

using namespace std;

#define MAX 105
#define INF 1e9

int mat[MAX][MAX];
int dist[MAX][MAX];
int N;

void clean_up() {
}

void pre_proc() {
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (mat[i][j]) dist[i][j] = mat[i][j];
      else dist[i][j] = INF;
    }
  }
}

void solution() {
  for (int k = 0; k < N; ++k) {
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cout << (dist[i][j] != INF ? 1 : 0) << ' ';
    }
    cout << endl;
  }
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> N;
  clean_up();

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> mat[i][j];
    }
  }
  pre_proc();
  solution();
}
