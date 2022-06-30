class Solution {
 public:
  vector<string> answer;
  void solution(int start, int end, string s) {
    if (start == 0 and end == 0) {
      answer.push_back(s);
      return;
    }

    if (start > 0) {
      solution(start - 1, end, s + "(");
    }
    if (end > 0 and end > start) {
      solution(start, end - 1, s + ")");
    }
  }

  vector<string> generateParenthesis(int n) {
    solution(n, n, "");
    
    return answer;
  }
};
