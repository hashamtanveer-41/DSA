class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
    int left = 0, right = n-1;
    int res = INT_MIN;
    while (left<right) {
        int currArea = (right-left) * min(height[left], height[right]);
        res = max(currArea, res);
        if (height[left]<height[right])left++;
        else right--;
    }
    return res;
    }
};