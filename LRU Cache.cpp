//Space Complexity:  O(n)
//int get(int key);        Time complexity: O(1)
//void put(int key, int value);        Time complexity: O(1)

class LRUCache {
public:
    list<int> l;
    unordered_map<int, pair<int, list<int>::iterator>> mp; // map: key -> (value, iterator)
    int cap;

    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;
        // get the key's current information
        auto pos = mp[key].second;
        int val = mp[key].first;
        // update the key's information
        l.push_front(key);
        l.erase(pos);
        mp[key].second = l.begin();
        return val;
    }

    void put(int key, int value) {
        // use get(key) to check if key exists in the list;
        //if yes, the information of the key is updated already;
        int vtemp = get(key);
        if (vtemp == -1) { // if no
            if (l.size() == cap) { // erase the least recent key
                int lastKey = l.back();
                l.pop_back();
                mp.erase(lastKey);
            }
            l.push_front(key);  // put the key to the front of the list
            mp[key].second = l.begin();
        }
        mp[key].first = value;

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
