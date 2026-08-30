class Solution {
public:
    string predictPartyVictory(string senate) {
    queue<char>q;
    queue<char>power;
    int count =0;
    char res;
    for (char c:senate)q.push(c);
    while (q.size()!=1) {
        if (!power.empty() && power.front()!=q.front()) {
            q.pop();
            power.pop();
            continue;
        }
        char curr = q.front();
        q.pop();
        if (q.front()!=curr) {
            count=0;
            q.pop();
            q.push(curr);
        }else {
            if (count == q.size()) {
                res = q.front();
                break;
            }
            q.push(curr);
            power.push(curr);
            count++;
        }
    }
    if (res=='R' || q.front()=='R')return "Radiant";
    return "Dire";
}
};