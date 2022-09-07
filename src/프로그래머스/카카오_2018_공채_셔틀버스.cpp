#include <algorithm>
#include <deque>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string timeToString(int hour, int min) {
  string time;
  if (hour < 10) {
    time += '0';
    time += to_string(hour);
  } else {
    time += to_string(hour);
  }
  time += ':';

  if (min < 10) {
    time += '0';
    time += to_string(min);
  } else {
    time += to_string(min);
  }

  return time;
}

string solution(int n, int t, int m, vector<string> timetable) {
  string answer = "";
  deque<pair<int, int>> crews;
  sort(timetable.begin(), timetable.end());
  for (auto time : timetable) {
    int a, b;
    sscanf(time.c_str(), "%d:%d", &a, &b);
    crews.push_back({a, b});
  }

  int curr_hour = 9;
  int curr_min = 0;
  int idx = 0;

  for (int i = 0; i < n - 1; ++i) {
    int cnt = 0;
    while (!crews.empty()) {
      auto [crew_hour, crew_min] = crews.front();
      if (crew_hour < curr_hour ||
          (crew_hour == curr_hour && crew_min <= curr_min)) {
        ++cnt;
        crews.pop_front();
        if (cnt == m) break;
      } else break;
    }

    curr_min += t;
    if (curr_min >= 60) {
      ++curr_hour;
      curr_min -= 60;
    }
  }

  int cnt = 0;
  for (int i = 0; i < crews.size(); ++i) {
    auto [crew_hour, crew_min] = crews[i];
    if (crew_hour < curr_hour ||
        (crew_hour == curr_hour && crew_min <= curr_min)) {
      ++cnt;
      if (cnt == m) {
        if (crew_min == 0) {
          --crew_hour;
          crew_min = 59;
        } else {
          --crew_min;
        }
        answer = timeToString(crew_hour, crew_min);
      }
    }
  }
  if (answer == "") answer = timeToString(curr_hour, curr_min);
  return answer;
}
