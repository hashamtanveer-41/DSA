class Solution {
public:
    vector<int> findAnagrams(string s2, string s1) {
    int requiredCount = s1.size();
    int n = s2.size(), k = requiredCount;
    int left =0, right = 0;
    unordered_map<char, int> required;
    for (char c:s1)required[c]++;
    vector<int>res;
    while (right<n) {
        char temp = s2[right];
        if (required.find(temp)!=required.end()) {
            if (required[temp]>0)requiredCount--;
            required[temp]--;
        }

        int windowSize = right-left+1;
        if (windowSize==k) {
            if (requiredCount==0)res.push_back(left);
            if (required.find(s2[left])!=required.end()) {
                required[s2[left]]++;
                if (required[s2[left]]>0)requiredCount++;
            }
            left++;
        }
        right++;
    }
    return res;
}

};