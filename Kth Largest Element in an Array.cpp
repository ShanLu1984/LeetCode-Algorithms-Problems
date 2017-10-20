215. Kth Largest Element in an Array
// Method 1: priority_queue
// space complexity: O(n)
// time complexity: O(nlogn)

int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int> pq(nums.begin(), nums.end());
    while (--k) {
        pq.pop(); 
    }
    return pq.top();
}



// Method 2: Quick select
// space complexity: O(1)
// time complexity: Worst-case performance:О(n^2) Average performance:O(n)

int findKthLargest(vector<int>& nums, int k) {
    int pivot = 0, right = nums.size() - 1;
    while (true) {
        int l = pivot + 1, r = right;
        // all the elements larger than pivot one goes to the left;
        // finally, l point to the first one smaller or equal to pivot;
        // r point to the last one larger than pivot;
        while (l <= r) {
            if (nums[l] <= nums[pivot] && nums[r] > nums[pivot]) {
                swap(nums[l++], nums[r--]);
            }
            if (nums[r] <= nums[pivot]) r--;
            if (nums[l] > nums[pivot]) l++;
        }
        // swap to make pivot one in the right position (decreasing order)
        swap(nums[pivot], nums[r]);
        // if r+1 == k, pivot is the kth largest one; return;
        // if r+1 < k, the kth largest one should be on the right side of pivot;
        // if r+1 > k, the kth largest one should be on the left side of pivot;
        if (r + 1 == k) return nums[r];
        else if (r + 1 < k) {
            pivot = r + 1;
        } else {
            right = r - 1;
        }
    }
 }