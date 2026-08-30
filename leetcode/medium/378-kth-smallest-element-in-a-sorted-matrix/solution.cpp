class Solution {
public:
    int fun (vector<vector<int>> a, int n, int m, int guess )
{
    int row = n-1, col = 0, count = 0;
    while (row>=0 && col<m)
    {
        if (a[row][col]<=guess)
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
    int kthSmallest(vector<vector<int>>& a, int k) {
        int n= a.size();
        int m = a[0].size();
        int low = a[0][0], high  = a[n-1][m-1], res = -1;
        while (low<=high)
        {
            int guess = (high+low)/2;
            int ans = fun(a, n, m ,guess);

            if(ans<k)low = guess+1;
            else{
                res = guess;
                high = guess-1;
            }
        }
    return res;
}
};