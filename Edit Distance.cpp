// Method: Dynamic programming
// Space Complexity:  O(n^2)
// Time complexity: O(n^2)

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        // dp[i][j], edit distance between word1[0..i-1] and word2[0..j-1]
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for(int i=1; i<m+1; ++i) dp[i][0] = i;
        for(int j=1; j<n+1; ++j) dp[0][j] = j;
        
        for(int i=1; i<m+1; ++i) {
            for (int j=1; j<n+1; ++j) {
                if(word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    // dp[i][j] = dp[i - 1][j - 1] + 1(for replacement, replace word1[i-1] with word2[j-1])
                    // dp[i][j] = dp[i - 1][j] + 1 (for deletion, delete word1[i-1])
                    // dp[i][j] = dp[i][j - 1] + 1 (for insertion, insert word2[j - 1] to word1[0..i - 1])
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j])) + 1; 
                }
            }
        }
        return dp[m][n];
    }
};