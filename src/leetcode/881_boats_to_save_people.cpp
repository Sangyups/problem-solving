class Solution {
   public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());

        int N = people.size();
        int start = 0;
        int end = N - 1;
        int answer = 0;

        while (start <= end) {
            if (people[end] + people[start] <= limit) {
                ++start;
            }
            --end;
            ++answer;
        }

        return answer;
    }
};
