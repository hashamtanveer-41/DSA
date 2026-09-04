class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        int maxVal = 0;
        int res=0;
        for(int i=0; i<n; i++){
            maxVal = max(nums[i], maxVal);
            int minVal = nums[i];
            for(int j=i; j<n; j++){
                minVal = min(minVal, nums[j]);
            }
            if(maxVal-minVal<=k)return i;
        }
        return -1;
    }
};