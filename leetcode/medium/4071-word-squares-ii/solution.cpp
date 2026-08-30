class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        int n = words.size();
    vector<vector<string>> res;
    unordered_map<string, vector<int>> mp;
    for (int i=0; i< n; i++) {
        string s = words[i];
        string key = {s[0], s[3]};
        mp[key].push_back(i);
    }
    for (int i =0;i< n; i++) {
        for (int j=0;j < n; j++) {
            if(i==j)continue;
            string left = {words[i][0], words[j][0]};
            string right = {words[i][3], words[j][3]};
            if (mp.find(left)!=mp.end()  && mp.find(right)!=mp.end()) {
                vector<int> leftIdx = mp[left];
                vector<int> rightIdx = mp[right];
                for (int l=0; l< leftIdx.size(); l++) {
                    for (int r = 0; r< rightIdx.size(); r++) {
                        if (leftIdx[l] != rightIdx[r] && rightIdx[r] !=i && rightIdx[r]!=j && leftIdx[l]!=i && leftIdx[l]!=j)
                                                        res.push_back({words[i], words[leftIdx[l]], words[rightIdx[r]], words[j]});

                    }
                }
            }
        }
    }
    sort(res.begin(), res.end());
    return res;
    }
};