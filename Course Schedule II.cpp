// Bread-first-search
// Space complexity: O(n)
// Time complexity: O(n)

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> indeg (numCourses, 0); // indegrees of all courses (the total number of prerequisites of each course);
        unordered_map<int, vector<int>> mp; // node (prerequisite) -> the nodes it pointing to;
        
        /** build the graph */
        for (int i=0; i<prerequisites.size(); i++) {
            indeg[prerequisites[i].first]++;
            mp[prerequisites[i].second].push_back(prerequisites[i].first);
        }
        
        /** using queue to do the bfs traverse of the graph */
        vector<int> res;
        queue<int> q;
        for (int i=0; i<numCourses; ++i) {
            // strat with all the nodes with 0 indegree;
            if (indeg[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int temp = q.front();
            q.pop();
            res.push_back(temp);
            // remove the 0 indegree node and all its directed edges, put all new 0 indegree nodes into queue
            for (auto c : mp[temp]) {
                indeg[c]--;
                if (indeg[c] == 0) q.push(c);
            }
        }
        
        /** if there are nodes left in the graph, cycle detected, invalid tree*/
        if (res.size() == numCourses) return res;
        res.clear();
        return res;
    }
};