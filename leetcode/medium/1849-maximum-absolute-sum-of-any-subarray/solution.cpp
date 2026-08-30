class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int min = minSum(nums);
        int max = maxSum(nums);

        if(abs(min)>max)return abs(min);
        return max;    
    }

    int maxSum(vector<int>& nums){
        int bestEnding = nums[0];
        int ans= nums[0];

        for(int i =1; i< nums.size(); i++){
            int v1 = bestEnding +nums[i];
            int v2 = nums[i];
            bestEnding = max(v1, v2);
            ans = max(bestEnding, ans);
        }
        return ans;
    }
    int minSum(vector<int>& nums){
        int bestEnding = nums[0];
        int ans= nums[0];

        for(int i =1
        ; i< nums.size(); i++){
            int v1 = bestEnding +nums[i];
            int v2 = nums[i];
            bestEnding = min(v1, v2);
            ans = min(bestEnding, ans);
        }
        return ans;
    }
};