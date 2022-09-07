#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

const int MAX = 360005;

int N;
ll dp[MAX];

int ttoi(string time) {
  string hour;
  hour += time[0];
  hour += time[1];
  string min;
  min += time[3];
  min += time[4];
  string sec;
  sec += time[6];
  sec += time[7];

  return stoi(hour) * 3600 + stoi(min) * 60 + stoi(sec);
}

string itot(int time) {
  string hour = to_string(time / 3600);
  time %= 3600;
  string min = to_string(time / 60);
  time %= 60;
  string sec = to_string(time);

  if (hour.size() < 2) hour = '0' + hour;
  if (min.size() < 2) min = '0' + min;
  if (sec.size() < 2) sec = '0' + sec;

  return hour + ':' + min + ':' + sec;
}

string solution(string play_time, string adv_time, vector<string> logs) {
  int answer = 0;
  int N = ttoi(play_time);

  for (auto log : logs) {
    int start_time = ttoi(log.substr(0, 8));
    int end_time = ttoi(log.substr(9, 8));
    dp[start_time] += 1;
    dp[end_time] -= 1;
  }

  for (int i = 1; i <= N; ++i) {
    dp[i] += dp[i - 1];
  }

  for (int i = 1; i <= N; ++i) {
    dp[i] += dp[i - 1];
  }

  int gap = ttoi(adv_time);
  ll max_cnt = 0;

  for (int i = 0; i + gap <= N; ++i) {
    ll temp;
    if (i == 0) temp = dp[i + gap - 1];
    else temp = dp[i + gap - 1] - dp[i - 1];
    if (max_cnt < temp) {
      max_cnt = temp;
      answer = i;
    }
  }

  return itot(answer);
}
