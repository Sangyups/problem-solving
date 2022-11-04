class Solution {
   public:
    int is_vowel(char c) {
        if (c >= 'A' && c <= 'Z') {
            c += 'a' - 'A';
        }
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    string reverseVowels(string s) {
        string answer = s;
        vector<char> ch;
        for (int i = 0; i < s.size(); ++i) {
            if (is_vowel(s[i])) {
                ch.push_back(s[i]);
            }
        }
        int idx = ch.size() - 1;
        for (int i = 0; i < answer.size(); ++i) {
            if (is_vowel(s[i])) {
                answer[i] = ch[idx--];
            }
        }
        return answer;
    }
};
