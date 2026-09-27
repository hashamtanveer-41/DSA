class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& intervals) {
     int n = intervals.size();
    int count = 0;
    sort(intervals.begin(), intervals.end());
    for (int read=0; read<n ; read++) {
        int start = intervals[read][0];
        int end = intervals[read][1];
        for (int j= read+1; j<n; j++) {
            int s = intervals[j][0];
            int e = intervals[j][1];
            if (s<=end) {
                count++;
            }
        }
    }
    return count;
    }
};