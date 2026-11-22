class Solution {
public:
    string digitSum(string s, int k) {
       while(s.size()>k){
        string temp = "";
        for(int i=0; i<s.size(); i+=k){
            int sum = 0;
            for(int j=i; j<i+k && j<s.size();j++ ){
                int val  = s[j]-'0';
                sum+=val;
            }
            temp.append(to_string(sum));
        }
        s = temp;
    }
    return s;
    }
};