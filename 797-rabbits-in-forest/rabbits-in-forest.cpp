class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> mp;
        for(int & x: answers){
            mp[x]++;
        }
        int ans=0;
        for(auto & it : mp){
            int groupSize=it.first+1;
            int noOfRabbits=it.second;
            int groups=ceil((double)noOfRabbits/groupSize);
            ans+=groupSize*groups;
        }
        return ans;
    }
};