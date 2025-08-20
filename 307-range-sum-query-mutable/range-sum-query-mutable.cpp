class NumArray {
public:
vector<int> segTree;
vector<int> lazy;
int n;
void BuildSegTree(vector<int>& nums,int l,int r,int i){
    if(l==r){
            segTree[i]=nums[l];
            return;
    }
    int mid=(l+r)/2;

    BuildSegTree(nums,l,mid,2*i+1);
    BuildSegTree(nums,mid+1,r,2*i+2);
    segTree[i]=segTree[2*i+1]+segTree[2*i+2];
}
    NumArray(vector<int>& nums) {
         n=nums.size();
        segTree.resize(n*4);
       
        BuildSegTree(nums,0,n-1,0);
    }
    void processUpdate(int idx,int val,int st,int end,int i){
        if(st==idx && end==idx){
            segTree[i]=val;
            return;
        }
        int mid=(st+end)/2;
        if(mid>=idx){
            processUpdate(idx,val,st,mid,i*2+1);

        }
        else{
             processUpdate(idx,val,mid+1,end,i*2+2);
            
        }
        segTree[i]=segTree[2*i+1]+segTree[2*i+2];
        
    }
    void update(int index, int val) {
        processUpdate(index,val,0,n-1,0);
    }
    int sum(int l,int r,int st,int end,int i){
        if(l>end || r<st){
            return 0;
        }
        if(l<=st && r>=end){
            return segTree[i];
        } 
        int mid=(st+end)/2;
        return sum(l,r,st,mid,2*i+1)+sum(l,r,mid+1,end,2*i+2);

    }
    int sumRange(int l, int r) {
        cout<<segTree[2];
        return sum(l,r,0,n-1,0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */