// Dynamic programming
// Space Complexity:  O(n)
// Time complexity: O(n)

class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') return 0;
        int n = s.size();
        vector<int> dp(n, 0); // dp[i]: the decode ways of substring from begining to the current position i;
        dp[0] = 1;
        for (int i=1; i<s.size(); ++i) {
            if (s[i] != '0') dp[i] += dp[i-1]; // this is the case that s[i] is representing letter from
                                               // 'A' to 'I';
            
            // if s[i] == '0' and the previous s[i-1] is neither '1' or '2', then fail to decode;
            if (s[i] == '0' && s[i-1] != '1' && s[i-1] != '2') return 0; 
            
            // this is the case that s[i-1] and s[i] representing letters from 'J' to 'Z'
            if (s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6')) {
                if (i == 1) dp[i] += 1;
                else dp[i] += dp[i-2]; 
            }
        }
        return dp[n-1];
    }
};