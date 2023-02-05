#include <map>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    int latest_num = 0;
    map<string, int> m;
    for (int i = 1; i <= 26; ++i) {
        string temp = "";
        temp += 'A' + i - 1;
        m.insert({temp, i});
        latest_num++;
    }

    for (int i = 0; i < msg.size(); ++i) {
        string input = {msg[i]};
        while (i < msg.size() - 1 && m.find(input + msg[i + 1]) != m.end()) {
            input += msg[++i];
        }
        answer.push_back(m[input]);
        if (i < msg.size() - 1) {
            input += msg[i + 1];
            m.insert({input, ++latest_num});
        }
    }
    return answer;
}
