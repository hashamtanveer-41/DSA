class Solution {
public:
    int minMoves2(vector<int>& nums) {
      sort(nums.begin(), nums.end());
      int n = nums.size();
      int res = 0;
      int val = 0;
      if(n%2!=0){
        val = nums[n/2];
      }else{
        val = (nums[n/2]+nums[(n/2)-1])/2;
      }
      for(int num: nums)
        res += abs(val-num);
    return res;
    }
};