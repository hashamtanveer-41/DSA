class Solution {
public:
    int minOperations(string s) {
    int n = s.size();
    int  right = n-1;
    int res = INT_MAX;
    for (int left=0; left< n; left++) {
        if (left!=0)right = left-1;
        int low = left;
        int high = right;
        int counter = n/2;
        int runningSum = 0;
        while (counter--) {
            char leftChar = s[low];
            char rightChar = s[high];
            int diff = rightChar - leftChar;
            // left to right cost
            int leftCost = 0, rightCost = 0;
            if (diff<0) {
                // for case y to b
                // y to z then z to a then a to b
                // come from leftCHar to z first then to right char
                leftCost = ('z' - leftChar )+ 1 + rightChar - 'a';
            }else {
                // for case b to d
                // b to c then c to d
                // Directly come to d
                leftCost = rightChar - leftChar;
            }
            // Right to left cost
            // Same as above but reverse now
            if (diff<0) {
                // for case y to b where y is left and b is right
                // i have to go from right to left
                // from b to y
                rightCost = leftChar- rightChar ;
            }else {
                // for case b to d where b is left and d is right
                // d to b, first d to z then z to a then a to b
                rightCost = ('z' - rightChar )+ 1 + leftChar - 'a';

            }

            runningSum += min(leftCost, rightCost);

            low++;
            if (low==n)low=0;
            high--;
            if (high<0)high = n-1;
        }
        runningSum +=left;
        res = min(runningSum, res);
    }
    return res;
}
};