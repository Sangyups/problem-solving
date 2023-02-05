class Solution {
   public:
    int reverse(int x) {
        int answer = 0;

        while (x != 0) {
            if ((answer == 214748364 and x % 10 > 7) or answer > 214748364) {
                return 0;
            }
            if ((answer == -214748364 and x % 10 < -8) or answer < -214748364) {
                return 0;
            }
            answer = answer * 10 + x % 10;
            x /= 10;
        }
        return answer;
    }
};
