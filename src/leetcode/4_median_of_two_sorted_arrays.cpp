#define MX 1987654321
#define MN -1987654321

class Solution {
 public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    vector<int> arr;
    int N, M;
    N = nums1.size();
    M = nums2.size();
    if (N > M) {
      return findMedianSortedArrays(nums2, nums1);
    }
    int partition_size = (N + M + 1) / 2;
    int start = 0;
    int end = N;
    while (start <= end) {
      int num1_idx = (start + end) / 2;
      int num2_idx = partition_size - num1_idx;

      int max_left1 = MN;
      int min_right1 = MX;
      if (num1_idx != 0) max_left1 = nums1[num1_idx - 1];
      if (num1_idx != N) min_right1 = nums1[num1_idx];

      int max_left2 = MN;
      int min_right2 = MX;
      if (num2_idx != 0) max_left2 = nums2[num2_idx - 1];
      if (num2_idx != M) min_right2 = nums2[num2_idx];

      if (max_left1 <= min_right2 && max_left2 <= min_right1) {
        if ((N + M) & 1) {
          return max(max_left1, max_left2);
        } else {
          return (max(max_left2, max_left1) + min(min_right1, min_right2)) / 2.0;
        }
      } else if (max_left1 > min_right2) {
        end = num1_idx - 1;
      } else {
        start = num1_idx + 1;
      }
    }

    // correct input cannot reach here
    return 1.0;
  }
};