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
            if(temp.size() >= 3){
            bool is = true;
            
                for(int i=1; i<temp.size()-1; i++){
                    if((temp[i]-temp[i-1]) != (temp[i+1] - temp[i]))
                        is = false;
                }
            if(is)count++;}
        }
        return count;
    }
};