struct Node {
    string word;
    vector<Node*> children;
    Node()
        : word(""),
          children(vector<Node*>(26, nullptr)) {}
};

class Solution {
   public:
    int N, M;
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    vector<string> answer;
    Node* build_trie(vector<string>& words) {
        Node* root = new Node();
        for (const auto& word : words) {
            Node* curr = root;
            for (const auto& c : word) {
                if (curr->children[c - 'a'] == nullptr) {
                    curr->children[c - 'a'] = new Node();
                }
                curr = curr->children[c - 'a'];
            }
            curr->word = word;
        }
        return root;
    }

    void dfs(vector<vector<char>>& board, int x, int y, Node* curr) {
        char c = board[x][y];
        if (c == '.' || curr->children[c - 'a'] == nullptr) return;
        curr = curr->children[c - 'a'];

        if (curr->word != "") {
            answer.push_back(curr->word);
            curr->word = "";
        }

        board[x][y] = '.';

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            dfs(board, nx, ny, curr);
        }

        board[x][y] = c;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        N = board.size();
        M = board[0].size();

        Node* root = build_trie(words);

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                dfs(board, i, j, root);
            }
        }
        return answer;
    }
};
