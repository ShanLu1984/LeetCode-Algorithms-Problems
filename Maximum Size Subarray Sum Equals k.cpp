// Space Complexity:  O(n)
// Time complexity: O(n)

class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int, int> mp; // sum -> the smallest index that sum equals sum
        mp[0] = -1;
        int sum = 0;
        int res = 0;
        for (int i=0; i<nums.size(); ++i) {
            sum += nums[i];
            if (mp.find(sum-k) != mp.end()) {
                res = max(res, i-mp[sum-k]);
            }
            if (mp.find(sum) == mp.end()) mp[sum] = i;
        }
        return res;
    }
};
