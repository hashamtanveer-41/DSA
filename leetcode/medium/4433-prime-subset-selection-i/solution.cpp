class Solution {
public:
    bool isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            return false; 
        }
    }
    return true; 
}
    vector<int> maxPrimes(int n, int s) {
        vector<int>  res;
    
        for(int i=1; i<=n; i++){
            if(isPrime(i)){
                res.push_back(i);
            }
        }
        int left = 0, right = 0;
        int ns = res.size();
        int startRes = 0;
        int result = 0;
        int sum = 0;
        while(right<ns){
            sum+=res[right];
            while(sum>s){
                sum-=res[left];
                    left++;
            }
            int windLen = right - left + 1;
            if(windLen>=result){
                startRes = left;
                result = windLen;
            }
            right++;
        }
        vector<int> ans;
        for(int i=startRes; i<(startRes+result); i++){
            ans.push_back(res[i]);
        }
        return ans;
    }
};