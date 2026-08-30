class Solution {
public:

    string reorganizeString(string s) {
    int n = s.size();
    unordered_map<char, int> p;
    priority_queue<pair<int, char>> pq;
    int seat = 0;
    string res ="";
    for (int i =0; i<n; i++)p[s[i]]++;
    for (auto it=p.begin(); it!=p.end(); ++it) {
        pq.push({it->second, it->first});
    }
    while (!pq.empty()) {
        pair<int, char> mp = pq.top();
        pq.pop();
        if (seat==0 || res[seat-1]!=mp.second) {
            res.push_back(mp.second);
            seat++;
            mp.first--;
            if (mp.first>0)pq.push(mp);
        }else {
            if (pq.empty()) return "";
            pair<int, char> mp1 = pq.top();
            pq.pop();
            res.push_back(mp1.second);
            seat++;
            mp1.first--;
            if (mp1.first>0)pq.push(mp1);
            pq.push(mp);
        }
    }
    return res;
}
};