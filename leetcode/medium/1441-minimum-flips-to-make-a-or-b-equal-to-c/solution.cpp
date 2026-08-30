class Solution {
public:
    int minFlips(int a, int b, int c) {
    
    int res = 0;
    for (int i =0; i<32; i++) {
        int bitA = (a>>i) & 1;
        int bitB = (b>>i) & 1;
        int bitC = (c>>i) & 1;
        if ((bitA | bitB) != bitC) {
            // We need to flip
            if (bitC==0) {
                if (bitA==1 && bitB ==1)res +=2;
                else res++;
            }else {
                res++;
            }
        }
    }
    return res;
    }
};