// Bread-first-search
// Space complexity: O(n)
// Time complexity: O(n)

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        
        /** build the graph */
        vector<int> inCourses(numCourses, 0);
        unordered_map<int, vector<int>> mp;
        int nodeVisited = 0;
        for(auto p : prerequisites) {
            inCourses[p.first]++;
            mp[p.second].push_back(p.first);
        }
        
        /** bread-first search */
        queue<int> q;
        for(int i=0; i<inCourses.size(); ++i) {
            if(inCourses[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int temp = q.front();
            q.pop();
            nodeVisited++;
            for (auto c : mp[temp]) {
                if (--inCourses[c] == 0) {
                    q.push(c);
                }
            }
        }
        /** check if the graph has cycle */
        return nodeVisited == numCourses;
    }
};