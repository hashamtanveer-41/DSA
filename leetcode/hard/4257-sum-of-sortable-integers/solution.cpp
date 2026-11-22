class Solution{
    public:
bool checkRotationSorted(const vector<int>& nums, int left, int right, int& val, int& valStart) {
    int breakPoints = 0;
    int maxCurr = 0;
    int minCurr = INT_MAX;
    for (int i=left; i<right; i++) {
        maxCurr = max(maxCurr, nums[i]);
        minCurr = min(minCurr, nums[i]);
        if (nums[i]>nums[i+1])
            breakPoints++;
    }
    maxCurr = max(nums[right], maxCurr);
    minCurr = min(nums[right], minCurr);
    if (nums[right]>nums[left])
        breakPoints+=1;
    val = maxCurr;
    valStart = minCurr;
    return breakPoints<=1;
}
int sortableIntegers(vector<int>& nums) {
    int n = nums.size();
    int sq = sqrt(n);
    int res = 0;
    vector<int> possibleDivisors;
    for (int i=1; i<=sq; i++) {
        if (n%i==0) {
            possibleDivisors.push_back(i);
            if ((n/i) == i)continue;
            possibleDivisors.push_back(n/i);
        }
    }
    for (int i=1; i<possibleDivisors.size(); i++) {
        int currWindow = possibleDivisors[i];
        int maxVal = INT_MIN;
        bool is = true;
        for (int j=0; j<n; j+=currWindow) {
            int val = 0;int valStart = 0;
            if (!checkRotationSorted(nums, j, j+currWindow-1, val, valStart)) {
                is = false;
                break;
            }
            if (val<maxVal || valStart<maxVal) {
                is = false;
                break;
            }
            maxVal = val;
        }
        if (is)
            res +=currWindow;
    }
    // Check for 1
    bool is = true;
    for (int i=0; i<n-1; i++) {
        if (nums[i]>nums[i+1]) {
            is = false;
            break;
        }
    }
    if (is)
        res+=1;
    return res;
}
};