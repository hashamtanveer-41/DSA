class Solution {
public:
    int countConsistent(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        for(int i=0; i<n; i++){
            int minVal = nums[i];
            int andVal = nums[i];
            for(int j=i; j<n; j++){
                minVal = min(nums[j], minVal);
                andVal = andVal&nums[j];
                if(andVal == minVal)
                    res++;
            }
        }
        return res;
    }
};