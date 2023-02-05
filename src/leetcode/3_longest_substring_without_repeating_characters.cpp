#define MAX 50005

class Solution {
   public:
    int dp[MAX];
    unordered_map<char, int> m;
    int lengthOfLongestSubstring(string s) {
        int answer = 0;

        for (int i = 0; i < s.size(); ++i) {
            if (m.count(s[i]) == 0) {
                m[s[i]] = i;
                dp[i + 1] = dp[i] + 1;
            } else {
                dp[i + 1] = min(i - m[s[i]], dp[i] + 1);
                m[s[i]] = i;
            }
            answer = max(dp[i + 1], answer);
        }
        return answer;
    }
};
