class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
    int n = nums.size();
    int currOnes = 0;
    int res = 0;
    for (int i=0; i<n; i++) {
        if (nums[i]==1)currOnes++;
        else {
            if (currOnes>0) {
                res = max(res, currOnes);
                currOnes =0;
            }
        }
    }
    if (currOnes>res)return currOnes;
    return res;
}
};