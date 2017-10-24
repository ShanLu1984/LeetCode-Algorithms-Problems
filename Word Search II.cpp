// Trie + backtracking: 
// L: length of all the words in dictionary; n, m: row and column numbers of the board;
// space complexity: O(26 * L)
// time complexity: O(L) + O(n * m * 4^L)

cclass TrieNode {
public:
    char c;
    bool isEnd; // if this letter is the end of an word;
    bool visited; // if we have already output this word;
    int pos; // the position of the word in the vector words;
    vector<TrieNode*> neighbors; 
     
    /**initialze a TrieNode object without an input */
    TrieNode() {
        c = '#';
        isEnd = false;
        visited = false;
        neighbors = vector<TrieNode*> (26, nullptr);
        pos = -1;
    }
    /** initialize a TrieNode object with a letter as an input */
    TrieNode(char c) {
        this->c = c;
        isEnd = false;
        visited = false;
        neighbors = vector<TrieNode*> (26, nullptr);
        pos = -1;
    }
    ~TrieNode() {
        for (auto n : neighbors) {
            delete(n);
        }
    }
};


class Solution {
public:
    TrieNode* root;
    /** Inserts a word into trie */ 
    void insert(string word, int index) {
        TrieNode* tn = root;
        for (auto c: word) {
            if (tn->neighbors[c - 'a'] == nullptr) {
                tn->neighbors[c - 'a'] = new TrieNode(c);
            }
            tn = tn->neighbors[c - 'a'];
        }
        // At the end of each insertion, mark that TrieNode as an end and
        // record its position in the original words vector
        tn->isEnd = true;
        tn->pos = index;
    }
    /** Build the trie with words*/
    void buildTrie(vector<string> &words) {
        // initialize the Trie
        root = new TrieNode();
        
        // build the Trie
        for (int i=0; i<words.size(); ++i) {
            insert(words[i], i);
        }
    }
    
    /** helper funciton is used to do backtracking */
    void helper(vector<string> &res, vector<string>& words, vector<vector<char>> &board, TrieNode* root, int x, int y) {    
        // the situation to return to the previous step;
        if (root == nullptr) return;
        
        // the situation to output part of the result;
        if (root->isEnd == true && root->visited == false) { 
            res.push_back(words[root->pos]);
            root->visited = true;
        }
        
        // mark the current position in the borad to be '*' to avoid revisiting;
        char ctemp = board[x][y];
        board[x][y] = '*';
        
        // check the four directions;
        vector<int> dir = {-1, 0, 1, 0, -1};
        for (int i=0; i<dir.size()-1; ++i) {
            int x_temp = x + dir[i];
            int y_temp = y + dir[i + 1];
            if (x_temp >= 0 && x_temp < board.size() && y_temp >= 0 && y_temp < board[0].size()) {       
                if (board[x_temp][y_temp] == '*') continue; // if is already visited, skip;
                helper(res, words, board, root->neighbors[board[x_temp][y_temp] - 'a'], x_temp, y_temp);
            }
        }
        
        // change the current position in the borad back to the original character;
        board[x][y] = ctemp;
        return;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        buildTrie(words);
        
        // begin search with every letter in the board as starting letter
        vector<string> res; string cur = "";
        for (int i=0; i<board.size(); ++i) {
            for (int j=0; j<board[0].size(); ++j) {
                helper(res, words, board, root->neighbors[board[i][j]-'a'], i, j);
            }
        }
        return res;
    }
};