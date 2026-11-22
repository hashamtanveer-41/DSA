class Solution {
public:
    int calculateScore(int a, int b) {
        int count1 = 0;
        int count2 = 0;
        for(int i=0; i<8; i++){
            if((a>>i & 1)==1)
                count1++;    
            if((b>>i & 1)==1)
                            count2++;       
        }
     return count1>=count2?count1*count2 : count2/count1;
    }
   
};