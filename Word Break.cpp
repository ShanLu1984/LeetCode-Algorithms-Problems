// Dynamic programming: dp[i], the substring from index 0 to i-1 can be segmented;
//                      dp[0] = true;
//                      dp[i] = true, if for any j < i, dp[j] = true and s[j,i-1] is in Dict;
// space complexity: O(n)
// time complexity: O(n^2)

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        // put all the words in the Dict into a unorder_set, so the time for search is O(1)
        unordered_set<string> st;
        for (auto w : wordDict) {
            st.insert(w);
        }
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int i=1; i<=n; ++i) {
            for (int j=0; j<i; ++j) {
                if (dp[j] == false) continue; // dp[j] is false, then no need to check s[j,i-1];
                string temp = s.substr(j, i-j);
                if (st.find(temp) == st.end()) continue; //s[j,i-1] is not in Dict, so false;
                dp[i] = true; // dp[j] is true and s[j,i-1] is in Dict, can be segmented, dp[i] = true;
                break;
            }
        }
        return dp[n];
    }
};
