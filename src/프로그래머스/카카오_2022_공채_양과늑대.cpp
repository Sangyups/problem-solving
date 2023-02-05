#include <iostream>
#include <set>
#include <string>
#include <vector>

#define SHEEP 0
#define WOLF 1

using namespace std;

const int MAX = 25;

vector<int> adj[MAX];
vector<int> info_global;
int answer;

void dfs(int node, int sheep_cnt, int wolf_cnt, set<int> to_visit) {
    if (sheep_cnt == wolf_cnt) return;

    to_visit.erase(node);
    answer = max(sheep_cnt, answer);

    for (const auto &child : adj[node]) {
        to_visit.insert(child);
    }

    for (const auto &next : to_visit) {
        if (info_global[next] == SHEEP)
            dfs(next, sheep_cnt + 1, wolf_cnt, to_visit);
        else dfs(next, sheep_cnt, wolf_cnt + 1, to_visit);
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    for (auto edge : edges) {
        int a = edge[0];
        int b = edge[1];
        adj[a].push_back(b);
    }
    info_global = info;
    dfs(0, 1, 0, set<int>({0}));
    return answer;
}
