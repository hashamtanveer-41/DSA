class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
    int write = 0;
    int count = 2;
    int distinct= nums[0];
    for (int i=0; i<n ; i++) {
        if (nums[i]!=distinct) {
            count = 1;
            distinct = nums[i];
            nums[write] = nums[i];
            write++;
        }else {
            // repitition
            if (count>0) {
                nums[write] = nums[i];
                write++;
            }
            count--;
        }
    }
    return write;
    }
};