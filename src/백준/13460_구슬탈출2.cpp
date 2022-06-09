#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>

#define endl '\n'
#define pii pair<int, int>

typedef long long ll;

using namespace std;

#define MAX 20
#define DOWN 1
#define UP 2
#define LEFT 3
#define RIGHT 4

int N, M, answer;
char board[MAX][MAX];
pii red, blue, goal;

pair<pii, pii > move_marble(int direction, pii curr_red, pii curr_blue) {
  pii next_red = curr_red, next_blue = curr_blue;

  auto[x_red, y_red] = curr_red;
  auto[x_blue, y_blue] = curr_blue;

  if (direction == DOWN) {
    if (x_red > x_blue) {
      while (board[next_red.first + 1][next_red.second] == '.') {
        next_red.first++;
      }
      if (board[next_red.first + 1][next_red.second] == 'O') next_red.first++;
      else board[next_red.first][next_red.second] = '#';

      while (board[next_blue.first + 1][next_blue.second] == '.') {
        next_blue.first++;
      }
      if (board[next_blue.first + 1][next_blue.second] == 'O') next_blue.first++;
      else board[next_blue.first][next_blue.second] = '#';
    } else {
      while (board[next_blue.first + 1][next_blue.second] == '.') {
        next_blue.first++;
      }
      if (board[next_blue.first + 1][next_blue.second] == 'O') next_blue.first++;
      else board[next_blue.first][next_blue.second] = '#';

      while (board[next_red.first + 1][next_red.second] == '.') {
        next_red.first++;
      }
      if (board[next_red.first + 1][next_red.second] == 'O') next_red.first++;
      else board[next_red.first][next_red.second] = '#';
    }
  } else if (direction == UP) {
    if (x_red < x_blue) {
      while (board[next_red.first - 1][next_red.second] == '.') {
        next_red.first--;
      }
      if (board[next_red.first - 1][next_red.second] == 'O') next_red.first--;
      else board[next_red.first][next_red.second] = '#';

      while (board[next_blue.first - 1][next_blue.second] == '.') {
        next_blue.first--;
      }
      if (board[next_blue.first - 1][next_blue.second] == 'O') next_blue.first--;
      else board[next_blue.first][next_blue.second] = '#';

    } else {
      while (board[next_blue.first - 1][next_blue.second] == '.') {
        next_blue.first--;
      }
      if (board[next_blue.first - 1][next_blue.second] == 'O') next_blue.first--;
      else board[next_blue.first][next_blue.second] = '#';

      while (board[next_red.first - 1][next_red.second] == '.') {
        next_red.first--;
      }
      if (board[next_red.first - 1][next_red.second] == 'O') next_red.first--;
      else board[next_red.first][next_red.second] = '#';

    }
  } else if (direction == LEFT) {
    if (y_red < y_blue) {
      while (board[next_red.first][next_red.second - 1] == '.') {
        next_red.second--;
      }
      if (board[next_red.first][next_red.second - 1] == 'O') next_red.second--;
      else board[next_red.first][next_red.second] = '#';

      while (board[next_blue.first][next_blue.second - 1] == '.') {
        next_blue.second--;
      }
      if (board[next_blue.first][next_blue.second - 1] == 'O') next_blue.second--;
      else board[next_blue.first][next_blue.second] = '#';

    } else {
      while (board[next_blue.first][next_blue.second - 1] == '.') {
        next_blue.second--;
      }
      if (board[next_blue.first][next_blue.second - 1] == 'O') next_blue.second--;
      else board[next_blue.first][next_blue.second] = '#';

      while (board[next_red.first][next_red.second - 1] == '.') {
        next_red.second--;
      }
      if (board[next_red.first][next_red.second - 1] == 'O') next_red.second--;
      else board[next_red.first][next_red.second] = '#';

    }
  } else if (direction == RIGHT) {
    if (y_red > y_blue) {
      while (board[next_red.first][next_red.second + 1] == '.') {
        next_red.second++;
      }
      if (board[next_red.first][next_red.second + 1] == 'O') next_red.second++;
      else board[next_red.first][next_red.second] = '#';

      while (board[next_blue.first][next_blue.second + 1] == '.') {
        next_blue.second++;
      }
      if (board[next_blue.first][next_blue.second + 1] == 'O') next_blue.second++;
      else board[next_blue.first][next_blue.second] = '#';

    } else {
      while (board[next_blue.first][next_blue.second + 1] == '.') {
        next_blue.second++;
      }
      if (board[next_blue.first][next_blue.second + 1] == 'O') next_blue.second++;
      else board[next_blue.first][next_blue.second] = '#';

      while (board[next_red.first][next_red.second + 1] == '.') {
        next_red.second++;
      }
      if (board[next_red.first][next_red.second + 1] == 'O') next_red.second++;
      else board[next_red.first][next_red.second] = '#';

    }
  }

  if (board[next_red.first][next_red.second] == '#') board[next_red.first][next_red.second] = '.';
  if (board[next_blue.first][next_blue.second] == '#') board[next_blue.first][next_blue.second] = '.';

  return make_pair(next_red, next_blue);
}

void solution() {
  queue<tuple<int, pii, pii>> q;
  q.push(make_tuple(0, red, blue));
  while (not q.empty()) {
    auto[step, curr_red, curr_blue] = q.front();
    q.pop();
    if (step == 11) {
      answer = -1;
      return;
    }
    if (curr_blue == goal) continue;
    else if (curr_red == goal) {
      answer = step;
      return;
    }

    for (int direction = 1; direction <= 4; ++direction) {
      auto[next_red, next_blue] = move_marble(direction, curr_red, curr_blue);
      q.push(make_tuple(step + 1, next_red, next_blue));
    }

  }
}

int main(int argc, const char *argv[]) {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> N >> M;

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      cin >> board[i][j];
      if (board[i][j] == 'O') goal = make_pair(i, j);
      else if (board[i][j] == 'B') {
        blue = make_pair(i, j);
        board[i][j] = '.';
      } else if (board[i][j] == 'R') {
        red = make_pair(i, j);
        board[i][j] = '.';
      }
    }

  }

  solution();
  cout << answer << endl;

}
