class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
    int left =0, right =0;
    int res = 1e8;
    for(int i=0; i<n; i++){
        int sum = 0;
        for(int j=i;j<n; j++){
            sum+=nums[j];
            int windSize = j - i +1;
            if(windSize>=l && windSize<=r){
                if(sum>0)
                 res = min(res, sum);
            }else if(windSize>r){
                break;
            }

        }
    }
    // while(right<n){
    //     sum+=nums[right];
    //     int windSize = right - left +1;
    //     while (right <n && windSize<l) {
    //         right++;
    //         sum+=nums[right];
    //          windSize = right - left +1;
    //     }
    //     if(windSize>=l && windSize<=r){
    //         // valid
    //         if(sum>0)
    //             res = min(res, sum);
    //     }
    //      if (windSize>r){
    //         // invalid
    //         sum-=nums[left];
    //         left++;
    //     }
    //     right++;
    // }
    return res==1e8?-1:res;
    }
};