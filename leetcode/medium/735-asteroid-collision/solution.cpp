class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
       int n = asteroids.size();
    stack<int> st;
   for (int i=0; i<n; i++) {
        int currNum = asteroids[i];
        bool alive = true;
        while (!st.empty() && st.top() > 0 && currNum < 0) {
            if (st.top()<abs(currNum))st.pop();
            else if (st.top()==abs(currNum)) {
                st.pop(); alive = false;break;
            }
            else if (st.top()>abs(currNum)){alive = false; break;}
        }
        if (alive)st.push(currNum);
    }
    vector<int> res;
    while (!st.empty()) {
        res.push_back(st.top()); st.pop();
    }
    reverse(res.begin(), res.end());
    return res;
    }
};