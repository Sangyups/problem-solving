#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

int N, M;
vector<vector<int>> keys;
vector<vector<int>> candidate_keys;

void combination(int idx, int r, int cnt, vector<int> arr) {
  if (r == cnt) {
    keys.push_back(arr);
    return;
  }
  if (idx == M) {
    return;
  }
  combination(idx + 1, r, cnt, arr);
  arr.push_back(idx);
  combination(idx + 1, r, cnt + 1, arr);
}

bool is_valid_key(vector<int> keys) {
  for (int i = 0; i < candidate_keys.size(); ++i) {
    vector<int> candidate_key = candidate_keys[i];
    int cnt = 0;
    for (int j = 0; j < candidate_key.size(); ++j) {
      int key = candidate_key[j];
      for (int k = 0; k < keys.size(); ++k) {
        if (keys[k] == key) {
          cnt++;
          if (cnt == candidate_key.size()) return false;
        }
      }
    }
  }

  return true;
}

int solution(vector<vector<string>> relation) {
  int answer = 0;
  N = relation.size();
  M = relation[0].size();

  for (int i = 1; i <= M; ++i) {
    vector<int> arr;
    combination(0, i, 0, arr);
  }

  for (int i = 0; i < keys.size(); ++i) {
    vector<int> key = keys[i];
    if (!is_valid_key(key)) continue;
    set<vector<string>> s;
    for (int row = 0; row < N; ++row) {
      vector<string> rows;
      for (int k = 0; k < key.size(); ++k) {
        int col = key[k];
        rows.push_back(relation[row][col]);
      }
      s.insert(rows);
    }
    if (s.size() == N) {
      ++answer;
      candidate_keys.push_back(key);
    }
  }

  return answer;
}
