class Solution {
   public:
    int maxArea(vector<int> &height) {
        int ans = 0;
        int s = 0, e = height.size() - 1;

        while (s < e) {
            int temp = min(height[s], height[e]) * (e - s);
            ans = max(temp, ans);
            if (height[s] < height[e]) ++s;
            else --e;
        }

        return ans;
    }
};
