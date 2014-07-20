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
    static bool comp(Interval i, Interval j) {
        return i.start < j.start;
    }
    vector<Interval> merge(vector<Interval> &intervals) {
        if (intervals.empty()) return intervals;
        sort(intervals.begin(), intervals.end(), comp);
        int storeIndex = 0, i = 1;
        while (i < intervals.size()) {
            if (intervals[i].start <= intervals[storeIndex].end) {
                intervals[storeIndex].end = max(intervals[i].end, intervals[storeIndex].end);
            }
            else {
                storeIndex ++;
                intervals[storeIndex].start = intervals[i].start;
                intervals[storeIndex].end = intervals[i].end;
            }
            i++;
        }
        intervals.erase(intervals.begin() + storeIndex + 1, intervals.end());
        return intervals;
    }
};