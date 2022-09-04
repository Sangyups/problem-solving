#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

#define pii pair<int, int>

using namespace std;

const int MAX = 50005;

vector<pii > graph[MAX];
int visited[MAX];
int is_summit[MAX];
int N;

int get_path(int mid, vector<int> gates, vector<int> summits) {
  memset(visited, 0, sizeof(int) * (N + 1));
  queue<int> q;

  for (auto &gate : gates) {
    visited[gate] = 1;
    q.push(gate);
  }

  while (!q.empty()) {
    int curr_node = q.front();
    q.pop();
    for (auto &g : graph[curr_node]) {
      auto [next_node, cost] = g;
      if (visited[next_node]) continue;
      if (cost > mid) continue;

      visited[next_node] = 1;
      if (!is_summit[next_node])
        q.push(next_node);

    }
  }

  for (auto summit : summits) {
    if (visited[summit]) return summit;
  }

  return 0;
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
  vector<int> answer;
  answer.push_back(0);
  answer.push_back(1);
  sort(summits.begin(), summits.end());
  int MAX_INTENSITY = 0;
  N = n;
  for (auto &path : paths) {
    MAX_INTENSITY = max(path[2], MAX_INTENSITY);
    graph[path[0]].push_back({path[1], path[2]});
    graph[path[1]].push_back({path[0], path[2]});
  }

  for (auto &summit : summits) {
    is_summit[summit] = 1;
  }

  int left = 0, right = MAX_INTENSITY;
  while (left <= right) {
    int mid = (left + right) / 2;
    int temp = get_path(mid, gates, summits);
    if (temp) {
      right = mid - 1;
      answer[0] = temp;
      answer[1] = mid;
    } else {
      left = mid + 1;
    }
  }
  return answer;
}
