class Solution {
public:
    int jump(vector<int>& nums) {
     int n= nums.size();
    int reach = 0;
    int jumps = 0;
    int left = 0;
    while (left<n){
        if (reach>=n-1)return jumps;

        // i have to take one jump atleast
        // Curr is the maxReach among these all options i have to choose one with most value
        int counter = reach;
        while (left<=counter && left<n) {
            reach = max(reach, nums[left]+left);
            left++;
        }
        jumps++;
        
    }
    return jumps;
    }
};