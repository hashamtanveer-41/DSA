class Solution {
public:
    bool canTransform(vector<int>& source, vector<int>& target) {
        long long  one =0;
        for(int num : target)
            one += num;
            long long two = 0;
            for(int num : source)
            two += num;
    return one == two;
    }
};