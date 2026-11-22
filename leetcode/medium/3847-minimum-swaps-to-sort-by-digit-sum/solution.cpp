class Solution {
public:
int digitSum(int digit){
    int res = 0;
    while(digit>0){
        res += digit % 10;
        digit = digit/10;
    }
    return res;
}
int minSwaps(vector<int>& nums) {
    int swaps = 0;
    int n = nums.size();
    unordered_map<int, int> mp;
    vector<int> old = nums;
    for(int i=0; i<n; i++)
        mp[nums[i]] = i;
    auto lambda = [this](int num1, int num2) {
        int sum1 = digitSum(num1);
        int sum2 = digitSum(num2);
        if (sum1!=sum2)
            return sum1<sum2;
        return  num1<num2;
    };
    sort( nums.begin(), nums.end(), lambda);
    for (int i=0; i<n; i++) {
        int currCorrect = nums[i];
        int oldIdx = mp[currCorrect];
        if (oldIdx==i)continue;
        int toReplace = old[i];
        mp[currCorrect] = i;
        mp[toReplace] = oldIdx;
        swap(old[i], old[oldIdx]);
        swaps++;
    }
    return swaps;
}
};