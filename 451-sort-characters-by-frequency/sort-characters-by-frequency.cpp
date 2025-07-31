class Solution {
public:
typedef pair<char,int> P;
struct lambda{
    bool operator()(P &p1,P& p2){
        return p1.second < p2.second;  //pq mai ulta
    }
};
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        priority_queue<P,vector<P>,lambda> pq;
        for(char ch : s){
            mp[ch]++;
        }
        string str="";
        for(auto it : mp){
            char ch=it.first;
            int x=it.second;
            pq.push({ch,x});
          
        }
        while(!pq.empty()){
                auto it =pq.top();
                 pq.pop();
                char ch=it.first;
                 int x=it.second;
                 str+=string(x,ch);
        }
        
           return str;
    }
};