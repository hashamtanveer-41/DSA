class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
    int zeros = 0, ones =0;
for (int std:students) std==0?zeros++:ones++;
int ptr = 0, m = sandwiches.size();
while (ptr<m) {
    if (sandwiches[ptr]==1 && ones>0)
        ones--;
    else if (sandwiches[ptr]==0 && zeros>0)
        zeros--;
    else if ((sandwiches[ptr]==1 && ones==0) || sandwiches[ptr]==0 && zeros==0 )
        break;
    ptr++;
}
if (zeros>0)return zeros;
if (ones>0)return ones;
return 0;
}
};