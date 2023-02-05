#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define endl '\n'
#define pii pair<int, int>

typedef long long ll;

using namespace std;

string equation;
int hasMinus;

void solution() {
    int result = 0;
    string num = "";
    for (int i = 0; i <= equation.size(); ++i) {
        if (equation[i] == '-' or equation[i] == '+' or i == equation.size()) {
            if (hasMinus) result -= stoi(num);
            else result += stoi(num);
            if (equation[i] == '-') {
                hasMinus = 1;
            }
            num = "";
        } else {
            num += equation[i];
        }
    }
    cout << result;
}

int main(int argc, const char *argv[]) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> equation;

    solution();
}
