#include <iostream>
#include <string>
#include <vector>

#define PILLAR 0
#define BEAM 1

using namespace std;

const int MAX = 105;

int N;
int grid[MAX][MAX][2];

int is_valid(int x, int y, int type, int build) {
  if (build & !grid[x][y][type]) return 1;

  if (type == PILLAR) {
    if (build) {
      if (x == N - 1) return 1;
      if (grid[x + 1][y][PILLAR]) return 1;
      if (grid[x][y][BEAM] | grid[x][y - 1][BEAM]) return 1;
    } else {
      return is_valid(x - 1, y, PILLAR, 1) & is_valid(x - 1, y - 1, BEAM, 1) &
             is_valid(x - 1, y, BEAM, 1);
    }
  } else {
    if (build) {
      if (grid[x + 1][y][PILLAR] | grid[x + 1][y + 1][PILLAR]) return 1;
      if (grid[x][y - 1][BEAM] & grid[x][y + 1][BEAM]) return 1;
    } else {
      return is_valid(x, y, PILLAR, 1) & is_valid(x, y + 1, PILLAR, 1) &
             is_valid(x, y - 1, BEAM, 1) & is_valid(x, y + 1, BEAM, 1);
    }
  }
  return 0;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
  vector<vector<int>> answer;

  N = n + 1;
  for (auto frame : build_frame) {
    int y = frame[0];
    int x = N - 1 - frame[1];
    int type = frame[2];
    int build = frame[3];

    if (build) grid[x][y][type] = 1;
    else grid[x][y][type] = 0;

    if (is_valid(x, y, type, build)) continue;

    if (build) grid[x][y][type] = 0;
    else grid[x][y][type] = 1;
  }

  for (int j = 0; j < N; ++j) {
    for (int i = N - 1; i >= 0; --i) {
      if (grid[i][j][PILLAR]) {
        vector<int> temp = {j, N - 1 - i, PILLAR};
        answer.push_back(temp);
      }
      if (grid[i][j][BEAM]) {
        vector<int> temp = {j, N - 1 - i, BEAM};
        answer.push_back(temp);
      }
    }
  }
  return answer;
}
