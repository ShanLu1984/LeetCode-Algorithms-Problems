// two pointers, starting position of a string length 3 is
//            l     r
//            0     0
//            0     1
//            1     1
//            1     2
//            2     2
// i = 0, 1, 2, 3, 4 (i < 2 * 3 - 1): l = i / 2,  r = (i + 1) / 2;
// space complexity: O(1)
// time complexity: O(n^2)

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int l, r;
        string res;
        for (int i=0; i<2*n-1; ++i) {
            // l is the left starting position; r is the right starting position;
            // when l == r, means the length of the palindromic is odd, such as “aba”;
            // when l != r, means the length of the palindromic is even, such as “abba”;
            l = i / 2; r = (i + 1) / 2;
            string temp = helper(s, l, r);
            if (temp.size() > res.size()) {
                res = temp;
            }
        }
        return res;
    }
    
    /** helper function used to return the longest palindrome with the starting position (l, r); */
    string helper(string &s, int l, int r) {
        int len = 0;
        while (l >= 0 && r < s.size()) {
            if (l != r && s[l] != s[r]) break;
            if (l == r) {
                len += 1;
            } else if (s[l] == s[r]) {
                len += 2;
            }
            l--;
            r++;
        }
        return s.substr(l + 1, len);
    }
};
