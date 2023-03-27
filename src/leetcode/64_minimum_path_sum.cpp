#define MAX 205
#define INF 2e9

class Solution {
   public:
    int dp[MAX][MAX];
    int N, M;
    int minPathSum(vector<vector<int>>& grid) {
        N = grid.size();
        M = grid[0].size();

        fill(&dp[0][0], &dp[MAX - 1][MAX], INF);
        dp[0][1] = 0;

        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= M; ++j) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];
            }
        }

        return dp[N][M];
    }
};
