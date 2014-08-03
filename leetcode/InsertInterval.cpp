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
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        int l = 0, r = intervals.size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (newInterval.start == intervals[mid].end) {
                l = mid;
                break;
            }
            else if (newInterval.start > intervals[mid].end) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        int start = l;
        r = intervals.size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (newInterval.end == intervals[mid].start) {
                r = mid;
                break;
            }
            else if (newInterval.end > intervals[mid].start) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        int end = r;
        if (start < intervals.size()) {
            newInterval.start = min(newInterval.start, intervals[start].start);
        }
        if (end >= 0) {
            newInterval.end = max(newInterval.end, intervals[end].end);
        }
        intervals.erase(intervals.begin() + start, intervals.begin() + end + 1);
        intervals.insert(intervals.begin() + start, newInterval);
        return intervals;
    }
};