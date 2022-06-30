#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

map<int, int> m = {
    {6, 1},
    {5, 2},
    {4, 3},
    {3, 4},
    {2, 5},
    {1, 6},
    {0, 6}
};

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
  vector<int> answer;
  int zeros = 0;
  int correct = 0;
  for (auto num : lottos) {
    if (!num) {
      zeros++;
      continue;
    }
    int idx = distance(win_nums.begin(), find(win_nums.begin(), win_nums.end(), num));
    if (idx < win_nums.size()) correct++;
  }

  answer.push_back(m[correct + zeros]);
  answer.push_back(m[correct]);

  return answer;
}
