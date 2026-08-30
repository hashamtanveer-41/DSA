class Solution {
public:
    int maximumSum(vector<int>& a) {
        int n = a.size();
        int power=INT_MIN, nopower = a[0], res = a[0];
        for(int i =1; i< n; i++){
            int v1= a[i];
            int v2= nopower+a[i];
            int v3;
            if(power==INT_MIN){
                v3 = a[i];
            }else{
                v3 = power+a[i];
            }
            
            int v4 = nopower;
            nopower = max(v1, v2);
            power = max(v3, v4);
            res = max(res, max(power, nopower));
        }
        return res;
    }   
};