class Solution {
public:
    int smallestIndex(vector<int>& nums) {
         int n = nums.size();
    for (int i=0; i<n; i++) {
        int sum = 0;
        int tens = nums[i] % 10;// last
        int digit2nd = (nums[i]/10) % 10;
        int digit3rd = (nums[i]/100)%10;
        sum += tens + digit2nd+digit3rd;
        if(nums[i]==1000)sum+=1;
        if (sum==i)return i;
    }
    return -1;
    }
};