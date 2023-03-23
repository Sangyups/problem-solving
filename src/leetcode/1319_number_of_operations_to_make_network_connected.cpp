#define MAX 100000

class Solution {
   public:
    int visited[MAX];
    vector<int> graph[MAX];
    int remaining_cables;

    void bfs(int start) {
        queue<int> q;
        q.push(start);
        visited[start] = 1;

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            for (auto& neigh : graph[curr]) {
                if (visited[neigh]) {
                    continue;
                }

                visited[neigh] = 1;
                q.push(neigh);
                --remaining_cables;
            }
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        for (auto& connection : connections) {
            int a = connection[0];
            int b = connection[1];

            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        int group_cnt = 0;
        remaining_cables = connections.size();

        for (int i = 0; i < n; ++i) {
            if (visited[i]) {
                continue;
            }

            bfs(i);
            ++group_cnt;
        }

        return group_cnt - 1 <= remaining_cables ? group_cnt - 1 : -1;
    }
};
