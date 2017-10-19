// Method 1: binary search

// Space Complexity:  O(1)
// Time complexity: O(nlogn)


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int count = 0;
            for (auto n : nums) {
                if (n <= mid) {
                    count++;
                }
            }
            if (count > mid) r = mid - 1;
            else l = mid + 1;
        }
        return l;
    }
};

// Method 2: cycle detection

// Space Complexity:  O(1)
// Time complexity: O(n)

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       
       int slow = 0;
       int fast = 0;
       
       while (slow != fast || slow == 0) {
           slow = nums[slow];
           fast = nums[fast];
           fast = nums[fast];
       }
       slow = 0;
       while (slow != fast) {
           slow = nums[slow];
           fast = nums[fast];
       }
       return slow;
    }
};


