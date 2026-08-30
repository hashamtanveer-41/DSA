class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> s;
        for(int val: nums)s.insert(val);
        int i=1;
        while(true){
            if(s.count(i*k)==0)return i*k;
            i++;
        }
    }
};