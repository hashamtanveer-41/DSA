class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
       int n = nums.size();
    int minIdx = 0;
    int maxIdx = 0;
    for (int i=0; i<n; i++) {
        if (nums[i]<nums[minIdx]) {
            minIdx = i;
        }else if (nums[i]>nums[maxIdx]) {
            maxIdx = i;
        }
    }
    // i have idx for min and max val
    int i, j;
    if (minIdx>maxIdx) {
        i = maxIdx, j = minIdx;
    }else {
        i = minIdx ,j = maxIdx;
    }
    return min({n-i, j+1, (i+1)+(n-j)});
    }
};