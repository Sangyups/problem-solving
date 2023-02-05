#include <string>
#include <vector>

using namespace std;

int mat[102][102];

int rotate_matrix(vector<int> query) {
    int min_num = 1987654321;
    int r1 = query[0], c1 = query[1], r2 = query[2], c2 = query[3];

    vector<int> temp = {mat[r1 + 1][c1], mat[r1][c2 - 1], mat[r2 - 1][c2], mat[r2][c1 + 1]};

    for (int i = c2 - 1; i > c1; --i) {
        mat[r1][i] = mat[r1][i - 1];
        min_num = min(min_num, mat[r1][i]);
    }

    for (int i = r2 - 1; i > r1; --i) {
        mat[i][c2] = mat[i - 1][c2];
        min_num = min(min_num, mat[i][c2]);
    }

    for (int i = c1 + 1; i < c2; ++i) {
        mat[r2][i] = mat[r2][i + 1];
        min_num = min(min_num, mat[r2][i]);
    }

    for (int i = r1 + 1; i < r2; ++i) {
        mat[i][c1] = mat[i + 1][c1];
        min_num = min(min_num, mat[i][c1]);
    }

    mat[r1][c1] = temp[0];
    min_num = min(min_num, mat[r1][c1]);

    mat[r1][c2] = temp[1];
    min_num = min(min_num, mat[r1][c2]);

    mat[r2][c2] = temp[2];
    min_num = min(min_num, mat[r2][c2]);

    mat[r2][c1] = temp[3];
    min_num = min(min_num, mat[r2][c1]);

    return min_num;
}

vector<int> solution(int rows, int cols, vector<vector<int>> queries) {
    vector<int> answer;

    for (int i = 1; i <= rows; ++i) {
        for (int j = 1; j <= cols; ++j) {
            mat[i][j] = (i - 1) * cols + j;
        }
    }

    for (auto query : queries) {
        answer.push_back(rotate_matrix(query));
    }

    return answer;
}
