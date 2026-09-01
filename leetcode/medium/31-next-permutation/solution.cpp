class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
    if (n==1)return;
    int k = -1;
    int l = -1;
    // Find index k by condition nums[k] < nums[k+1]
    for (int i=n-2; i>=0; i--) {
        if (nums[i]<nums[i+1]) {
            k = i;
            break;
        }
    }
    if (k==-1) {
        // not possible to get the value
        sort(nums.begin(), nums.end());return;
    }
    // find l
    for (int i= k+1; i<n; i++)
        if (nums[k]<nums[i])
            l = i;
    // i have both k and l ready now swap them
    swap(nums[k], nums[l]);
        reverse(nums.begin()+k+1, nums.end());

    }
};