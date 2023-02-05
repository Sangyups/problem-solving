#include <iostream>
#include <string>
#include <vector>

using namespace std;

string rebuild_parentheses(string s) {
    s = s.substr(1, s.size() - 2);
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(') s[i] = ')';
        else s[i] = '(';
    }

    return s;
}

bool is_bracket_valid(string s) {
    int left_cnt = 0;
    int right_cnt = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') left_cnt++;
        else right_cnt++;

        if (left_cnt < right_cnt) return false;
    }

    return true;
}

pair<string, string> split_bracket(string s) {
    string u = "";
    string v = "";

    int left_cnt = 0;
    int right_cnt = 0;
    for (int i = 0; i < s.size(); i++) {
        u += s[i];
        if (s[i] == '(') left_cnt++;
        else right_cnt++;

        if (left_cnt == right_cnt) {
            v = s.substr(i + 1);
            break;
        }
    }

    return make_pair(u, v);
}

string solution(string p) {
    if (p == "") return p;

    auto [u, v] = split_bracket(p);

    if (is_bracket_valid(u)) {
        u += solution(v);
        return u;
    } else {
        string temp = "(" + solution(v) + ")";
        temp += rebuild_parentheses(u);
        return temp;
    }
}
