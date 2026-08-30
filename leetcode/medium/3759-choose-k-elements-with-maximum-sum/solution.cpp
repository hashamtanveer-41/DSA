class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
    int n = nums1.size();
    vector<pair<int, int>> pairs(n);
    for (int i=0; i< n; i++) {
        pairs[i]={nums1[i], i};
    }
     sort(pairs.begin(), pairs.end());
    priority_queue<int, vector<int> , greater<>> minHeap;
    long long runningSum =0;
    vector<long long >res(n);
    int j = 0;
    for (int i =0; i< n; i++) {
        while (j< i  && pairs[j].first < pairs[i].first) {
            runningSum  += nums2[pairs[j].second];
            minHeap.push(nums2[pairs[j].second]);
            while (minHeap.size()>k) {
                runningSum -= minHeap.top();
                minHeap.pop();
            }
            j++;
        }
        res[pairs[i].second]=runningSum;
    }
    return res;
    }
};