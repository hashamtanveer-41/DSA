class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxInc=0, maxDec=0,currInc=0, currDec=0;
        int currMax=0, currMin=51;
        for(int num: nums){
            if(num<currMin){
                currDec++;
                currMin = num;
            }else{
                maxDec = max(maxDec, currDec);
                currMin = num;
                currDec =1;
            }
        }
        maxDec = max(maxDec, currDec);
         for(int num: nums){
            if(num>currMax){
                currInc++;
                currMax = num;
            }else{
                maxInc = max(maxInc, currInc);
                currMax = num;
                currInc =1;
            }
        }
        maxInc = max(maxInc, currInc);
        return max(maxInc ,maxDec);
    }
};