#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using pii = pair<int, int>;

vector<int> pre_nodes;
vector<int> post_nodes;

struct Node {
    int data;
    int x;
    int y;

    Node *left;
    Node *right;

    Node(int data, int x, int y, Node *left, Node *right)
        : data(data),
          x(x),
          y(y),
          left(left),
          right(right) {}

    bool operator<(const Node &rhs) const {
        if (y == rhs.y) return x < rhs.x;
        return y > rhs.y;
    }
};

void order_nodes(Node *node) {
    pre_nodes.push_back(node->data);
    if (node->left) order_nodes(node->left);
    if (node->right) order_nodes(node->right);
    post_nodes.push_back(node->data);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    vector<Node> nodes;

    int cnt = 0;
    for (auto info : nodeinfo) {
        ++cnt;
        nodes.push_back(Node(cnt, info[0], info[1], nullptr, nullptr));
    }

    sort(nodes.begin(), nodes.end());

    Node root_node = nodes[0];

    for (int i = 1; i < nodes.size(); ++i) {
        Node *temp = &root_node;
        while (true) {
            if (temp->x > nodes[i].x) {
                if (temp->left) temp = temp->left;
                else {
                    temp->left = &nodes[i];
                    break;
                }
            } else {
                if (temp->right) temp = temp->right;
                else {
                    temp->right = &nodes[i];
                    break;
                }
            }
        }
    }

    order_nodes(&root_node);

    answer.push_back(pre_nodes);
    answer.push_back(post_nodes);

    return answer;
}
