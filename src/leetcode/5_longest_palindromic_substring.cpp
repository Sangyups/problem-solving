#define MAX 1005

class Solution {
 public:
  int dp[MAX][MAX];
  int N;
  int start = 0, end = 0;
  string longestPalindrome(string s) {
    memset(dp, 0, sizeof(dp));
    N = s.size();
    string ans = "";
    for (int i = 0; i < N; ++i) {
      dp[i][i] = 1;
      if (i < N - 1 and s[i] == s[i + 1]) {
        dp[i][i + 1] = 1;
        start = i;
        end = i + 1;
      }
    }

    for (int k = 2; k < N; ++k) {
      for (int i = 0; i < N - k; ++i) {
        int j = i + k;
        if (dp[i + 1][j - 1] == 1 and s[i] == s[j]) {
          dp[i][j] = 1;
          start = i;
          end = j;
        }
      }
    }
    
    for (int i = start; i <= end; ++i) {
      ans += s[i];
    }
    return ans;
  }
};
