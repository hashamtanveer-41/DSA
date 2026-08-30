class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<vector<int>> result;
    for (int j=0; j<n-3; j++) {
        int s1 = nums[j];
        if(j>0 && nums[j]== nums[j-1]) continue;
        for(int i = j+1; i< n-2 ; i++){

            if(i>j+1 && nums[i]== nums[i-1]) continue;
            int left = i+1;
            int right = n-1;

            long long sum = (long long)(s1+ nums[i]);

            while(left< right){

                long long s = (long long)(nums[left] + nums[right]+sum);
                if(target == s){
                    vector<int> ans = {nums[j], nums[i], nums[left],nums[right]};
                    result.push_back(ans);
                    left++;
                    right--;
                    while(left<right && nums[left]==nums[left-1]){
                        left++;
                    }
                    while(left<right && nums[right]==nums[right+1]){
                        right--;
                    }
                }else if(s< target){
                    left++;
                }else{
                    right--;
                }
            }
        }
    }
    return result;
}
};