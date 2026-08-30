class Solution {
public:
   int numOfPlanks(vector<int>& planks,int n, int guess) {
    int left = 0, right = n-1, res = 0;
    bool is = false;
    while (left<=right) {
        if (planks[left]==guess) {
            res++;
            if (left == right)break;
            left++;
            is = true;
        }
        if (planks[right]==guess) {
            res++;
            right--;
            is = true;
        }
        if (is) {
            is = false;
            continue;
        }
        int sum;
        if (left == right) sum = planks[left];
        else sum = planks[left] + planks[right];
        if (sum == guess) {
            res++;
            left++;
            right--;
        }
        else if (sum<guess) {
            left++;
        }else {
            right--;
        }
    }
    return res;
}
int maximumWidth(vector<int>& planks) {
    sort(planks.begin(), planks.end());
    int n = planks.size();
    unordered_map<int, int> freq;
    for (int num : planks) {
        freq[num]++;
    }
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j<n; j++) {
            freq[planks[i]+planks[j]]++;
        }
    }
    int res = 0;
    for (auto& pair : freq) {
        int guess = pair.first;
        int theoretical_max = pair.second;
        if (theoretical_max>res) {
            int currPlanks = numOfPlanks(planks, n, guess);
            res = max(currPlanks, res);
        }
    }
    return res;
}
};