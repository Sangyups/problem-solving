class Solution {
   public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }

        string answer = "";
        int N = s.size();
        int total_gap = numRows * 2 - 2;

        for (int i = 0; i < numRows; ++i) {
            int gap2 = 2 * i;
            int gap1 = total_gap - gap2;
            int gap = gap1;
            if (gap1 == 0) gap = gap2;
            for (int j = i; j < N;) {
                answer += s[j];
                j += gap;
                if (gap == gap1 and gap2 != 0) gap = gap2;
                else if (gap == gap2 and gap1 != 0) gap = gap1;
            }
        }

        return answer;
    }
};
