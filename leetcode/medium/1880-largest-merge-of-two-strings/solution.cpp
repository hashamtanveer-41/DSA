class Solution {
public:
    string largestMerge(string word1, string word2) {
        string merge = "";
        int n = word1.size();
    int m = word2.size();
        int i =0, j=0;
    while (i<n || j<m) {
        if ((word1.substr(i) < word2.substr(j))) {
            merge.push_back(word2[j]);
            j++;
        }else {
            merge.push_back(word1[i]);
            i++;
        }
    }
    return merge;
    }
};