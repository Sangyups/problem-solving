class Solution {
   public:
    map<string, int> visited;

    int is_valid_mutation(string a, string b) {
        int cnt = 0;
        for (int i = 0; i < 8; ++i) {
            if (a[i] != b[i]) ++cnt;
        }

        return ((cnt == 1) ? 1 : 0);
    }

    int minMutation(string start, string end, vector<string>& bank) {
        if (start == end) return 0;
        queue<pair<string, int>> q;
        visited[start] = 1;
        q.push({start, 0});
        while (!q.empty()) {
            auto [curr, step] = q.front();
            q.pop();

            for (const auto& b : bank) {
                if (visited[b]) continue;
                if (!is_valid_mutation(curr, b)) continue;

                if (b == end) return step + 1;

                visited[b] = 1;
                q.push({b, step + 1});
            }
        }
        return -1;
    }
};
