class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int first = 0, count = 1, second = 1;

        while (second < nums.size()){
            if( nums[first] == nums[second]){
                second++;
            }else{
                
                first++;
                nums[first] = nums[second];
                count++;
            }
        }  
        return count; 
    }
};