// Trie + Backtracking
// space complexity: O(m * n) n: number of words, m: average length of words
// time complexity: build Trie: O(m * n), backtracking: O(n^n) * O(n) (O(n) for query);

class Solution {
public:
    // TrieNode: index is the words begin with the current prefix
    struct TrieNode{
        vector<TrieNode*> children;
        vector<int> index;
        TrieNode() {
            children = vector<TrieNode*>(26, nullptr);
        }
    };
    
    // insert a word into trie;
    void insertWord(TrieNode* root, string str, int index) {
        TrieNode* tn = root;
        for (auto c : str) {
            if (!tn->children[c - 'a']) {
                tn->children[c - 'a'] = new TrieNode();
            }
            tn = tn->children[c - 'a'];
            tn->index.push_back(index);
        }
        tn->index.push_back(index);
    }
    
    // return the words index with a given prefix;
    vector<int> queryPrefix(TrieNode* root, string prefix) {
        vector<int> res;
        TrieNode* tn = root;
        for (auto p : prefix) {
            if (!tn->children[p - 'a']) return res;
            tn = tn->children[p - 'a'];
        }
        return tn->index;
    }
    
    void helper(TrieNode* root, vector<string> &words, vector<vector<string>> &res, vector<string> &cur) {
        int n = cur.size();
        if (n == cur[0].size()) {
            res.push_back(cur);
            return;
        }
        // the prefix of a new line can be computed with the previous lines
        string prefix = "";
        for (int i=0; i<n; ++i) {
            prefix += cur[i][n];
        }
        vector<int> index = queryPrefix(root, prefix);
        if (index.empty()) return;
        for (auto i : index) {
            cur.push_back(words[i]);
            helper(root, words, res, cur);
            cur.pop_back();
        }
        return;
    }
    
    vector<vector<string>> wordSquares(vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (int i=0; i<words.size(); i++) {
            insertWord(root, words[i], i);
        }
        vector<vector<string>> res;
        vector<string> cur;
        for (auto w : words) {
            cur.push_back(w);
            helper(root, words, res, cur);
            cur.pop_back();
        }
        return res;
    }
};
