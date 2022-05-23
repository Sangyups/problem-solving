#include <bits/stdc++.h>

#define endl '\n'
#define print(x) cout << x << endl
#define clearArray(arr, num) memset(arr, num, sizeof(arr))
#define clear2DArray(arr, num, row) \
  for (int i = 0; i < row; i++) {   \
    clearArray(arr[i], num);        \
  }
#define pii pair<int, int>
#define ll long long
#define INF 987654321
using namespace std;

#define MAX 9
int N;
int sudoku[MAX][MAX];
int ans[MAX][MAX];
int flag;

void backTrackSudoku(int x, int y);

void printSudoku() {
  if(flag) return;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cout << sudoku[i][j];
    }
    cout << endl;
  }
  flag = 1;
}

bool isValid(int x, int y) {
  for (int i = 0; i < N; i++) {
    if (y == i) {
      continue;
    }
    if (sudoku[x][i] == sudoku[x][y]) {
      return false;
    }
  }

  for (int i = 0; i < N; i++) {
    if (x == i) {
      continue;
    }
    if (sudoku[i][y] == sudoku[x][y]) {
      return false;
    }
  }

  int startX = (x / 3) * 3;
  int startY = (y / 3) * 3;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (x == startX + i && y == startY + j) {
        continue;
      }
      if (sudoku[startX + i][startY + j] == sudoku[x][y]) {
        return false;
      }
    }
  }

  return true;
}

void move(int x, int y) {
  if (y == N - 1) {
    if (x != N - 1) {
      backTrackSudoku(x + 1, 0);
    } else {
      printSudoku();
    }
  } else {
    backTrackSudoku(x, y + 1);
  }
}

void backTrackSudoku(int x, int y) {
  if(flag) return;
  if (sudoku[x][y] == 0) {
    for (int i = 1; i <= N; i++) {
      sudoku[x][y] = i;
      if (isValid(x, y)) {
        //        cout << x << ' ' << y << ": " << sudoku[x][y] << endl;
        move(x, y);
      }
    }
    sudoku[x][y] = 0;
  } else {
    if (isValid(x, y)) move(x, y);
  }
}

void solution() { backTrackSudoku(0, 0); }

int main(int argc, const char* argv[]) {
  //  cin.tie(nullptr);
  //  ios::sync_with_stdio(false);

  N = MAX;
  fill(&ans[0][0], &ans[N - 1][N], 9);
  for (int i = 0; i < N; i++) {
    string row;
    cin >> row;
    sscanf(row.c_str(), "%1d%1d%1d%1d%1d%1d%1d%1d%1d", &sudoku[i][0],
           &sudoku[i][1], &sudoku[i][2], &sudoku[i][3], &sudoku[i][4],
           &sudoku[i][5], &sudoku[i][6], &sudoku[i][7], &sudoku[i][8]);
  }

  solution();
}
