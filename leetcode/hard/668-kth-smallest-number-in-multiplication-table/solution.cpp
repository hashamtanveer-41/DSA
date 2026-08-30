class Solution {
public:
int fun1 (int m, int n, int guess )
{
    int row = m-1, col = 0, count = 0;
    while (row>=0 && col<n)
    {
        if ((row+1)*(col+1)<=guess)
        {
            count += row+1;
            col++;
        }else
        {
            row--;
        }
    }
    return count;
}
int findKthNumber(int m, int n, int k)
{
    int low =1, high  = m*n, res = -1;
    while (low<=high)
    {
        int guess = (high+low)/2;
        int ans = fun1(m, n ,guess);
        if(ans<k)low = guess+1;
        else{
            res = guess;
            high = guess-1;
        }
    }
    return res;
}
};