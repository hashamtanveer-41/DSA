class Solution {
public:
int count1 = 0;
  void findTotalNumbers(vector<int> & digits, int s, int n, int i, int even, vector<int> isEven) {
    if (s==3) {
        count1 += even * 2;
        if (digits[i-3]%2==0) {
            even--;
            isEven[i-3]=-1;
        }
        s--;
    }
    if (i==n)return;
    // Leave it
    findTotalNumbers(digits, s, n, i+1,even, isEven);
    // Take it
    if (digits[i]%2==0 && isEven[i]==-1) {
        even++;
        isEven[i]=1;
    }
    findTotalNumbers(digits, s+1, n, i+1, even, isEven);
   
}
int totalNumbers(vector<int>& digits) {
int freq[10] = {0};
        for (int d : digits) {
            freq[d]++;
        }

        int res = 0;
        for (int i = 100; i < 1000; i += 2) {
            int x = i / 100;
            int y = (i / 10) % 10;
            int z = i % 10;

            // Decrement all three unconditionally
            freq[x]--;
            freq[y]--;
            freq[z]--;

            // Valid if none went into deficit
            if (freq[x] >= 0 && freq[y] >= 0 && freq[z] >= 0) {
                res++;
            }

            // Restore all three unconditionally
            freq[x]++;
            freq[y]++;
            freq[z]++;
        }

return res;
}
};