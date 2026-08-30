class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        bool a = false;
        if(s.length()%2!=0)return false;
        for(int i=0; i< s.size(); i++){
            if( s[i]=='('||s[i]=='['||s[i]=='{' ){
                st.push(s[i]);
                continue;
            }
            if(st.empty()) return false;
            if(s[i]==')'&& st.top()=='('){
                st.pop();
                continue;
            }
            if(s[i]==']'&& st.top()=='['){
                st.pop();
                continue;
            }
            if(s[i]=='}'&& st.top()=='{'){
                st.pop();
                continue;
            }
            a = true;

        }
        
        if((!(st.empty()) || a))return false;
        return true;
    }
};