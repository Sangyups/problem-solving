class Solution {
   public:
    unordered_map<int, int> m;
    set<int> players;
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> answer = vector<vector<int>>(2);
        for (const auto& match : matches) {
            int winner = match[0];
            int loser = match[1];

            players.insert(winner);
            players.insert(loser);
            ++m[loser];
        }

        for (const auto& player : players) {
            if (m[player] == 0) {
                answer[0].push_back(player);
            } else if (m[player] == 1) {
                answer[1].push_back(player);
            }
        }
        return answer;
    }
};
