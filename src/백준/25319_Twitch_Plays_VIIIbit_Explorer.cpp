#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <queue>

#define endl '\n'
#define pii pair<int, int>

typedef long long ll;

using namespace std;

#define MAX 55

int N, M, S;
int MAX_LEVEL;
string char_id;
int visited[MAX][MAX];
map<char, vector<pii>> item_pos;
map<char, int> char_cnt;
vector<char> chats;

void preproc() {
}

void record_chats(pii start, pii goal) {
  int dist = goal.first - start.first;
  for (int i = 0; i < abs(dist); ++i) {
    if (dist < 0) chats.push_back('U');
    else if (dist > 0) chats.push_back('D');
  }
  dist = goal.second - start.second;
  for (int i = 0; i < abs(dist); ++i) {
    if (dist < 0) chats.push_back('L');
    else if (dist > 0) chats.push_back('R');
  }
}

void solution() {
  int curr_level = 0;
  int curr_item = 0;
  pii curr_pos = {0, 0};
  pii goal;
  if (MAX_LEVEL != 0) {
    goal = item_pos[char_id[curr_item]][0];
    visited[goal.first][goal.second] = 1;
  }
  while (curr_level != MAX_LEVEL) {
    record_chats(curr_pos, goal);
    chats.push_back('P');
    curr_pos = goal;
    if (curr_item == S - 1) {
      curr_item = 0;
      ++curr_level;
    } else {
      ++curr_item;
    }
    for (int i = 0; i < item_pos[char_id[curr_item]].size(); ++i) {
      goal = item_pos[char_id[curr_item]][i];
      if (!visited[goal.first][goal.second]) break;
    }
    visited[goal.first][goal.second] = 1;
  }
  goal = {N - 1, M - 1};
  record_chats(curr_pos, goal);

  cout << MAX_LEVEL << ' ' << chats.size() << endl;
  for (auto chat : chats) {
    cout << chat;
  }
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> N >> M >> S;

  for (int i = 0; i < N; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < M; ++j) {
      item_pos[s[j]].push_back({i, j});
    }
  }

  cin >> char_id;

  for (int i = 0; i < S; ++i) {
    char_cnt[char_id[i]]++;
  }
  int level = 1987654321;
  for (int i = 0; i < S; ++i) {
    char chr = char_id[i];
    level = min(level, int(item_pos[chr].size()) / char_cnt[chr]);
  }

  MAX_LEVEL = level;

  preproc();
  solution();
}
