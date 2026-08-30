class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if (intervals.empty()) return {};

    // Step 1: Sort by starting times
    sort(intervals.begin(), intervals.end());

    // Step 2: Initialize Write Pointer
    int write = 0;

    // Step 3: Iterate with Read Pointer
    for (int read = 1; read < intervals.size(); read++) {

        // Overlap condition: Read interval starts before/when Write interval ends
        if (intervals[read][0] <= intervals[write][1]) {
            // Merge them by updating the end time of the Write interval
            intervals[write][1] = max(intervals[write][1], intervals[read][1]);
        }
        // No overlap condition
        else {
            // Move Write pointer forward and bring the new interval into position
            write++;
            intervals[write] = intervals[read];
        }
    }

    // Step 4: Chop off the leftover garbage at the end of the array
    intervals.resize(write + 1);

    return intervals;
}
long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
    int totalActiveBulbs = (brightness + 2) / 3;
    merge(intervals);
    long long totalActiveHours =0;
    for (int i=0; i<intervals.size(); i++) {
        totalActiveHours += intervals[i][1]-intervals[i][0] +1;
    }
    long long res = 1LL*totalActiveBulbs * totalActiveHours;
    return res;
}
};