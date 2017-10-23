// using vector and unordered_map;
// insert(val), remove(val) and getRandom: O(1) time complexity

class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    vector<pair<int, int>> nums; // (num, postion at the mp[num])
    unordered_map<int, vector<int>> mp;  //num -> array of positions in the nums
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool res;
        if (mp.find(val) == mp.end()) res = true;
        else res = false; // if there is no element has value val, return true; otherwise return false;
        mp[val].push_back(nums.size()); // the position of the new elment if nums.size();
        nums.push_back(make_pair(val, mp[val].size() - 1)); // put it in the back, with its position to be the last element in map[val];
        return res;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (mp.find(val) == mp.end()) return false;
        // get the pos of the last one with value val; the informaiton of the element at the back of the vector;
        int pos = mp[val].back();
        int back_val = nums.back().first;
        int back_pos_in_map = nums.back().second;
        // replace the elements at the pos with the one at the back of the vector;
        nums[pos] = nums.back();
        // update the original back one's position in the vector;
        mp[back_val][back_pos_in_map] = pos;
        // remove the one in the back of the vector; remove the its position in the map;
        nums.pop_back();
        mp[val].pop_back();
        // if there is no elements with value val, erase it;
        if (mp[val].empty()) mp.erase(val);
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        // access to an elment in array given position, O(1);
        return nums[rand() % int(nums.size())].first;
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */