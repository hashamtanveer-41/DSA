class Solution {
public:
    int maxSubarray(vector<int>& nums) {
        int n= nums.size();
    int ans = 0;
    int start = 0, end = 0;
    map<int, int> mp;
    while (end<n) {
        int x = nums[end];
        while (start<end) {
            bool is = true;
            for (auto& it: mp) {
                if ((mp.count(x - it.first) && ((x - it.first )!= it.first || it.second> 1))  || mp.count(x + it.first)){
                    is = false;
                    break;
                }
            }
            if (is)
                break;
            mp[nums[start]]--;
            if (mp[nums[start]]==0)
                mp.erase(nums[start]);
            start++;
        }
        mp[x]++;
        ans = max(ans, end - start + 1);
        end++;
    }
    return ans;
    }
};