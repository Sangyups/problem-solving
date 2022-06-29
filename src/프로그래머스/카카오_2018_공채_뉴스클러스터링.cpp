#include <string>
#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

multiset<string> get_multiset(string s) {
  multiset<string> string_set;

  for (int i = 0; i < s.size() - 1; ++i) {
    string temp = s.substr(i, 2);
    if (temp[0] >= 'a' and temp[0] <= 'z' and temp[1] >= 'a' and temp[1] <= 'z')
      string_set.insert(temp);
  }

  return string_set;
}

int solution(string str1, string str2) {
  int answer = 0;
  transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
  transform(str2.begin(), str2.end(), str2.begin(), ::tolower);

  multiset<string> A = get_multiset(str1);
  multiset<string> B = get_multiset(str2);

  multiset<string> AunionB;
  multiset<string> AinterB;

  set_intersection(A.begin(), A.end(), B.begin(), B.end(), inserter(AinterB, AinterB.begin()));
  set_union(A.begin(), A.end(), B.begin(), B.end(), inserter(AunionB, AunionB.begin()));

  if (AunionB.size() == 0) return 65536;

  answer = (double) AinterB.size() / AunionB.size() * 65536;

  return answer;
}