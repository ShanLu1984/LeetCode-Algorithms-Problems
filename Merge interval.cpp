// Two overlapping intervals itv1 and itv2, the merge interval itv:
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
    vector<Interval> merge(vector<Interval>& intervals) {
        
        /** sort the intervals with the start; */
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b) {return a.start < b.start;});
        
        vector<Interval> res;
        if (intervals.size() == 0) return res;
        
        /** current interval is the one need to check for merge at current time*/
        // if interval[i].start > interval_cur.end, interval_cur has no merging activity, output it.
        Interval interval_cur = intervals[0];
        for (int i=1; i<intervals.size(); ++i) {
            if (intervals[i].start > interval_cur.end) {
                res.push_back(interval_cur);
                interval_cur = intervals[i];
            } else {
                interval_cur.end = max (interval_cur.end, intervals[i].end);
            }
        }
        // don't forget to push the last interval;
        res.push_back(interval_cur);
        return res;
    }
};