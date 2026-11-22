class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string res;
        if(sum>(9*num))return res;
        int k = sum/9, r = sum % 9;
        res.reserve(num);
        res.append(k, '9');
        num -= k;
        if(r){
            res += '0'+r;num--;
        }
        res.append(num, '0');
        return res;
    }
};