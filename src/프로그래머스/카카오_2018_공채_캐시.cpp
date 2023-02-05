#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define MAX 35

pair<string, int> cache[MAX];

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;

    for (int i = 0; i < cities.size(); ++i) {
        string city = cities[i];
        transform(city.begin(), city.end(), city.begin(), ::tolower);
        int flag = 0;
        int mn = 1987654321;
        int min_index = 0;
        for (int j = 0; j < cacheSize; ++j) {
            if (cache[j].first == city) {
                answer += 1;
                cache[j].second = i + 1;
                flag = 1;
                break;
            }
            if (mn > cache[j].second) {
                mn = cache[j].second;
                min_index = j;
            }
        }
        if (flag) continue;
        cache[min_index] = {city, i + 1};
        answer += 5;
    }

    return answer;
}
