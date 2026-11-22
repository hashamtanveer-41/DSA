class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int res =0;
        for(int val1: arr1){
            int diff = 1e8;
            for(int val2: arr2){
                int ab = abs(val1-val2);
                diff = min(ab, diff);
            }
            if(diff>d)
            res++;
        }
        return res;
    }
};