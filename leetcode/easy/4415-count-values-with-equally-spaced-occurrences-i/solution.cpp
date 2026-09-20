class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int> > mp;
        for(int i=0; i<n; i++){
            mp[nums[i]].push_back(i);
        }
        int count = 0;
        for(auto& pa: mp){
            vector<int> temp = pa.second;
            if(temp.size() == 3 && ((temp[1]-temp[0] )== (temp[2]-temp[1])))
                count++;
        }
        return count;
    }
};