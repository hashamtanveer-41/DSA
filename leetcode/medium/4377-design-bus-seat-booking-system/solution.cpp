class BusBooking {
public:
    unordered_map<string, int> mp;
    int totalTime = 0;
    BusBooking(int n) {
        
    }
    
    void toggle(string seat) {
        if(mp.find(seat)!=mp.end()){
            int cost = mp[seat];
            totalTime -= cost;
            mp.erase(seat);
        }else{
        char c = seat[0];
        int row = 0;
        int cost = 0;
        for(int i=1; i<seat.size(); i++){
            row = row* 10 + (seat[i] - '0');
        }
        if(c=='A'||c=='D'){
            string check = "";
            if(c=='A')
            check+='B';
            if(c=='D')
            check+='C';
            check.append(to_string(row));
            if(mp.find(check)!=mp.end()){
                cost +=3;
            }else{
                cost+=1;
            }
        }else{
            cost += 1;
        }
        totalTime +=cost;
        mp[seat] = cost;
        }
    }
    
    int getTotalTime() {
        return totalTime;
    }
    
    int getMinTime() {
        return mp.size();
    }
};

/**
 * Your BusBooking object will be instantiated and called as such:
 * BusBooking* obj = new BusBooking(n);
 * obj->toggle(seat);
 * int param_2 = obj->getTotalTime();
 * int param_3 = obj->getMinTime();
 */