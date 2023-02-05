class Solution {
   public:
    stack<int> st;

    int longestValidParentheses(string s) {
        int N = s.size();
        int answer = 0;
        vector<int> dp(N + 1);

        for (int i = 0; i < N; ++i) {
            if (s[i] == '(') st.push(i);
            else {
                if (not st.empty()) {
                    int n = i - st.top() + 1;
                    n += dp[st.top()];
                    st.pop();
                    dp[i + 1] = n;
                    answer = max(answer, n);
                }
            }
        }

        return answer;
    }
};
