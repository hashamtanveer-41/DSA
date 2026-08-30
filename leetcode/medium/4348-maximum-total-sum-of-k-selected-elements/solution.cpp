class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        int n =nums.size();
        sort(nums.begin(), nums.end());
        long long sum = 0;
        int idx =n-1;
    
        for(int i =n-1; k!=0; i--){
            if(mul>0){
                long long prod = static_cast<long long>(nums[i])*mul;
                mul--;
                sum += prod;
            }else{
                sum +=nums[i];
            }
            k--;
        }
        return sum;
    }
};