#include <algorithm>
#include <string>
#include <vector>

using namespace std;

pair<string, int> separate_name(string s) {
    string head = "";
    string number_string = "";

    int i = 0;
    while (!(s[i] >= '0' && s[i] <= '9')) {
        head += s[i++];
    }
    transform(head.begin(), head.end(), head.begin(), ::tolower);

    while (i < s.size() && s[i] >= '0' && s[i] <= '9') {
        number_string += s[i++];
    }
    int number = stoi(number_string);

    return {head, number};
}

bool cmp(string file_a, string file_b) {
    auto [head_a, number_a] = separate_name(file_a);
    auto [head_b, number_b] = separate_name(file_b);
    if (head_a < head_b) return true;
    else if (head_a > head_b) return false;
    else return number_a < number_b;
}

vector<string> solution(vector<string> files) {
    stable_sort(files.begin(), files.end(), cmp);

    return files;
}
