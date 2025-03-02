class SmallestInfiniteSet {
public:
      int small;
    vector<bool> isPres;
    SmallestInfiniteSet() {
        small=1;
        isPres = vector<bool>(1001, true);
        
    }
    
    int popSmallest() {
        int r=small;
        isPres[small]=false;
        small++;
        while(isPres[small]==false && small<1000) small++;
        return r;
    }
    
    void addBack(int num) {
        isPres[num]=true;
        if(num<small){
            small=num;
        }

    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */