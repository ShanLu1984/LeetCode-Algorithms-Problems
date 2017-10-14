//Space Complexity:  O(n)
//int get(int key);        Time complexity: O(1)
//void put(int key, int value);        Time complexity: O(1)

class LFUCache {
public:
    unordered_map<int, pair<int, int>> mp1; //key->(val, freq);
    unordered_map<int, list<int>::iterator> mp2;  // key->iterator;
    //The items with the same frequency keep in the same list.
    unordered_map<int, list<int>> mp3; // freq->list
    int cap, num = 0, minfreq = 0;

    LFUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        if (mp1.find(key) == mp1.end()) return -1;// the key is not found;

        // get the current information of the key;
        int val = mp1[key].first;
        int freq = mp1[key].second;
        auto it = mp2[key];
        // update the information of the key;
        mp1[key].second = freq + 1;  // frequency increases 1;
        mp3[freq+1].push_front(key);  // put in the front of the list of the new frequency;
        mp2[key] = mp3[freq+1].begin();
        mp3[freq].erase(it);  // erase the current key from original frequency list;
        // update the minfreq
        if (mp3[minfreq].empty()) minfreq++; // if this key is the last one in the minfreq list,
                                             // then minfreq++;
        return val;
    }

    void put(int key, int value) {
        if (cap == 0) return;
        // use get(int key) function to update the position of the key if the key exist;
        int val = get(key);
        if (val == -1) {
            if (num == cap){
                // erase the least recent one in the least frequent list;
                int lastKey = mp3[minfreq].back();
                mp3[minfreq].pop_back();
                mp2.erase(lastKey);
                mp1.erase(lastKey);
                num--;
            }
            // put the new one into the frequency 1 list
            mp1[key].second = 1;
            minfreq = 1;
            mp3[1].push_front(key);
            mp2[key] = mp3[1].begin();
            num++;
        }
        // update the value of the current key;
        mp1[key].first = value;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
