class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
    vector<int> pos;
    vector<int> neg;
    int originalS= nums.size();
    int i =0, j=0, k = 0;

    for(int l = 0; l< originalS ; l++){
        if(nums[l]< 0){
            neg.push_back(nums[l]);
        }else{
            pos.push_back(nums[l]);
        }
    }

    if(neg.empty()){
        // Square the array
        for(int f= 0; f< pos.size(); f++){
            pos[f] *= pos[f];
        }
        return pos;
    }

    if(pos.empty()){
        // Square the array
        for(int f= 0; f< neg.size(); f++){
            neg[f] *= neg[f];
        }
        reverse(neg.begin(), neg.end());
        return neg;
    }


    for(int f= 0; f< pos.size(); f++){
        pos[f] *= pos[f];
    }

    for(int f= 0; f< neg.size(); f++){
        neg[f] *= neg[f];
    }
    reverse(neg.begin(), neg.end());

    int n = neg.size(), m = pos.size();
    while(i< n && j < m){
        if(neg[i]> pos[j]){
            nums[k] = pos[j];
            j++;
            k++;
        }else{
            nums[k] = neg[i];
            i++;
            k++;
        }
    }

    if(i< n){
        while(i< n){
            nums[k] =neg[i];
            i++;
            k++;
        }
        return nums;
    }

    if(j< m){
        while(j< m){
            nums[k] =pos[j];
            j++;
            k++;
        }
        return nums;
    }
    return nums;

}

};