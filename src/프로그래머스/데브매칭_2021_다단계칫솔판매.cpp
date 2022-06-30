#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
  vector<int> answer;
  map<string, int> m;
  vector<int> parent;

  for (int i = 0; i < enroll.size(); ++i) {
    m.insert({enroll[i], i});
    answer.push_back(0);

    if (referral[i] != "-") parent.push_back(m[referral[i]]);
    else parent.push_back(-1);
  }

  for (int i = 0; i < seller.size(); ++i) {
    int person = m[seller[i]];
    int money = amount[i] * 100;
    while (person != -1 and money != 0) {
      int fee = money / 10;
      answer[person] += money - fee;
      money = fee;
      person = parent[person];
    }
  }
  
  return answer;
}
