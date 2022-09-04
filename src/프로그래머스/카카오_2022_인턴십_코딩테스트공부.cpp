#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 155;
const int INF = 1e9;

int dp[MAX][MAX];

int solution(int alp, int cop, vector<vector<int>> problems) {
  int MAX_ALP = 0, MAX_COP = 0;

  for (auto &prob : problems) {
    int alp_req = prob[0];
    int cop_req = prob[1];
    MAX_ALP = max(alp_req, MAX_ALP);
    MAX_COP = max(cop_req, MAX_COP);
  }
  
  alp = min(alp, MAX_ALP);
  cop = min(cop, MAX_COP);

  for (int i = alp; i <= MAX_ALP; ++i)
    for (int j = cop; j <= MAX_COP; ++j)
      dp[i][j] = INF;

  dp[alp][cop] = 0;

  for (int i = alp; i <= MAX_ALP; ++i) {
    for (int j = cop; j <= MAX_COP; ++j) {
      if (i + 1 <= MAX_ALP) dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
      if (j + 1 <= MAX_COP) dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + 1);

      for (auto &prob : problems) {
        int alp_req = prob[0];
        int cop_req = prob[1];
        int alp_rwd = prob[2];
        int cop_rwd = prob[3];
        int cost = prob[4];
        if (i < alp_req || j < cop_req) continue;
        int n_alp = min(MAX_ALP, i + alp_rwd);
        int n_cop = min(MAX_COP, j + cop_rwd);
        dp[n_alp][n_cop] = min(dp[n_alp][n_cop], dp[i][j] + cost);
      }
    }
  }
  return dp[MAX_ALP][MAX_COP];
}
