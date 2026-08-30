class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int n = drones.size();
        pair<int, int> res={INT_MAX, INT_MAX};
        for(int i=n-1; i>=0; i-- ){
            int x = drones[i][0];
            int y = drones[i][1];
            int range = drones[i][2];
            int dist = abs(x-target[0])+abs(y-target[1]);
            if(dist<=range){
                if (res.first>=dist)
                    res = {dist, i};
            }
        }
        if(res.first==INT_MAX)return -1;
        return res.second;
    }
};