class Solution {
public:
    int maxSum(vector<int>& nums){
        int bestEnding = nums[0];
        int result = nums[0];

        for(int i = 1; i< nums.size(); i++){
            int v1 = nums[i] + bestEnding;
            int v2 = nums[i];
            bestEnding = max(v1 ,v2);
            result= max(result, bestEnding );
        }

        return result;
    }
    int minSum(vector<int>& nums){
            int bestEnding = nums[0];
            int result = nums[0];

            for(int i = 1; i< nums.size(); i++){
                int v1 = nums[i] + bestEnding;
                int v2 = nums[i];
                bestEnding = min(v1 ,v2);
                result= min(result, bestEnding );
            }

            return result;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
    
        int maxDirectSum = maxSum(nums);
        int minDirectSum = minSum(nums);
        int sum = nums[0];
        for(int i = 1; i<nums.size(); i++){
            sum += nums[i];
        }

        int maxCircularSum = sum - minDirectSum;
        if(maxCircularSum == 0)return maxDirectSum;
        return max(maxDirectSum, maxCircularSum);
    }
};