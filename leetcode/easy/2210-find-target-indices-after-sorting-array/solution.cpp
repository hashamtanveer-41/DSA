class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int n = nums.size();
        int smaller = 0, equal = 0;
        for(int num: nums){
            if(num<target)smaller++;
            if(num==target)equal++;
        }
        vector<int> res;
        for(int i=0; i<equal; i++){
                res.push_back(smaller+i);
        }
        return res;
    }
};