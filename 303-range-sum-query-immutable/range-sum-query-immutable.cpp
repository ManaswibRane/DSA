class NumArray {
public:
    vector<int> segtree;
    int n;
    void buildTree(vector<int>& nums,int l,int r,int i){
        if(l==r) {
            segtree[i]=nums[l];
            return;
        }
        int mid=(l+r)/2;
        buildTree(nums,l,mid,2*i+1);
        buildTree(nums,mid+1,r,2*i+2);
        segtree[i]=segtree[2*i+1]+segtree[2*i+2];
    }
    NumArray(vector<int>& nums) {
         n=nums.size();
        segtree.resize(4*n);
        buildTree(nums,0,n-1,0);
        for(int i=0;i<n;i++){
            cout<<segtree[i];
        }
    }
    
    int process(int l,int r,int st,int end,int i){
        if(l>end || r<st){
            return 0;
        }
         if (st >= l && end <= r) return segtree[i];  


        
        int mid=(st+end)/2;
        return process(l,r,st,mid,2*i+1)+process(l,r,mid+1,end,2*i+2);

       
    }
    int sumRange(int l, int r) {
        return process(l,r,0,n-1,0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */