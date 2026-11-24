class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int res = 1;
        for(int i=0; i<n; i++){
            long long currentGCD = nums[i]; 
            long long currentLCM = nums[i]; 
            long long currentPROD = nums[i];    
            for(int j=i+1; j<n; j++){
                currentGCD = gcd(currentGCD, nums[j])*1LL;
                currentLCM = lcm(currentLCM, nums[j])*1LL;
                currentPROD = currentPROD * nums[j]*1LL;
                if(currentPROD >=( 2520 *currentLCM*currentGCD*1LL))
                    break;
                if(currentPROD == (currentLCM*currentGCD*1LL)){
                    res = max(res, j-i+1);
                }
            }
        }
        return res;
    }
};