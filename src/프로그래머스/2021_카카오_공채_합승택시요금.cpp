#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MAX = 205;
const int INF = 1e8;

int graph[MAX][MAX];
int dist[MAX][MAX];

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {

  for (auto fare : fares) {
    int c = fare[0];
    int d = fare[1];
    int f = fare[2];
    graph[c][d] = f;
    graph[d][c] = f;
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (i == j) dist[i][j] = 0;
      else if (graph[i][j]) dist[i][j] = graph[i][j];
      else dist[i][j] = INF;
    }
  }

  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  int answer = 1e9;

  for (int i = 1; i <= n; ++i) {
    answer = min(dist[s][i] + dist[i][a] + dist[i][b], answer);
  }

  return answer;
}
