class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int diff = 0, max_diff = INT_MAX, res_sum= 0;
    int n = nums.size();
    for(int i = 0; i<n-2; i++){
        int left = i+1;
        int right = n-1;

        while(left<right){
            int sum = nums[left]+ nums[right]+ nums[i];
            diff = abs(sum - target);
            if (diff<max_diff)
            {
                max_diff = diff;
                res_sum = sum;
            }
            else if (sum< target)
            {
                left++;
            }else
            {
                right--;
            }
        }

    }
    return res_sum;
}
};