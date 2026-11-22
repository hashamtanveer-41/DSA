#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    int resilientSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return 0;

        int max_len = 1; // Any single-element subarray has remaining sum 0 % k == 0

        int i = 0;
        while (i < n) {
            // Normalize remainder to [0, k - 1]
            int r = ((nums[i] % k) + k) % k;

            // Find the maximal contiguous segment where all elements have remainder r
            int j = i;
            while (j < n && (((nums[j] % k) + k) % k) == r) {
                j++;
            }

            int segment_len = j - i;

            if (r == 0) {
                // Any length is valid when all elements are divisible by k
                max_len = max(max_len, segment_len);
            } else {
                // (m - 1) * r must be divisible by k => (m - 1) is a multiple of L
                int g = std::gcd(r, k);
                int L = k / g;

                // Largest m <= segment_len such that m == 1 (mod L)
                int best_m = 1 + ((segment_len - 1) / L) * L;
                max_len = max(max_len, best_m);
            }

            i = j;
        }

        return max_len;
    }
};