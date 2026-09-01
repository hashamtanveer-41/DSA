class Solution {
public:
int nextPermutation(vector<int>& nums) {
    // Solution using Generation in lexicographic order on wikipedia
    int n = nums.size();
    if (n==1)return -1;
    int k = -1;
    int l = -1;
    // Find index k by condition nums[k] < nums[k+1]
    for (int i=n-2; i>=0; i--) {
        if (nums[i]<nums[i+1]) {
            k = i;
            break;
        }
    }
    if (k==-1) {
        // not possible to get the value
        return -1;
    }
    // find l
    for (int i= k+1; i<n; i++)
        if (nums[k]<nums[i])
            l = i;
    // i have both k and l ready now swap them
    swap(nums[k], nums[l]);
    reverse(nums.begin()+k+1, nums.end());
    return 0;
}
int nextGreaterElement(int n) {
    vector<int> nums;
    while(n>0){
        nums.push_back(n%10);
        n = n/10;
    }
    reverse(nums.begin(), nums.end());
    if (nextPermutation(nums)==-1)return -1;
    long long ans = 0;
    for(int i= 0; i<nums.size(); i++){
        ans = ans*10 + nums[i];
    }
    if(ans>INT_MAX)return -1;
    return (int)ans;
}
};