class Solution {
public:
    bool correctNum(vector<int> have, vector<int> need){
    for(int i = 0; i<256; i++){
        if(have[i]<need[i]){
            return false;
        }
    }

    return true;
}
string minWindow(string s, string t) {
    int high = 0, low = 0, start = 0, res = INT_MAX, n = s.length();

    vector<int> need(256);
    for(int i = 0; i<t.length(); i++){
        need[t[i]]++;
    }
    vector<int> have(256);

    for( high = 0; high<n; high++){
        have[s[high]]++;
        while(correctNum(have, need)){
            int len = high -low +1;
            if(res>len){
                res = len;
                start = low;
            }
            have[s[low]]--;
            low++;
        }
    }
    if (low == 0) return "";
    return s.substr(start, res);
}

};