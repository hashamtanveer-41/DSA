#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    int resilientSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return 0;
        int max_len = 1; 
        int i = 0;
        while (i < n) {
            int r = ((nums[i] % k) + k) % k;

            int j = i;
            while (j < n && (((nums[j] % k) + k) % k) == r) {
                j++;
            }

            int segment_len = j - i;

            if (r == 0) {
                max_len = max(max_len, segment_len);
            } else {
                int g = std::gcd(r, k);
                int L = k / g;
                int best_m = 1 + ((segment_len - 1) / L) * L;
                max_len = max(max_len, best_m);
            }

            i = j;
        }

        return max_len;
    }
};