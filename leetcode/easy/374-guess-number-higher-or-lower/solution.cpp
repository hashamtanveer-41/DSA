/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int left = 1, right = n;
        while(left<right){
            int val = left+ (right-left)/2;
            int res = guess(val);
            if(res==0)return val;
            else if( res==1){
                left =val+1;
            }else{
                right = val-1;
            }
        }
        return left;
    }
};