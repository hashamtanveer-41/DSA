class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();

    int temp =nums[0];
    unordered_set<int>set;
    int i;
    set.insert(nums[0]);
    for (i =1; i< n; i++) {
         if (nums[i]==(nums[i-1]+1)) {
             temp += nums[i];
         }else {
             break;
         }
        set.insert(nums[i]);
    }
    while (i<n){set.insert(nums[i]);i++;}
    while (true) {
        if (set.count(temp)==0)return temp;
        temp++;
    }
    }
};