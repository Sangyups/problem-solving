use std::cmp;

impl Solution {
    pub fn rob(nums: Vec<i32>) -> i32 {
        let mut dp = Vec::with_capacity(nums.len());

        for (i, num) in nums.iter().enumerate() {
            let current_max = match i {
                0 => nums[0],
                1 => cmp::max(nums[0], nums[1]),
                _ => cmp::max(dp[i - 1], dp[i - 2] + num),
            };

            dp.push(current_max);
        }

        dp[dp.len() - 1]
    }
}

