/*
 * 풀이 1.
 * stl 사용
 */

#include <algorithm>
#include <iostream>
#include <set>
#include <string>

using namespace std;

multiset<string> get_multiset(string s) {
    multiset<string> string_set;

    for (int i = 0; i < s.size() - 1; ++i) {
        string temp = s.substr(i, 2);
        if (temp[0] >= 'a' and temp[0] <= 'z' and temp[1] >= 'a' and temp[1] <= 'z')
            string_set.insert(temp);
    }

    return string_set;
}

int solution(string str1, string str2) {
    int answer = 0;
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);

    multiset<string> A = get_multiset(str1);
    multiset<string> B = get_multiset(str2);

    multiset<string> AunionB;
    multiset<string> AinterB;

    set_intersection(A.begin(), A.end(), B.begin(), B.end(), inserter(AinterB, AinterB.begin()));
    set_union(A.begin(), A.end(), B.begin(), B.end(), inserter(AunionB, AunionB.begin()));

    if (AunionB.size() == 0) return 65536;

    answer = (double) AinterB.size() / AunionB.size() * 65536;

    return answer;
}

/*
 * 풀이 2.
 * multiset union, intersection 직접 구현
 */

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

vector<string> get_multiset(string s) {
    vector<string> string_set;

    for (int i = 0; i < s.size() - 1; ++i) {
        string temp = s.substr(i, 2);
        if (temp[0] >= 'a' and temp[0] <= 'z' and temp[1] >= 'a' and temp[1] <= 'z')
            string_set.push_back(temp);
    }

    return string_set;
}

int solution(string str1, string str2) {
    int answer = 0;
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);

    vector<string> A = get_multiset(str1);
    vector<string> B = get_multiset(str2);

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    vector<string> AunionB;
    vector<string> AinterB;

    int i = 0, j = 0;
    while (i < A.size() || j < B.size()) {
        string a = "}}";
        string b = "}}";
        if (i < A.size()) a = A[i];
        if (j < B.size()) b = B[j];

        if (a < b) {
            AunionB.push_back(a);
            ++i;
        } else if (a > b) {
            AunionB.push_back(b);
            ++j;
        } else {
            AunionB.push_back(b);
            AinterB.push_back(b);
            ++i;
            ++j;
        }
    }

    if (AunionB.size() == 0) return 65536;

    answer = (double) AinterB.size() / AunionB.size() * 65536;

    return answer;
}
