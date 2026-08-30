class Solution {
public:
    int findMin(vector<int>& nums) {
    int n = nums.size();
    if (n==0)return -1;
    int low =0, high = n, res = -1;
    int guess = 0;
    while(low<=high){
        guess = (high+low)/2;
        if (guess == n)break;
        if(nums[guess]>nums[n-1])
        {
            low = guess+1;
        }
        else{
            res = guess;
            high = guess-1;
        }

    }
    return nums[res];
}
    
};