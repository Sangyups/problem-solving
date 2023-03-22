#define MAX 100000 + 1
#define INF 2e9

using pii = pair<int, int>;

class Solution {
   public:
    vector<pii> graph[MAX];
    int visited[MAX];
    int ans = INF;

    void bfs() {
        queue<int> q;
        q.push(1);
        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (auto &neigh : graph[curr]) {
                auto [next_node, dist] = neigh;

                ans = min(ans, dist);
                if (visited[next_node]) {
                    continue;
                }
                visited[next_node] = 1;
                q.push(next_node);
            }
        }
    }

    int minScore(int n, vector<vector<int>> &roads) {
        for (auto &road : roads) {
            int x = road[0];
            int y = road[1];
            int w = road[2];

            graph[x].push_back({y, w});
            graph[y].push_back({x, w});
        }

        bfs();

        return ans;
    }
};
