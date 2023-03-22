#define MAX 100000 + 1
#define INF 2e9

using pii = pair<int, int>;

class Solution {
   public:
    vector<pii> graph[MAX];
    int dist[MAX];
    int N;

    void dijkstra(int start) {
        fill(&dist[0], &dist[MAX], INF);
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({INF, start});
        dist[start] = INF;

        while (!pq.empty()) {
            auto [curr_dist, curr] = pq.top();
            pq.pop();

            if (dist[curr] < curr_dist) continue;

            for (auto &neigh : graph[curr]) {
                auto [next_dist, next_node] = neigh;
                next_dist = min(next_dist, curr_dist);
                if (next_dist < dist[next_node]) {
                    dist[next_node] = next_dist;
                    pq.push({next_dist, next_node});
                }
            }
        }
    }

    int minScore(int n, vector<vector<int>> &roads) {
        for (auto &road : roads) {
            int x = road[0];
            int y = road[1];
            int w = road[2];

            graph[x].push_back({w, y});
            graph[y].push_back({w, x});
        }

        dijkstra(1);

        return dist[n];
    }
};
