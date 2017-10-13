// Time complexity: n: words length, k: average letter lengh, O(nk) + O(26 + 26^2) -> O(nk)
// Space complexity: O(26) + O(26^2) -> O(1)


class Solution {
public:
    string alienOrder(vector<string>& words) {
        string res = "";
        unordered_map<char, int> indegs; // indegs: map letter -> indegrees
        unordered_map<char, unordered_set<char>> edges; // edges: map letter -> unordered_set of letters pointing to

        // initialize indegree of  all the letters that appear to 0
        for (auto w : words) {
            for (auto c : w) {
                if (indegs.find(c) == indegs.end()) {indegs[c] = 0;}
            }
        }

        // build graph, if unsuccessful, return empty string
        for (int i=0; i<words.size()-1; ++i) {
            if (!helper(words[i], words[i+1], indegs, edges)) {return res;}
        }

        // Bread First Search (BFS)
        queue<char> q;
        for (auto c : indegs) {
            if (c.second == 0) {
                q.push(c.first);
            }
        }
        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                char c = q.front();
                res += c;
                q.pop(); indegs.erase(c);
                for (auto n : edges[c]) {
                    if (--indegs[n] == 0) {
                        q.push(n);
                    }
                }
            }
        }
        // If there is none zero indegree nodes left, the graph is invalid, return empty string
        return (indegs.empty()) ? res : "";
    }

    // helper function is used to generate graph from word pair (w1, w2);
    // return false: if the order of the word is not correct.
    // return true: otherwise
    bool helper(string w1, string w2, unordered_map<char, int> &indegs, unordered_map<char, unordered_set<char>> &edges) {
        int i = 0;
        while (i < w1.size()) {
            // if all previous letters in  w2 is the same as in w1, and it is shorter than w1,
            // then the order between w1 and w2 is incorrect.
            if (i == w2.size()) return false;
            if (w1[i] == w2[i]) i++;
            else {
                // if w1[i] != w2[i], then there is an direct edge from w1[i] to w2[i]
                if (edges.find(w1[i]) == edges.end() || edges[w1[i]].find(w2[i]) == edges[w1[i]].end()) {
                    edges[w1[i]].insert(w2[i]);
                    indegs[w2[i]]++;
                }
                break;
            }
        }
        return true;
    }
};
