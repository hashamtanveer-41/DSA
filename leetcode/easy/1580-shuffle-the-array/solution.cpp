class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
    vector<int> res(2*n);
    int left =0, right = n, i=0;
    while (right<2*n) {
        res[i] = nums[left];
        res[i+1]=nums[right];
        left++;
        right++;
        i+=2;
    }
    return res;
}
};