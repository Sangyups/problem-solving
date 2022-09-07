#include <iostream>
#include <string>
#include <vector>

typedef long long ll;

using namespace std;

const int MAX = 200005;

int N;
int stones_global[MAX];

int solution(vector<int> stones, int k) {
  int answer = 0;
  ll sum = 0;
  N = stones.size();
  int left = 1, right = 2e9;

  while (left <= right) {
    int mid = (left + right) / 2;

    ll sum = 0;
    int cnt = 0, flag = 0;
    for (int i = 0; i < N; ++i) {
      sum += (stones[i] > mid ? stones[i] : 0);
      ++cnt;
      if (cnt == k) {
        if (sum == 0) {
          flag = 1;
          break;
        }
      }
      if (cnt > k) {
        sum -= (stones[i - k] > mid ? stones[i - k] : 0);
        if (sum == 0) {
          flag = 1;
          break;
        }
      }
    }

    if (flag) {
      right = mid - 1;
      answer = mid;
    } else {
      left = mid + 1;
    }
  }
  return answer;
}
