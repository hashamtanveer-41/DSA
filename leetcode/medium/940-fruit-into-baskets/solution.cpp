class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // code here
        int low = 0, high = 0, res = 0, n = fruits.size();
        unordered_map<int, int> f;
        for (high = 0; high< n; high++)
        {
            f[fruits[high]]++;
            while (f.size()>2)
            {
                f[fruits[low]]--;
                if (f[fruits[low]]==0)f.erase(fruits[low]);
                low++;
            }
                int len = high -low +1;
                res = max(len , res);
        }
    return res;
}
};