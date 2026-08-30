class Solution {
public:
    bool search(vector<int>& nums, int target) {
    int n = nums.size();
    int low =0, high = n-1;
    int guess = 0;
    if (n==0)return false;
    while(low<=high){
        guess = low+ (high-low)/2;
        if (guess == n)break;
        if(nums[guess]==target)return true;
        if(nums[guess]>nums[n-1]){
            if(nums[guess]<target){
                low = guess +1;
            }else{
                if(nums[0]>target){
                    low = guess +1;
                }else{
                    high = guess-1;
                }
            }
            continue;
        }else if (nums[guess]==nums[n-1]) {
            if (nums[high]==target)return true;
            else high--;
        }
        else{
            if(nums[guess]>target){
                high = guess -1;
            }else{
                if(nums[n-1]<target){
                    high = guess -1;
                }else{
                    low = guess +1;
                }
            }
        }
    }
    return false;
    }
};