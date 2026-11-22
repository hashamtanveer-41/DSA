class Solution {
public:
    long long minSumSquareDiff(vector<int>& v1, vector<int>& v2, int k1, int k2) 
    {
       int n = v1.size();
       vector<int> diffs(1e5+1, 0);
       for(int i=0; i<n; i++){
        int diff =abs(v1[i]-v2[i]);
        diffs[diff]++;
       }
    
       int k = k1+k2;
       for(int currDiff = 1e5; currDiff>0 && k>0; currDiff--){
        int operations = min(diffs[currDiff], k);
        diffs[currDiff] -= operations;
        diffs[currDiff-1] += operations;
        k -= operations; 
       }
       long long result = 0;
       for(long long i =1; i<=1e5; i++){
        result += (diffs[i]* (i*i));
       }
       return result;
    }
};