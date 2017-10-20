// Two overlapping intervals itv1 and itv2, the merge interval itv;
// itv.start = min (itv1.start, itv2.start); itv.end = max(itv1.end, itv2.end); 
// space complexity: O(1)
// time complexity: O(n)

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;
        int i = 0;
        // push the intervals on the left of the newInterval into the result vector;
        while (i < intervals.size() && intervals[i].end < newInterval.start) 
            res.push_back(intervals[i++]);
        // if there is an interval overlapping with the newInterval, update the newInterval
        while (i < intervals.size() && newInterval.end >= intervals[i].start) {
            newInterval.start = min(intervals[i].start, newInterval.start);
            newInterval.end = max(intervals[i].end, newInterval.end);
            i++;
        }
        // push the updated newInterval into the result vector;
        res.push_back(newInterval);
        // push the intervals on the right of the newInterval into the result vector;
        while (i < intervals.size()) 
            res.push_back(intervals[i++]);
        return res;
    }
};