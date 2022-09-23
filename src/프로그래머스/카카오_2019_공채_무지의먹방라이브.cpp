#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int solution(vector<int> food_times, long long k) {
    int answer = -1;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<pii> candidates;
    ll curr_time = 0;

    for (int i = 0; i < food_times.size(); ++i) {
        pq.push({food_times[i], i + 1});
    }

    int previous = 0;
    while (!pq.empty()) {
        auto [now, idx] = pq.top();
        ll minus = pq.size() * (now - previous);
        if (minus <= k) {
            k -= minus;
            previous = now;
            pq.pop();
        } else {
            while (!pq.empty()) {
                auto [candidate_food, candidate_idx] = pq.top();
                pq.pop();
                candidates.push_back({candidate_idx, candidate_food});
            }
            sort(candidates.begin(), candidates.end());
            return candidates[k % candidates.size()].first;
        }
    }

    return answer;
}
