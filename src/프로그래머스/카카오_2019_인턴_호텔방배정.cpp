#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    unordered_map<ll, ll> m;

    for (const auto &num : room_number) {
        vector<ll> rooms = {num};
        ll temp = num;
        while (m[temp] != 0) {
            temp = m[temp];
            rooms.push_back(temp);
        }
        answer.push_back(temp);
        for (const auto &room : rooms) {
            m[room] = temp + 1;
        }
    }
    return answer;
}
