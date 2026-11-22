class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        int smallest = 27;
        int largest = -1;
        int smallestCount = 0;
        int largestCount = 0;
        int i = 0;
        int count =0;
        for(char c: s){
            if(i!=n-1)
                if(s[i]>s[i+1])count++;
            smallest = min(smallest, c - 'a');
            largest = max(largest, c - 'a');
            i++;
        }
        for(char c: s){
            if((c-'a')==smallest)smallestCount++;
            if((c - 'a')==largest)largestCount++;
        }
        if(count==0)return 0;
        int res = 0;
        int first = s[0]- 'a';
        int last = s[n-1]-'a';
        if(n==2){
            if(first==largest)
                return -1;
            else return 0;
        }
        if(first>last){
            if(first==largest)
                if(last == smallest)
                    if(smallestCount == 1 && largestCount == 1)
                        return 3;
                    else 
                        return 2;
                else
                    return 2;
            else 

                return 2;
        }else if(first==last){
            if(first == largest || first == smallest)
                return 1;
            else 
                return 2;
        }else{
            if(first == smallest)
                return 1;
            else if (last == largest){
                return 1;
            }else
                return 2;
        }
        return -1;
    }
};