class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
         int n = nums.size();
        vector<int> pMax; 
        vector<int> sMin(n);
        int val = nums[0];
        for (int num : nums){
            val = max(val, num);
            pMax.push_back(val);
        }
        val = nums[n-1];
        for (int i = n-1; i>=0; i--){
            val = min(nums[i] , val);
            sMin[i]= val;
        }
        for (int i = 0; i<n; i++){
            if(pMax[i]-sMin[i]<=k){
               return i;
            }
        }
    return -1;
    }
};