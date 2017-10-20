// Dynamic programming: dp[i], the substring from index 0 to i-1 can be segmented;
//                      dp[0] = true;
//                      dp[i] = true, if for any j < i, dp[j] = true and s[j,i-1] is in Dict;
// space complexity: O(n)
// time complexity: O(n^2)

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> st;
        for (auto w : wordDict) {
            st.insert(w);
        }
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int i=1; i<=n; ++i) {
            for (int j=0; j<i; ++j) {
                if (dp[j] == false) continue; 
                string temp = s.substr(j, i-j);
                if (st.find(temp) == st.end()) continue;
                dp[i] = true;
                break;
            }
        }
        return dp[n];
    }
};