class Solution {
public:

    int lowest(vector<int>& nums, int x )
{// code here
        int n = nums.size();
    if (n==0)return -1;
        int low =0, high = n, res = -1;
    int guess = 0;
        while(low<=high){
            guess = (high+low)/2;
            if (guess == n)break;
            if(nums[guess]<x)low = guess+1;
            else if (nums[guess]>x)high = guess-1;
            else{
                res = guess;
                high = high-1;
            }
        }
        return res;

}
int highest(vector<int>& nums, int x )
{// code here
    int n = nums.size();
    if (n==0)return -1;
    int low =0, high = n, res = -1;
    int guess = 0;
    while(low<=high){
        guess = (high+low)/2;
        if (guess == n)break;
        if(nums[guess]<x)low = guess+1;
        else if (nums[guess]>x)high = guess-1;
        else{
            res = guess;
            low = low+1;
        }
    }
    return res;

}
vector<int> searchRange(vector<int>& nums, int target) {
        int min = lowest(nums, target);
        int max = highest(nums, target);
    return {min, max};
}
};