class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
    int n = nums.size();
    int left =0, right =0;
    double maxAvg = INT_MIN, currSum = 0.0;
    while (right<n) {
        int windowSize = right-left+1;
        currSum +=nums[right];
        if (windowSize==k) {
            double currAvg = currSum/k;
            maxAvg = max(maxAvg, currAvg);
            currSum-=nums[left];
            left++;
        }
        right++;
    }
    return maxAvg;
}
};