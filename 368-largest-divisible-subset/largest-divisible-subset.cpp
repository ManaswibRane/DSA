class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
          int n=nums.size();
         
          sort(nums.begin(),nums.end());
          vector<int> noOfEle(n,1);
          int maxNoIdx=0;
          int maxNoElements=1;
          vector<int> prevIndices(n,-1);
          for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && i!=j){
                   
                    if(noOfEle[i]<noOfEle[j]+1){
                            prevIndices[i]=j;
                    }
                    noOfEle[i]=max( noOfEle[i], noOfEle[j]+1);
                  
                }
                  if(noOfEle[i]>maxNoElements){
                        maxNoElements=noOfEle[i];
                        maxNoIdx=i;
                    }
            }
          }
          vector<int> res;
          while(maxNoIdx!=-1){
             res.push_back(nums[maxNoIdx]);
             maxNoIdx=prevIndices[maxNoIdx];
          }
          return res;
            
    }
};