class Solution {
public:
    int lengthOfLongestSubstring(string fruits) {
        // code here
        int low = 0, high = 0, res = 0, n = fruits.size();
        unordered_map<char, int> f;
        for (high = 0; high< n; high++)
        {
            f[fruits[high]]++;
            int k = high - low +1;
            while (f.size()<k)
            {
                f[fruits[low]]--;
                if (f[fruits[low]]==0)f.erase(fruits[low]);
                low++;
            k = high - low +1;
            }
                int len = high -low +1;
                res = max(len , res);
        }
    return res;
}
};