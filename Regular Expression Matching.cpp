// Dynamic programming: dp[i][j], whether s[0:i-1] and p[0:j-1] matches;
// Time complexity: O(n^2)
// Space complexity: O(n^2)

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true;
        for (int i=0; i<=n; ++i) {
            for (int j=1; j<=m; ++j) {
                if (p[j-1] != '*') {
                    dp[i][j] = (i > 0 && dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.'));
                }
                else {
                    // the case when 'c*' matches 0 of the preceeding c; such as “a” and “ac*”
                    if (dp[i][j-2]) {dp[i][j] = true; continue;}
                    
                    // the case when 'c*' mathches > 0 of the preceeding c;
                    if (i > 0 && dp[i-1][j] && (s[i-1] == p[j-2] || p[j-2] == '.')) {
                        dp[i][j] = true; continue;
                    }
                }
            }
        }
        return dp[n][m];
    }
};