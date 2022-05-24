#include <string>
#include <vector>

using namespace std;

int damage[1001][1001];

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
  int answer = 0;

  for (auto s: skill) {
    if (s[0] == 1) s[5] = -s[5];
    damage[s[1]][s[2]] += s[5];
    damage[s[1]][s[4] + 1] -= s[5];
    damage[s[3] + 1][s[2]] -= s[5];
    damage[s[3] + 1][s[4] + 1] += s[5];
  }

  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[0].size(); j++) {
      if (i == 0) damage[i][j] += damage[i][j - 1];
      else if (j == 0) damage[i][j] += damage[i - 1][j];
      else damage[i][j] += damage[i - 1][j] + damage[i][j - 1] - damage[i - 1][j - 1];
      if (board[i][j] + damage[i][j] > 0) answer++;
    }
  }

  return answer;
}