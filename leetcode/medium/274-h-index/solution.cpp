class Solution {
public:
    int hIndex(vector<int>& citations) {
     int n = citations.size();
        vector<int> buckets(n+1, 0);
        for(int i=0; i<n; i++){
            if(citations[i]>=n)buckets[n]++;
            else buckets[citations[i]]++;
        }
        int count = 0;
        for(int i=n; i>=0; i--){
            count += buckets[i];
            if(count>=i)return i;
        }
        return 0;
    // 6 ,5, 3, 1, 0
    // 1, 2, 3, 4, 5

    // 0
    // 1

    // 2 0 0 
    // 1 2 3

    // 15 11
    // 1  2
    }
};