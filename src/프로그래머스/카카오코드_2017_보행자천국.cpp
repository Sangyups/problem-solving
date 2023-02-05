#include <iostream>
#include <vector>

#define DOWN 0
#define RIGHT 1

using namespace std;

const int MAX = 505;

int MOD = 20170805;
int N, M;
int answer;
int dp[MAX][MAX][2];

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    answer = 0;
    N = m;
    M = n;
    fill(&dp[0][0][0], &dp[MAX - 1][MAX - 1][2], 0);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (i == 0 && j == 0) {
                dp[0][0][RIGHT] = 1;
                dp[0][0][DOWN] = 1;
            } else if (i == 0) {
                if (city_map[i][j] == 1) {
                    dp[i][j][RIGHT] = 0;
                    dp[i][j][DOWN] = 0;
                } else if (city_map[i][j] == 2) {
                    dp[i][j][RIGHT] = dp[i][j - 1][RIGHT];
                    dp[i][j][DOWN] = 0;
                } else {
                    dp[i][j][RIGHT] = dp[i][j - 1][RIGHT];
                    dp[i][j][DOWN] = dp[i][j - 1][RIGHT];
                }
            } else if (j == 0) {
                if (city_map[i][j] == 1) {
                    dp[i][j][RIGHT] = 0;
                    dp[i][j][DOWN] = 0;
                } else if (city_map[i][j] == 2) {
                    dp[i][j][DOWN] = dp[i - 1][j][DOWN];
                    dp[i][j][RIGHT] = 0;
                } else {
                    dp[i][j][RIGHT] = dp[i - 1][j][DOWN];
                    dp[i][j][DOWN] = dp[i - 1][j][DOWN];
                }
            } else {
                if (city_map[i][j] == 1) {
                    dp[i][j][RIGHT] = 0;
                    dp[i][j][DOWN] = 0;
                } else if (city_map[i][j] == 2) {
                    dp[i][j][RIGHT] = dp[i][j - 1][RIGHT];
                    dp[i][j][DOWN] = dp[i - 1][j][DOWN];
                } else {
                    dp[i][j][RIGHT] = (dp[i][j - 1][RIGHT] + dp[i - 1][j][DOWN]) % MOD;
                    dp[i][j][DOWN] = dp[i][j][RIGHT];
                }
            }
        }
    }

    return dp[N - 1][M - 1][0];
}
