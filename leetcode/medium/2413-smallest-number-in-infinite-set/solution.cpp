class SmallestInfiniteSet {
public:
     vector<bool> ans;
    int i;
    SmallestInfiniteSet() {
       ans = vector<bool>(1001, true);
        i = 1;
    }

    int popSmallest() {
        while (!ans[i]) {
            i++;
        }
        ans[i] = false;
        return i++;
    }

    void addBack(int num) {
        if (!ans[num]) {
            ans[num] = true;
            if (num<i)i = num;
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */