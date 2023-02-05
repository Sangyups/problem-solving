typedef long long ll;

class Solution {
   public:
    int myAtoi(string s) {
        const ll MAX = (1L << 31) - 1;
        const ll MIN = -(1L << 31);
        ll answer = 0;
        int negative = 0;
        int flag = 0;
        for (auto &c : s) {
            int temp = 0;
            if (c == '-' && !flag) {
                negative = 1;
                flag = 1;
            } else if (c == '+' && !flag) {
                negative = 0;
                flag = 1;
            } else if (c == ' ' && !flag)
                continue;
            else if (c >= '0' && c <= '9') {
                temp = c - '0';
                flag = 1;
            } else
                break;

            if (!negative && answer > MAX) {
                answer = MAX;
                break;
            } else if (negative && answer > -MIN) {
                answer = -MIN;
                break;
            }
            answer = answer * 10 + temp;
        }
        if (negative) answer *= -1;
        if (answer > MAX)
            answer = MAX;
        else if (answer < MIN)
            answer = MIN;
        return answer;
    }
};
