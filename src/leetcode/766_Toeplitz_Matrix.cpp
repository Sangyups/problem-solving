const int MAX = 25;

class Solution {
   public:
    int N, M;
    int visited[MAX][MAX];

    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        N = matrix.size();
        M = matrix[0].size();

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (visited[i][j]) continue;
                int start = matrix[i][j];
                int cx = i;
                int cy = j;
                while (cx >= 0 && cx < N && cy >= 0 && cy < M) {
                    if (start != matrix[cx][cy]) return 0;
                    visited[cx][cy] = 1;
                    ++cx;
                    ++cy;
                }
            }
        }

        return 1;
    }
};
