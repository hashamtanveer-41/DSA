class Solution {
public:
int search(vector<int>& nums, int target) {
    int n = nums.size();
     int low =0, high = n, res = -1;
    int guess = 0;
    
    while(low<=high){
        guess = (high+low)/2;
        if (guess == n)break;
        if(nums[guess]==target)return guess;
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
        }else{
            if(nums[guess]>target){
                high = guess -1;
            }else{
                if(nums[n-1]<target){
                    high = guess -1;
                }else{
                    low = low +1;
                }
            }
        }    
    }
    return -1;
}
};