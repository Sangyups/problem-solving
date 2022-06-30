class Solution {
 public:
  int N;
  int jump(vector<int> &nums) {
    N = nums.size();
    int cnt = 0, curr_max = 0, next_max = 0;
    for (int i = 0; i < N; ++i) {
      next_max = max(i + nums[i], next_max);

      if (i == curr_max and i != N - 1) {
        cnt++;
        curr_max = next_max;
      }
    }
    
    return cnt;
  }
};
