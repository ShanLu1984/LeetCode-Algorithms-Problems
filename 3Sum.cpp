// Method: two pointers
// Space Complexity:  O(1)
// Time complexity: O(n^2)

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());  // time: O(nlogn)
        vector<vector<int>> res;
        for (int i=0; i<nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue; // avoid duplicates
            int target = -nums[i];  // the target sum of the numbers of two pointers is -nums[i]
            int l = i + 1, r = nums.size() - 1; // two pointers l and r
            while (l < r) {
                int nl = nums[l], nr = nums[r];
                if (nl + nr == target) {
                    res.push_back({nums[i], nl, nr});
                    while (nums[l] == nl) l++; // avoid duplicates
                    while (nums[r] == nr) r--; // avoid duplicates
                } else if (nl + nr > target) {
                    r--;
                } else {
                    l++;
                }
            }
        }
        return res;
    }
};