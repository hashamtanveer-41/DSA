class Solution {
public:
    int search(vector<int>& nums, int target) {
    int last = nums.size()-1;
    int first =0;
    int mid = first+((last-first)/2);

    while(nums[mid] != target){
        if(nums[mid] == target) return mid;
        
        if(nums[last] == target ) return last;

        if( nums[mid] > target){
            last = mid;
            mid = first+((last-first)/2);
        }else{
            first = mid;
            mid = first+((last-first)/2);
        }

        if (mid == first && nums[mid] != target)return -1;
    }
    return mid;
}
};