#include <iostream>
#include <algorithm>

#define endl '\n'

using namespace std;

int N, S;
int arr[50];

void print_solution() {
  for (int i = 0; i < N; i++) {
    cout << arr[i] << ' ';
  }
  cout << endl;
}

pair<int, int> get_max_num_and_index(int index, int range) {
  int max_num = 0;
  int max_num_index = 0;
  for (int i = index; i < N && i < index + range; i++) {
    if (max_num < arr[i]) {
      max_num = arr[i];
      max_num_index = i;
    }
  }
  return make_pair(max_num, max_num_index);
}

void solution() {
  int start_index = 0;

  while (start_index < N) {
    int range = min(N, S + 1);
    auto[max_num, index] = get_max_num_and_index(start_index, range);

    for (int i = index; i > start_index; i--) {
      swap(arr[i], arr[i - 1]);
      S--;
      if (S == 0) return;
    }
    start_index++;
  }
}

int main(int argc, const char *argv[]) {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  cin >> S;

  solution();
  print_solution();
}
