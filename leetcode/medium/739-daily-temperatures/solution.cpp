class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
       
    //  code here
     int n = arr.size();
    vector<int> res1(n);
    res1[n-1] = 0;
    stack<int> st;
    stack<int> st1;
    st.push(arr[n-1]);
    st1.push(n-1);
    for(int i=n-2; i>=0; i--){
        while(!st.empty() && st.top()<=arr[i]){
            st.pop();
            st1.pop();
        }
        if(st.empty()){
            res1[i]=0;
        }else{
            res1[i]=st1.top()-i;
        }
        st.push(arr[i]);
        st1.push(i);
    }
    return res1;
    }
    
};