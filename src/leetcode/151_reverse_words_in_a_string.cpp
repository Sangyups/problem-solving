class Solution {
   public:
    string reverseWords(string s) {
        vector<string> temp;
        string answer;
        int idx = 0;

        string t = "";
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') {
                if (t != "") temp.push_back(t);
                t = "";
                continue;
            }
            t += s[i];
        }
        if (t != "") temp.push_back(t);

        for (int i = temp.size() - 1; i >= 0; --i) {
            answer += temp[i];
            if (i > 0) {
                answer += ' ';
            }
        }

        return answer;
    }
};
