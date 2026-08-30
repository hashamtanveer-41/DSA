class Solution {
public:

long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
     int n = nums1.size();
    vector<pair<int, int>> arr;
    for (int i=0; i<n; i++) {
        arr.push_back({nums2[i],nums1[i] });
    }
    sort(arr.rbegin(), arr.rend());
    priority_queue<int, vector<int> , greater<int>> minHeap;
    long long sum = 0;
    long long res = 0;
    for (int i=0; i<n;i++) {
        minHeap.push(arr[i].second);
        sum += arr[i].second;
        if (minHeap.size()>k) {
            sum -= minHeap.top();
            minHeap.pop();
        }
        if (minHeap.size()==k) {
            long long score = sum * arr[i].first;
            res = max(score, res);
        }
    }
    return res;
}
};