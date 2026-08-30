class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        int maxLight = *max_element(lights.begin(), lights.end());
    int n = arrivalTime.size();
    int res = 0;
    for (int i=0; i< n; i++) {
        int r = arrivalTime[i]%period;
        if (r>=maxLight)
            res = max(period-r, res);
    }
    return res;
    }
};